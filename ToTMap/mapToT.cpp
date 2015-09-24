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

void display(std::string setNumber)
{
    gROOT->ProcessLine(".x lhcbStyle.C");
    gStyle->SetPalette(1);
	
    string filename = "/afs/cern.ch/eng/clic/work/clicpix/histos/set" + setNumber + "Nom.root";
    TFile* file = new TFile(filename.c_str(),"OPEN");

    int nBinsX(32), nBinsY(32);
    int nPixelsX(64), nPixelsY(64);
	
    std::cout<<"Making global intercept tot map"<<std::endl;
    // Global intercept map (not per pixel)
    TH2F* hToTMap = new TH2F("hToTMap","hToTMap",nBinsX,0,nPixelsX,nBinsY,0,nPixelsY);
    for(int x=0;x<nBinsX;x++)
    {
        for(int y=0;y<nBinsY;y++)
        {
            int id = x + y*nBinsX;
            // Get the ToT distribution for this location
            string histoname = "/tpanal/ClicpixAnalysis/hClusterTOTAssociated1pixMap"+makestring(id);
            TH1F* totMapHisto = 0;
            totMapHisto = (TH1F*)gDirectory->Get(histoname.c_str());
            if(totMapHisto == 0) continue;
            if(totMapHisto->GetEntries() < 20) continue;

            // Fit the tot distribution and enter the value in the ToT map
            totMapHisto->Fit("gaus","0q");
            TF1* fit = totMapHisto->GetFunction("gaus");
            hToTMap->Fill(x*floor(nPixelsX/nBinsX),y*floor(nPixelsY/nBinsY),fit->GetParameter(1));

            delete fit;
            delete totMapHisto;
        }
    }
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
  
    std::cout<<"Making per pixel tot map"<<std::endl;
    // Per pixel map
    TH2F* hToTMapPerPixel = new TH2F("hToTMapPerPixel","hToTMapPerPixel",nPixelsX,0,nPixelsX,nPixelsY,0,nPixelsY);
    for(int x=0;x<nPixelsX;x++)
    {
        for(int y=0;y<nPixelsY;y++)
        {
            int id = x + y*nPixelsX;
            // Get the ToT distribution for this location
            string histoname = "/tpanal/ClicpixAnalysis/hClusterTOTAssociated1pixPixel"+makestring(id);
            TH1F* totMapHisto = 0;
            totMapHisto = (TH1F*)gDirectory->Get(histoname.c_str());
            if(totMapHisto == 0) continue;
            if(totMapHisto->GetEntries() < 10) continue;
      
            // Fit the tot distribution and enter the value in the ToT map
            totMapHisto->Fit("gaus","0q");
            TF1* fit = totMapHisto->GetFunction("gaus");
            hToTMapPerPixel->Fill(x,y,fit->GetParameter(1));
      
            delete fit;
            delete totMapHisto;
        }
    }
    // Plot the map of ToT
    TCanvas* canv2 = new TCanvas();
    canv2->cd();
    canv2->SetRightMargin(0.2);
    hToTMapPerPixel->GetXaxis()->SetTitle("Column");
    hToTMapPerPixel->GetXaxis()->SetRangeUser(0,60);
    hToTMapPerPixel->GetYaxis()->SetTitle("Row");
    hToTMapPerPixel->GetYaxis()->SetRangeUser(0,60);
    hToTMapPerPixel->GetZaxis()->SetTitle("Mean charge (ToT)");
    hToTMapPerPixel->SetMaximum(10);
    hToTMapPerPixel->SetMinimum(6);
    hToTMapPerPixel->DrawCopy("colz");
    std::string pngFileName2 = "SET" + setNumber + "/ToTMap_PerPixelMap.png";
    std::string dotCFileName2 = "SET" + setNumber + "/ToTMap_PerPixelMap.C";
    canv2->SaveAs(pngFileName2.c_str());
    canv2->SaveAs(dotCFileName2.c_str());

    std::cout<<"Making pixel response tot maps"<<std::endl;
    // Pixel response maps
    int responseBins=100;
    double responseWidth=0.05;
    TH2F* hToTMapPixelResponseX = new TH2F("hToTMapPixelResponseX","hToTMapPixelResponseX",responseBins+1,-responseWidth,responseWidth,15,0,15);
    for(double rID=0;rID<responseBins;rID++)
    {
        // Get the ToT distribution for this location
        string histoname = "/tpanal/ClicpixAnalysis/hClusterTOTAssociated1pixResponseX"+makestringD(rID);
        TH1F* totMapHisto = 0;
        totMapHisto = (TH1F*)gDirectory->Get(histoname.c_str());
        if(totMapHisto == 0) continue;
        if(totMapHisto->GetEntries() < 1) continue;
        // loop over all tot bins
        for(int i=0;i<45;i++)
        {
            hToTMapPixelResponseX->Fill(2.*responseWidth*(rID/100.)-responseWidth,i,totMapHisto->GetBinContent(totMapHisto->FindBin(i)));
        }
        delete totMapHisto;
    }

    // Plot the map of ToT
    TCanvas* canv3 = new TCanvas();
    canv3->cd();
    canv3->SetRightMargin(0.2);
    hToTMapPixelResponseX->GetXaxis()->SetTitle("Track distance x (mm)");
    hToTMapPixelResponseX->GetXaxis()->SetRangeUser(-0.05,0.05);
    hToTMapPixelResponseX->GetYaxis()->SetTitle("ToT");
    hToTMapPixelResponseX->GetYaxis()->SetRangeUser(0,16);
    hToTMapPixelResponseX->GetZaxis()->SetTitle("Number of events");
    hToTMapPixelResponseX->DrawCopy("colz");
    std::string pngFileName3 = "SET" + setNumber + "/ToTMap_TrackDistanceX.png";
    std::string dotCFileName3 = "SET" + setNumber + "/ToTMap_TrackDistanceX.C";
    canv3->SaveAs(pngFileName3.c_str());
    canv3->SaveAs(dotCFileName3.c_str());

    TH1F* hToTProfilePixelResponseY = new TH1F("hToTProfilePixelResponseY","hToTProfilePixelResponseY",responseBins+1,-responseWidth,responseWidth);
    TH2F* hToTMapPixelResponseY = new TH2F("hToTMapPixelResponseY","hToTMapPixelResponseY",responseBins+1,-responseWidth,responseWidth,16,0,16);
    for(double rID=0;rID<responseBins;rID++)
    {
        // Get the ToT distribution for this location
        string histoname = "/tpanal/ClicpixAnalysis/hClusterTOTAssociated1pixResponseY"+makestringD(rID);
        TH1F* totMapHisto = 0;
        totMapHisto = (TH1F*)gDirectory->Get(histoname.c_str());
        if(totMapHisto == 0) continue;
        if(totMapHisto->GetEntries() < 1) continue;
        // loop over all tot bins
        for(int i=0;i<45;i++)
        {
            hToTMapPixelResponseY->Fill(2.*responseWidth*(rID/100.)-responseWidth,i,totMapHisto->GetBinContent(totMapHisto->FindBin(i)));
        }
        hToTProfilePixelResponseY->Fill(2.*responseWidth*(rID/100.)-responseWidth+0.001,totMapHisto->GetXaxis()->GetBinCenter(totMapHisto->GetMaximumBin()));
        delete totMapHisto;
    }
    // Plot the map of ToT
    TCanvas* canv4 = new TCanvas();
    canv4->cd();
    canv4->SetRightMargin(0.2);
    hToTMapPixelResponseY->GetXaxis()->SetTitle("Track distance y (mm)");
    hToTMapPixelResponseY->GetXaxis()->SetRangeUser(-0.05,0.05);
    hToTMapPixelResponseY->GetYaxis()->SetTitle("ToT");
    hToTMapPixelResponseY->GetYaxis()->SetRangeUser(0,16);
    hToTMapPixelResponseY->GetZaxis()->SetTitle("Number of events");
    hToTMapPixelResponseY->DrawCopy("colz");
//    drawline(-0.03,1,7);
//    drawline(0.03,1,7);
    std::string pngFileName4 = "SET" + setNumber + "/ToTMap_TrackDistanceY_ColZ.png";
    std::string dotCFileName4 = "SET" + setNumber + "/ToTMap_TrackDistanceY_ColZ.C";
    canv4->SaveAs(pngFileName4.c_str());
    canv4->SaveAs(dotCFileName4.c_str());

    TCanvas* canv6 = new TCanvas();
    canv6->cd();
    hToTProfilePixelResponseY->GetXaxis()->SetTitle("Track distance y (mm)");
    hToTProfilePixelResponseY->GetYaxis()->SetTitle("Most probable ToT");
    hToTProfilePixelResponseY->DrawCopy("");
    std::string pngFileName6 = "SET" + setNumber + "/ToTMap_TrackDistanceY.png";
    std::string dotCFileName6 = "SET" + setNumber + "/ToTMap_TrackDistanceY.C";
    canv6->SaveAs(pngFileName6.c_str());
    canv6->SaveAs(dotCFileName6.c_str());

    TCanvas* canv5 = new TCanvas();
    canv5->cd();
    TH1F* sidebandLow = (TH1F*)gDirectory->Get("/tpanal/ClicpixAnalysis/hClusterTOTAssociated1pixResponseY20");
    TH1F* sidebandHigh = (TH1F*)gDirectory->Get("/tpanal/ClicpixAnalysis/hClusterTOTAssociated1pixResponseY80");
    sidebandHigh->GetXaxis()->SetTitle("ToT (single pixel)");
    sidebandHigh->GetXaxis()->SetRangeUser(0,20);
    sidebandHigh->DrawCopy("");
    sidebandLow->SetLineColor(2);
    sidebandLow->DrawCopy("same");
    std::string pngFileName5 = "SET" + setNumber + "/ClusterTOTAssociated1pixResponseY20_Y80.png";
    std::string dotCFileName5 = "SET" + setNumber + "/ClusterTOTAssociated1pixResponseY20_Y80.C";
    canv5->SaveAs(pngFileName5.c_str());
    canv5->SaveAs(dotCFileName5.c_str());
}

//================================================

void drawline(double xpos, int colour, int style)
{
  TLine *line = new TLine(xpos,0,xpos,15);
  line->SetLineStyle(style);
  line->SetLineColor(colour);
  line->Draw();
}

