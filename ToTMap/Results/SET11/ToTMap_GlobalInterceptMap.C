{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Jul 22 10:18:54 2015) by ROOT version5.34/07
   TCanvas *c1 = new TCanvas("c1", "c1",12,51,700,500);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1->Range(-12.72727,-12.1519,78.18182,63.79747);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.14);
   c1->SetRightMargin(0.2);
   c1->SetTopMargin(0.05);
   c1->SetBottomMargin(0.16);
   c1->SetFrameLineWidth(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameLineWidth(2);
   c1->SetFrameBorderMode(0);
   
   TH2F *hToTMap = new TH2F("hToTMap","hToTMap",32,0,64,32,0,64);
   hToTMap->SetMinimum(6);
   hToTMap->SetMaximum(10);
   hToTMap->SetDirectory(0);
   hToTMap->SetStats(0);
   hToTMap->SetLineWidth(2);
   hToTMap->SetMarkerStyle(20);
   hToTMap->GetXaxis()->SetTitle("Column");
   hToTMap->GetXaxis()->SetRange(1,30);
   hToTMap->GetXaxis()->SetNdivisions(505);
   hToTMap->GetXaxis()->SetLabelFont(132);
   hToTMap->GetXaxis()->SetLabelOffset(0.01);
   hToTMap->GetXaxis()->SetLabelSize(0.06);
   hToTMap->GetXaxis()->SetTitleSize(0.072);
   hToTMap->GetXaxis()->SetTitleOffset(0.95);
   hToTMap->GetXaxis()->SetTitleFont(132);
   hToTMap->GetYaxis()->SetTitle("Row");
   hToTMap->GetYaxis()->SetRange(1,30);
   hToTMap->GetYaxis()->SetLabelFont(132);
   hToTMap->GetYaxis()->SetLabelOffset(0.01);
   hToTMap->GetYaxis()->SetLabelSize(0.06);
   hToTMap->GetYaxis()->SetTitleSize(0.072);
   hToTMap->GetYaxis()->SetTitleOffset(0.95);
   hToTMap->GetYaxis()->SetTitleFont(132);
   hToTMap->GetZaxis()->SetTitle("Mean charge (ToT)");
   hToTMap->GetZaxis()->SetLabelFont(132);
   hToTMap->GetZaxis()->SetLabelSize(0.06);
   hToTMap->GetZaxis()->SetTitleSize(0.072);
   hToTMap->GetZaxis()->SetTitleOffset(0.95);
   hToTMap->GetZaxis()->SetTitleFont(132);
   hToTMap->Draw("colz");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
