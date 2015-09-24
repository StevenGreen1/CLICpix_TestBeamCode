{
//=========Macro generated from canvas: c1_n4/c1_n4
//=========  (Wed Jul 22 10:19:04 2015) by ROOT version5.34/07
   TCanvas *c1_n4 = new TCanvas("c1_n4", "c1_n4",12,51,700,500);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1_n4->Range(-0.07121212,-3.240506,0.08030303,17.01266);
   c1_n4->SetFillColor(0);
   c1_n4->SetBorderMode(0);
   c1_n4->SetBorderSize(2);
   c1_n4->SetTickx(1);
   c1_n4->SetTicky(1);
   c1_n4->SetLeftMargin(0.14);
   c1_n4->SetRightMargin(0.2);
   c1_n4->SetTopMargin(0.05);
   c1_n4->SetBottomMargin(0.16);
   c1_n4->SetFrameLineWidth(2);
   c1_n4->SetFrameBorderMode(0);
   c1_n4->SetFrameLineWidth(2);
   c1_n4->SetFrameBorderMode(0);
   
   TH2F *hToTMapPixelResponseY = new TH2F("hToTMapPixelResponseY","hToTMapPixelResponseY",101,-0.05,0.05,16,0,16);
   hToTMapPixelResponseY->SetDirectory(0);
   hToTMapPixelResponseY->SetStats(0);
   hToTMapPixelResponseY->SetLineWidth(2);
   hToTMapPixelResponseY->SetMarkerStyle(20);
   hToTMapPixelResponseY->GetXaxis()->SetTitle("Track distance y (mm)");
   hToTMapPixelResponseY->GetXaxis()->SetRange(1,101);
   hToTMapPixelResponseY->GetXaxis()->SetNdivisions(505);
   hToTMapPixelResponseY->GetXaxis()->SetLabelFont(132);
   hToTMapPixelResponseY->GetXaxis()->SetLabelOffset(0.01);
   hToTMapPixelResponseY->GetXaxis()->SetLabelSize(0.06);
   hToTMapPixelResponseY->GetXaxis()->SetTitleSize(0.072);
   hToTMapPixelResponseY->GetXaxis()->SetTitleOffset(0.95);
   hToTMapPixelResponseY->GetXaxis()->SetTitleFont(132);
   hToTMapPixelResponseY->GetYaxis()->SetTitle("ToT");
   hToTMapPixelResponseY->GetYaxis()->SetRange(1,16);
   hToTMapPixelResponseY->GetYaxis()->SetLabelFont(132);
   hToTMapPixelResponseY->GetYaxis()->SetLabelOffset(0.01);
   hToTMapPixelResponseY->GetYaxis()->SetLabelSize(0.06);
   hToTMapPixelResponseY->GetYaxis()->SetTitleSize(0.072);
   hToTMapPixelResponseY->GetYaxis()->SetTitleOffset(0.95);
   hToTMapPixelResponseY->GetYaxis()->SetTitleFont(132);
   hToTMapPixelResponseY->GetZaxis()->SetTitle("Number of events");
   hToTMapPixelResponseY->GetZaxis()->SetLabelFont(132);
   hToTMapPixelResponseY->GetZaxis()->SetLabelSize(0.06);
   hToTMapPixelResponseY->GetZaxis()->SetTitleSize(0.072);
   hToTMapPixelResponseY->GetZaxis()->SetTitleOffset(0.95);
   hToTMapPixelResponseY->GetZaxis()->SetTitleFont(132);
   hToTMapPixelResponseY->Draw("colz");
   c1_n4->Modified();
   c1_n4->cd();
   c1_n4->SetSelected(c1_n4);
}
