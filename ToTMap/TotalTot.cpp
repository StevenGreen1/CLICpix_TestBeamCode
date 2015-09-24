using namespace std;

//================================================

std::string makestring(int voltage)
{
  std::ostringstream strs;
  strs << voltage;
  std::string legs = strs.str();
  return legs;
}

//================================================

std::string makestringD(double voltage)
{
  std::ostringstream strs;
  strs << voltage;
  std::string legs = strs.str();
  return legs;
}

//================================================

void display()
{
    gROOT->ProcessLine(".x lhcbStyle.C");
    gStyle->SetPalette(1);

    int setNumbers[6] = {9,10,12,13,14,15};
    int rootLineColors[6] = {1,2,3,4,6,7};
    std::string descriptions[6] = {"Ideal Alignment", "Quarter Pixel Misalignment", "Ideal Alignment, Thicker Glue", "Ideal Alignment", "Half Pixel Misalignment", "Ideal Alignment, Thicker Glue"};

    TCanvas* canv = new TCanvas();
    canv->cd();

    TLegend *pTLegend = new TLegend(0.6,0.7,0.9,0.9);

    for (int i = 0; i < 6; i++)
    {
        std::string fileName = "/afs/cern.ch/eng/clic/work/clicpix/histos/set" + makestring(setNumbers[i]) + "Nom.root";
        TFile* pTFile = new TFile(fileName.c_str());

        TH1F* pTH1F = (TH1F*)pTFile->Get("tpanal/ClicpixAnalysis/hClusterTOTAssociated1pix");
        pTH1F->SetLineColor(rootLineColors[i]);

        if (i==0)
        {
            pTH1F->GetXaxis()->SetRangeUser(0,17);
            pTH1F->GetXaxis()->SetTitle("Mean Charge (ToT)");
            pTH1F->GetYaxis()->SetRangeUser(0,30000);
            pTH1F->GetYaxis()->SetTitle("Number of Entries");
            pTH1F->Draw("");
        }
        else
        {
            pTH1F->Draw("same");
        }
        pTLegend->AddEntry(pTH1F, descriptions[i].c_str(), "l");
    }

    pTLegend->Draw("same");
    canv->SaveAs("ToT_Distribution.pdf");
    canv->SaveAs("ToT_Distribution.png");

/*    string filename = "/afs/cern.ch/eng/clic/work/clicpix/histos/set" + setNumber + "Nom.root";
    TFile* file = new TFile(filename.c_str(),"OPEN");
    // Plot the map of ToT
    TCanvas* canv = new TCanvas();
    canv->cd();
    canv->SetRightMargin(0.2);
    hToTMap->GetXaxis()->SetTitle("Column");
    hToTMap->GetXaxis()->SetRangeUser(0,60);
    hToTMap->GetYaxis()->SetTitle("Row");
    hToTMap->GetYaxis()->SetRangeUser(0,60);
    hToTMap->GetZaxis()->SetTitle("Mean charge (ToT)");
    hToTMap->SetMaximum(10);
    hToTMap->SetMinimum(6);
    hToTMap->DrawCopy("colz");
    std::string pngFileName = "SET" + setNumber + "/ToTMap_GlobalInterceptMap.png";
    std::string dotCFileName = "SET" + setNumber + "/ToTMap_GlobalInterceptMap.C";
    canv->SaveAs(pngFileName.c_str());
    canv->SaveAs(dotCFileName.c_str());
*/
}
