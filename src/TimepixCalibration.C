#include <iostream>
#include <cstdio>
#include <cmath>

#include "TCanvas.h"
#include "TH2F.h"

#include "TimepixCalibration.h"

//-----------------------------------------------------------------------------
// Implementation file for class : TimepixCalibration
//
// Added run number info to class for CLICpix calibration - S.Green, 2015-9-18
//
//-----------------------------------------------------------------------------
 
TimepixCalibration::TimepixCalibration(const std::string chip, const int method, const std::string runNumber) :
    m_method(method),
    m_RunNumber(runNumber)
 {
  
  if (method < 0 || method > 2) {
    std::cerr << "TimepixCalibration" << std::endl;
    std::cerr << "    Unknown calibration correction (" 
              << method << ") method requested\n";
    std::cerr << "    No correction will be applied.\n";
    m_method = 0;
  }

  pixGain.clear();
  pixToT0.clear();
  pixT.clear();
  pixGain.clear();
  pixToT0.clear();
  pixT.clear();
  
  // Set some reasonable default values 
  // for the average fit parameters.
  avgGain = 0.18597;
  avgToT0 = 28.5677;
  avgT = 326.111;
  avgC = 17.9182;

  bool foundChip = false;
  if (chip == "D04-W0015") {
    // Xavi fit
    // avgGain = 0.207;
    // avgToT0 = 30.63; 
    // avgC = 134.8;
    // avgT = 30.16;

    // Fit without gaussian convolution
    // avgGain = 0.19998;
    // avgToT0 = 25.480;
    // avgC = 211.575;
    // avgT = 24.204;

    // Fit from timepix paper with THL=420
    avgGain = 0.194;
    avgToT0 = 34.4;
    avgC = 195;
    avgT = 15.3;
    
    // Fit with gaussian convolution
    // avgGain = 0.20280;
    // avgToT0 = 23.999; 
    // avgC = 149.462;
    // avgT = 27.076;

    // Ana Barbara 2010 thin data fitting function
    // avgGain = 0.189469;
    // avgToT0 = 32.8982; 
    // avgC = 179.732;
    // avgT = 21.8025;
    
    foundChip = true;
  } else if (chip == "G08-W0087") {
    // Fit for THL 334 (Testbeam: 360) (C.Vazquez)
    avgGain = 0.1681;
    avgToT0 = 42.74;
    avgC = 288.6;
    avgT = 15.87;
    foundChip = true;
  } else if (chip == "J03-W0089") {
    // Fit for THL 403 (Testbeam: 410) (C.Vazquez)
    avgGain = 0.1694;
    avgToT0 = 48.62;
    avgC = 415.7;
    avgT = 11.28;
    foundChip = true;
  } else if (chip == "H03-W0092") {
    // Fit for THL 393 (Testbeam: 390) (C.Vazquez)
    avgGain = 0.2044;
    avgToT0 = 48.6;
    avgC = 322.2;
    avgT = 14.66;
    foundChip = true;
  } else if (chip == "D09-W0108") {
    // Fit for THL 373 (Testbeam: 376) (C.Vazquez)
    avgGain = 0.1919;
    avgToT0 = 46.27;
    avgC = 305.1;
    avgT = 13.72;
    foundChip = true;
  } else if (chip == "F11-W0108") {
    // Fit for THL 297 (Testbeam: 300) (C.Vazquez)
    avgGain = 0.1609;
    avgToT0 = 43.01;
    avgC = 306.4;
    avgT = 11.46;
    foundChip = true;
  } else if (chip == "J08-W0087") {
    // Fit for THL 354, fitted (Testbeam: 354) (C.Vazquez)
    avgGain = 0.1737;
    avgToT0 = 33.64;
    avgC = 223.45;
    avgT = 22.87;
    foundChip = true;
  } else if (chip == "C10-W0108") {
    // Fit for THL 414 (Testbeam: 355) (C.Vazquez)
    avgGain = 0.1743;
    avgToT0 = 41.42;
    avgC = 255;
    avgT = 14.8;
    foundChip = true;
  } else if (chip == "C09-W0108") {
    // Fit for THL 377 (Testbeam: 382) (C.Vazquez)
    avgGain = 0.186;
    avgToT0 = 44.3;
    avgC = 285.9;
    avgT = 13.91;
    foundChip = true;
  }

//==========CLICpix calibration option - S.Green
    else if (chip == "CLi-CPix")
    {
        avgGain = 0.08;
        avgToT0 = 2.5;
        avgC = 30;
        avgT = 7.5;
        foundChip = true;
    }
//==========
 
  if (m_method == 2 && chip != "CLi-CPix") {
    const std::string filename = "calib/" + chip + ".txt";
    if (!readdata(filename)) {
      std::cerr << "TimepixCalibration" << std::endl;
      std::cerr << "    Pixel-by-pixel calibration file " 
                << filename << " not found. Error!\n";
      if (foundChip) {
        std::cerr << "    Using average correction instead.\n";
        m_method = 1;
      } else {
        std::cerr << "    No correction will be applied.\n";
        m_method = 0;
      }
    }
  }

//==========CLICpix calibration option - S.Green
    else if (chip == "CLi-CPix")
    {
        const int numRows = 64;
        const int numColumns = 64;

        const std::string calibrationInfoFile = "/afs/cern.ch/eng/clic/work/clicpix/Calibration/CalibrationRunList.txt";
        std::cout << "==== TimepixCalibration ==== CLi-CPix Calibration " << std::endl;
        std::cout << "calibrationInfoFile : " << calibrationInfoFile << std::endl;
        std::cout << "Run Number : " << m_RunNumber << std::endl;

        std::ifstream inFile;
        inFile.open(calibrationInfoFile.c_str());

        std::string runNumber;
        std::string fileAParam;
        std::string fileBParam;
        std::string fileCParam;
        std::string fileTParam;

        while (inFile >> runNumber >> fileAParam >> fileBParam >> fileCParam >> fileTParam) 
        {
            if (runNumber == m_RunNumber)
            {
                std::cout << "fileAParam : " << fileAParam << std::endl;
                std::cout << "fileBParam : " << fileBParam << std::endl;
                std::cout << "fileCParam : " << fileCParam << std::endl;
                std::cout << "fileTParam : " << fileTParam << std::endl;

                // Clear surrogate function patameters
                pixGain.clear(); // Gain is A
                pixToT0.clear(); // ToT0 is B
                pixT.clear();    // T
                pixC.clear();    // C
                pixGain.resize(numRows);
                pixToT0.resize(numRows);
                pixT.resize(numRows);
                pixC.resize(numRows);
                for (int i = numRows; i--;) 
                {
                    pixGain[i].resize(numColumns);
                    pixToT0[i].resize(numColumns);
                    pixT[i].resize(numColumns);
                    pixC[i].resize(numColumns);
                    for (int j = numColumns; j--;) 
                    {
                        // Initialise with average fit parameters.
                        pixGain[i][j] = avgGain;
                        pixToT0[i][j] = avgToT0;
                        pixT[i][j] = avgT;
                        pixC[i][j] = avgC;
                    }
                }

                std::ifstream inFileA;
                inFileA.open(fileAParam.c_str());
                int counter(1);
                int column(0);
                int row(0);
                float param;
                while (inFileA >> row >> column >> param)
                {
                    pixGain[row][column] = param;
                    std::cout << "For param A, column " << column << ", row " << row << ", : " << param << std::endl;
                    counter++;
                    if (counter >= numColumns*numRows)
                        break;
                }
                inFileA.close();

                std::ifstream inFileB;
                inFileB.open(fileBParam.c_str());
                counter = 0;
                while (inFileB >> row >> column >> param)
                {
                    pixToT0[row][column] = param;
                    std::cout << "For param B, column " << column << ", row " << row << ", : " << param << std::endl;
                    counter++;
                    if (counter >= numColumns*numRows)
                        break;
                }
                inFileB.close();

                std::ifstream inFileC;
                inFileC.open(fileCParam.c_str());
                counter = 0;

                TH2F *pTH2F = new TH2F("Name","Title",64,0,64,64,0,64);
                while (inFileC >> row >> column >> param)
                {
                    pixC[row][column] = param;
                    std::cout << "For param C, column " << column << ", row " << row << ", : " << param << std::endl;

                    pTH2F->Fill(column,row,param);
                    counter++;
                    if (counter >= numColumns*numRows)
                        break;
                }
                TCanvas *pTCanvas = new TCanvas();
                pTCanvas->cd();
                pTH2F->Draw("COLZ");
                pTCanvas->SaveAs("check.C");
                inFileC.close();

                std::ifstream inFileT;
                inFileT.open(fileTParam.c_str());
                counter = 0;
                while (inFileT >> row >> column >> param)
                {
                    pixT[row][column] = param;
                    std::cout << "For param T, column " << column << ", row " << row << ", : " << param << std::endl;
                    counter++;
                    if (counter >= numColumns*numRows)
                        break;
                }
                inFileT.close();
            }
	}
        inFile.close();
    }
//==========

  if (m_method == 1 && !foundChip) {
    m_method = 0;
    std::cerr << "TimepixCalibration" << std::endl;
    std::cerr << "    Fit parameters for chip " 
              << chip << " not available.\n";
    std::cerr << "    No correction will be applied.\n";
  }
  
} 

double
TimepixCalibration::charge(const int row, const int col, const double tot) {

  if (m_method == 0) return tot;
  double result = 0.;
  if (m_method == 1) {
    result = inversesurrogate(tot, avgGain, avgToT0, avgC, avgT);
  } else if (m_method == 2) {
    result = inversesurrogate(tot, pixGain[row][col], pixToT0[row][col], 
                                   pixC[row][col], pixT[row][col]);
  }
  return result / 3.75467;

}

bool
TimepixCalibration::readdata(const std::string filename) {

  FILE* data = fopen(filename.c_str(), "r");
  if (!data) {
    fclose(data);
    return false;
  }
  
  // Setup the fit parameter matrices.
  pixGain.clear();
  pixToT0.clear();
  pixT.clear();
  pixC.clear();
  pixGain.resize(nRows);
  pixToT0.resize(nRows);
  pixT.resize(nRows);
  pixC.resize(nRows);
  for (int i = nRows; i--;) {
    pixGain[i].resize(nCols);
    pixToT0[i].resize(nCols);
    pixT[i].resize(nCols);
    pixC[i].resize(nCols);
    for (int j = nCols; j--;) {
      // Initialise with average fit parameters.
      pixGain[i][j] = avgGain;
      pixToT0[i][j] = avgToT0;
      pixT[i][j] = avgT;
      pixC[i][j] = avgC;
    }
  }
  
  // Read in JC calibrations
  char myline[200];
  int nPoints = 0;
  while (fgets(myline, 200, data)) {
    int rowcol[2] = {0, 0};
    float tempval[17];
    for (int i = 0; i < 15; ++i) tempval[i] = 0.;
    // Read fit parameters with convoluted gaussian (fit 3)   
    sscanf(myline, "%d %d %*f %*f %*f %*f %*f %*f %*f %*f %*f %f %f %f %f %f",
           &rowcol[0], &rowcol[1], &tempval[0], &tempval[1], &tempval[2], &tempval[3], &tempval[4]);
    // Read fit parameters without convoluted gaussian (fit 2)
    // sscanf(myline, "%d %d %*f %*f %f %f %f %f %f",
    //        &rowcol[0], &rowcol[1], &tempval[0], &tempval[1], &tempval[2], &tempval[3], &tempval[4]);
    if (rowcol[1] >= 0 && rowcol[1] < nRows &&
        rowcol[0] >= 0 && rowcol[0] < nCols) {
      pixGain[rowcol[1]][rowcol[0]] = tempval[0];
      pixToT0[rowcol[1]][rowcol[0]] = tempval[1];
      pixT[rowcol[1]][rowcol[0]] = tempval[3];
      pixC[rowcol[1]][rowcol[0]] = tempval[2];
      ++nPoints;
    }
  }
  fclose(data);
  std::cout << "TimepixCalibration" << std::endl;
  std::cout << "    read " << nPoints
            << " from JC surrogate fit file " << filename << "\n";
  return true;

}

double 
TimepixCalibration::inversesurrogate(const double x, 
                                     const double gain, const double tot0,
                                     const double c, const double t) {

  double result = 0.;
  const double sqrtterm = pow(tot0 + gain * t - x, 2) + 4 * gain * c;
  if (sqrtterm > 0) {
    result = ((t * gain + x - tot0) + sqrt(sqrtterm)) / (2 * gain);
  }

  // ??
  // const double clockcorrection = 40. / 48.;
  // result *= clockcorrection;
  return result;

}


