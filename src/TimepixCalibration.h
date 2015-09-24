#ifndef TIMEPIXCALIBRATION_H 
#define TIMEPIXCALIBRATION_H 1

#include <string>
#include <fstream>

#include "TestBeamObject.h"

/** @class TimepixCalibration TimepixCalibration.h
 *  
 *
 *  @author Heinrich Schindler
 *  @date   2011-12-13
 *
 *  @author Steven Green
 *  @date   2015-9-18
 *  @details - Added run number parameter for CLICpix calibration
 */

class TimepixCalibration : public TestBeamObject {

public: 

  TimepixCalibration(const std::string chip, const int method, const std::string runNumber);
  virtual ~TimepixCalibration() {}
  
  double charge(const int row, const int col, const double tot);

private:

  static const int nRows = 256;
  static const int nCols = 256;
  
  int m_method;
  std::string m_RunNumber;

  // Average fit parameters
  double avgGain;
  double avgToT0;
  double avgT;
  double avgC;
  
  // Pixel by pixel fit parameters
  std::vector<std::vector<double> > pixGain;
  std::vector<std::vector<double> > pixToT0;
  std::vector<std::vector<double> > pixT;
  std::vector<std::vector<double> > pixC;

  bool readdata(const std::string filename);  
  double inversesurrogate(const double x, 
                          const double gain, const double tot0,
                          const double c, const double t);

};

#endif // TIMEPIXCALIBRATION_H
