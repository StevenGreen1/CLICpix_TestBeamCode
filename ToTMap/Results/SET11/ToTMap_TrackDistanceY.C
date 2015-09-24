{
//=========Macro generated from canvas: c1_n5/c1_n5
//=========  (Wed Jul 22 10:19:04 2015) by ROOT version5.34/07
   TCanvas *c1_n5 = new TCanvas("c1_n5", "c1_n5",12,51,700,500);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1_n5->Range(-0.06728395,-0.2126582,0.05617284,1.116456);
   c1_n5->SetFillColor(0);
   c1_n5->SetBorderMode(0);
   c1_n5->SetBorderSize(2);
   c1_n5->SetTickx(1);
   c1_n5->SetTicky(1);
   c1_n5->SetLeftMargin(0.14);
   c1_n5->SetRightMargin(0.05);
   c1_n5->SetTopMargin(0.05);
   c1_n5->SetBottomMargin(0.16);
   c1_n5->SetFrameLineWidth(2);
   c1_n5->SetFrameBorderMode(0);
   c1_n5->SetFrameLineWidth(2);
   c1_n5->SetFrameBorderMode(0);
   
   TH1F *hToTProfilePixelResponseY__7 = new TH1F("hToTProfilePixelResponseY__7","hToTProfilePixelResponseY",101,-0.05,0.05);
   hToTProfilePixelResponseY__7->SetDirectory(0);
   hToTProfilePixelResponseY__7->SetStats(0);
   hToTProfilePixelResponseY__7->SetLineWidth(2);
   hToTProfilePixelResponseY__7->SetMarkerStyle(20);
   hToTProfilePixelResponseY__7->GetXaxis()->SetTitle("Track distance y (mm)");
   hToTProfilePixelResponseY__7->GetXaxis()->SetNdivisions(505);
   hToTProfilePixelResponseY__7->GetXaxis()->SetLabelFont(132);
   hToTProfilePixelResponseY__7->GetXaxis()->SetLabelOffset(0.01);
   hToTProfilePixelResponseY__7->GetXaxis()->SetLabelSize(0.06);
   hToTProfilePixelResponseY__7->GetXaxis()->SetTitleSize(0.072);
   hToTProfilePixelResponseY__7->GetXaxis()->SetTitleOffset(0.95);
   hToTProfilePixelResponseY__7->GetXaxis()->SetTitleFont(132);
   hToTProfilePixelResponseY__7->GetYaxis()->SetTitle("Most probable ToT");
   hToTProfilePixelResponseY__7->GetYaxis()->SetLabelFont(132);
   hToTProfilePixelResponseY__7->GetYaxis()->SetLabelOffset(0.01);
   hToTProfilePixelResponseY__7->GetYaxis()->SetLabelSize(0.06);
   hToTProfilePixelResponseY__7->GetYaxis()->SetTitleSize(0.072);
   hToTProfilePixelResponseY__7->GetYaxis()->SetTitleOffset(0.95);
   hToTProfilePixelResponseY__7->GetYaxis()->SetTitleFont(132);
   hToTProfilePixelResponseY__7->GetZaxis()->SetLabelFont(132);
   hToTProfilePixelResponseY__7->GetZaxis()->SetLabelSize(0.06);
   hToTProfilePixelResponseY__7->GetZaxis()->SetTitleSize(0.072);
   hToTProfilePixelResponseY__7->GetZaxis()->SetTitleOffset(0.95);
   hToTProfilePixelResponseY__7->GetZaxis()->SetTitleFont(132);
   hToTProfilePixelResponseY__7->Draw("");
   c1_n5->Modified();
   c1_n5->cd();
   c1_n5->SetSelected(c1_n5);
}
