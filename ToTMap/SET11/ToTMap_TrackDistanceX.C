{
//=========Macro generated from canvas: c1_n3/c1_n3
//=========  (Wed Jul 22 10:19:04 2015) by ROOT version5.34/07
   TCanvas *c1_n3 = new TCanvas("c1_n3", "c1_n3",12,51,700,500);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1_n3->Range(-0.07121212,-3.240506,0.08030303,17.01266);
   c1_n3->SetFillColor(0);
   c1_n3->SetBorderMode(0);
   c1_n3->SetBorderSize(2);
   c1_n3->SetTickx(1);
   c1_n3->SetTicky(1);
   c1_n3->SetLeftMargin(0.14);
   c1_n3->SetRightMargin(0.2);
   c1_n3->SetTopMargin(0.05);
   c1_n3->SetBottomMargin(0.16);
   c1_n3->SetFrameLineWidth(2);
   c1_n3->SetFrameBorderMode(0);
   c1_n3->SetFrameLineWidth(2);
   c1_n3->SetFrameBorderMode(0);
   
   TH2F *hToTMapPixelResponseX = new TH2F("hToTMapPixelResponseX","hToTMapPixelResponseX",101,-0.05,0.05,15,0,15);
   hToTMapPixelResponseX->SetDirectory(0);
   hToTMapPixelResponseX->SetStats(0);
   hToTMapPixelResponseX->SetLineWidth(2);
   hToTMapPixelResponseX->SetMarkerStyle(20);
   hToTMapPixelResponseX->GetXaxis()->SetTitle("Track distance x (mm)");
   hToTMapPixelResponseX->GetXaxis()->SetRange(1,101);
   hToTMapPixelResponseX->GetXaxis()->SetNdivisions(505);
   hToTMapPixelResponseX->GetXaxis()->SetLabelFont(132);
   hToTMapPixelResponseX->GetXaxis()->SetLabelOffset(0.01);
   hToTMapPixelResponseX->GetXaxis()->SetLabelSize(0.06);
   hToTMapPixelResponseX->GetXaxis()->SetTitleSize(0.072);
   hToTMapPixelResponseX->GetXaxis()->SetTitleOffset(0.95);
   hToTMapPixelResponseX->GetXaxis()->SetTitleFont(132);
   hToTMapPixelResponseX->GetYaxis()->SetTitle("ToT");
   hToTMapPixelResponseX->GetYaxis()->SetRange(1,16);
   hToTMapPixelResponseX->GetYaxis()->SetLabelFont(132);
   hToTMapPixelResponseX->GetYaxis()->SetLabelOffset(0.01);
   hToTMapPixelResponseX->GetYaxis()->SetLabelSize(0.06);
   hToTMapPixelResponseX->GetYaxis()->SetTitleSize(0.072);
   hToTMapPixelResponseX->GetYaxis()->SetTitleOffset(0.95);
   hToTMapPixelResponseX->GetYaxis()->SetTitleFont(132);
   hToTMapPixelResponseX->GetZaxis()->SetTitle("Number of events");
   hToTMapPixelResponseX->GetZaxis()->SetLabelFont(132);
   hToTMapPixelResponseX->GetZaxis()->SetLabelSize(0.06);
   hToTMapPixelResponseX->GetZaxis()->SetTitleSize(0.072);
   hToTMapPixelResponseX->GetZaxis()->SetTitleOffset(0.95);
   hToTMapPixelResponseX->GetZaxis()->SetTitleFont(132);
   hToTMapPixelResponseX->Draw("colz");
   c1_n3->Modified();
   c1_n3->cd();
   c1_n3->SetSelected(c1_n3);
}
