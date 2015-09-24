{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Wed Jul 22 10:19:04 2015) by ROOT version5.34/07
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",12,51,700,500);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1_n2->Range(-12.72727,-12.1519,78.18182,63.79747);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetTickx(1);
   c1_n2->SetTicky(1);
   c1_n2->SetLeftMargin(0.14);
   c1_n2->SetRightMargin(0.2);
   c1_n2->SetTopMargin(0.05);
   c1_n2->SetBottomMargin(0.16);
   c1_n2->SetFrameLineWidth(2);
   c1_n2->SetFrameBorderMode(0);
   c1_n2->SetFrameLineWidth(2);
   c1_n2->SetFrameBorderMode(0);
   
   TH2F *hToTMapPerPixel = new TH2F("hToTMapPerPixel","hToTMapPerPixel",64,0,64,64,0,64);
   hToTMapPerPixel->SetMinimum(6);
   hToTMapPerPixel->SetMaximum(10);
   hToTMapPerPixel->SetDirectory(0);
   hToTMapPerPixel->SetStats(0);
   hToTMapPerPixel->SetLineWidth(2);
   hToTMapPerPixel->SetMarkerStyle(20);
   hToTMapPerPixel->GetXaxis()->SetTitle("Column");
   hToTMapPerPixel->GetXaxis()->SetRange(1,60);
   hToTMapPerPixel->GetXaxis()->SetNdivisions(505);
   hToTMapPerPixel->GetXaxis()->SetLabelFont(132);
   hToTMapPerPixel->GetXaxis()->SetLabelOffset(0.01);
   hToTMapPerPixel->GetXaxis()->SetLabelSize(0.06);
   hToTMapPerPixel->GetXaxis()->SetTitleSize(0.072);
   hToTMapPerPixel->GetXaxis()->SetTitleOffset(0.95);
   hToTMapPerPixel->GetXaxis()->SetTitleFont(132);
   hToTMapPerPixel->GetYaxis()->SetTitle("Row");
   hToTMapPerPixel->GetYaxis()->SetRange(1,60);
   hToTMapPerPixel->GetYaxis()->SetLabelFont(132);
   hToTMapPerPixel->GetYaxis()->SetLabelOffset(0.01);
   hToTMapPerPixel->GetYaxis()->SetLabelSize(0.06);
   hToTMapPerPixel->GetYaxis()->SetTitleSize(0.072);
   hToTMapPerPixel->GetYaxis()->SetTitleOffset(0.95);
   hToTMapPerPixel->GetYaxis()->SetTitleFont(132);
   hToTMapPerPixel->GetZaxis()->SetTitle("Mean charge (ToT)");
   hToTMapPerPixel->GetZaxis()->SetLabelFont(132);
   hToTMapPerPixel->GetZaxis()->SetLabelSize(0.06);
   hToTMapPerPixel->GetZaxis()->SetTitleSize(0.072);
   hToTMapPerPixel->GetZaxis()->SetTitleOffset(0.95);
   hToTMapPerPixel->GetZaxis()->SetTitleFont(132);
   hToTMapPerPixel->Draw("colz");
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
