using namespace std;

std::string makestring(double number) {
	std::ostringstream ss;
	ss << number;
	return ss.str();
}

void display(){
	
	// Set some style options
  gROOT->ProcessLine(".x /afs/cern.ch/eng/clic/work/clicpix/ToTMap/lhcbStyle.C");
  gStyle->SetPalette(1);

	// Directory for root files
	string dir = "/afs/cern.ch/eng/clic/work/clicpix/histos/";
	
	// Database of files
	string fileList = "runListMay2015FullNominal.dat";

	// File writing options
	bool writeFile = false;
	string outputFile = "results.root";
	
	TCanvas* canv = new TCanvas();
	TH1F* hEfficiencyThresholdFake = new TH1F("hEfficiencyThresholdFake","hEfficiencyThresholdFake",1500,1000,2500);
	hEfficiencyThresholdFake->GetXaxis()->SetTitle("Threshold (electrons)");
	hEfficiencyThresholdFake->GetYaxis()->SetTitle("Efficiency (%)");
	hEfficiencyThresholdFake->GetYaxis()->SetRangeUser(80,100);
//	hEfficiencyThresholdFake->DrawCopy();
	
	plotData(dir,fileList,canv,"SET9",1034.,0.,1,20); //ideal
	plotData(dir,fileList,canv,"SET10",1220.,0.,4,20); //quarter
	plotData(dir,fileList,canv,"SET12",1145.,0.,2,20); //thick
	plotData(dir,fileList,canv,"SET13",1140.,0.,1,22); //ideal
	plotData(dir,fileList,canv,"SET14",1059.,0.,8,20); //half
	plotData(dir,fileList,canv,"SET15",1199.,0.,2,22); //thick

}

void plotData(string dir, string fileList, TCanvas* canv, string dut, double baseline, double threshold, int color, int style){

	// Make the histograms to plot
	TH1F* hEfficiencyThreshold = new TH1F("hEfficiencyThreshold","hEfficiencyThreshold",1500,1000,2500);
	TH1F* hClusterSizeVersusThreshold = new TH1F("hClusterSizeVersusThreshold","hClusterSizeVersusThreshold",1500,1000,2500);

	// Make objects for reading database list
	ifstream inFile; string line;
	// Open file
	inFile.open(fileList.c_str());
	// While file still contains data
	while(inFile.good()){
		// Loop over lines
		getline(inFile,line);
		// Read line
		char RUN[20], ALIGN[20], DUT[20]; int THL(0);
		sscanf(line.c_str(),"%s %s %s %i",&RUN,&ALIGN,&DUT,&THL);
		// Check if we want this run
		size_t check1 = line.find("0");
		if(check1==string::npos) continue;
		if(strcmp(DUT,dut.c_str()) != 0) continue; // Not the right DUT
		if(threshold != 0 && THL != threshold) continue; // Not the right threshold
		
		TH1F* hClusterSize = new TH1F("hClusterSize","hClusterSize",20,0,20);

//                std::cout << "It's made it to here..." << std::endl;
		
		double tracks=0;
		double tracksAssociated=0;
		double lostHitsFound=0;

		// Open file
		string filename = dir+"histograms"+string(RUN)+".root";
		TFile* file = new TFile(filename.c_str(),"OPEN");
		
		// Get temporary histograms
		TH2F* hTrackInterceptsChipTemp = (TH2F*)gDirectory->Get("/tpanal/ClicpixAnalysis/hTrackInterceptsChip");
		TH2F* hTrackInterceptsChipAssociatedTemp = (TH2F*)gDirectory->Get("/tpanal/ClicpixAnalysis/hTrackInterceptsChipAssociated");
		TH2F* hTrackInterceptsChipLostTemp = (TH2F*)gDirectory->Get("/tpanal/ClicpixAnalysis/hTrackInterceptsChipLost");
		TH2F* hHitPixelsTemp = (TH2F*)gDirectory->Get("/tpanal/ClicpixAnalysis/hHitPixels");
		TH1F* hClusterSizeTemp = (TH1F*)gDirectory->Get("/tpanal/ClicpixAnalysis/hClusterSizeAll");
		
		// Count tracks and associated tracks
		tracks += hTrackInterceptsChipTemp->GetEntries();
		tracksAssociated += hTrackInterceptsChipAssociatedTemp->GetEntries();
		lostHitsFound += hTrackInterceptsChipLostTemp->GetEntries();
		hClusterSize->Add(hClusterSizeTemp,1);
	
		tracksAssociated+=lostHitsFound;
		hClusterSizeVersusThreshold->Fill(10.*(baseline-THL),hClusterSize->GetMean(1));
		
		double efficiency = tracksAssociated/tracks;
		double errorEfficiency = (1./tracks) * sqrt(tracksAssociated*(1-efficiency));

//                std::cout << "Efficiency " << efficiency << std::endl;
//                std::cout << "Threshold  " << 10.*(baseline-THL) << std::endl;

		hEfficiencyThreshold->Fill(10.*(baseline-THL), 100.*efficiency);
		hEfficiencyThreshold->SetBinError(hEfficiencyThreshold->FindBin(10.*(baseline-THL)),100.*errorEfficiency);

//		cout<<" - Efficiency is "<<100.*efficiency<<" +/- "<<100.*errorEfficiency<<" %"<<endl;
	}
	
//	// Make canvases
//	TCanvas* canv2 = new TCanvas();
//	hClusterSizeVersusThreshold->GetXaxis()->SetTitle("Threshold (electrons)");
//	hClusterSizeVersusThreshold->GetYaxis()->SetTitle("Cluster Size");
//	hClusterSizeVersusThreshold->GetYaxis()->SetRangeUser(1,2.5);
//	hClusterSizeVersusThreshold->DrawCopy("p");
	
	canv->cd();
	hEfficiencyThreshold->SetMarkerStyle(style);
	hEfficiencyThreshold->SetMarkerColor(color);
	hEfficiencyThreshold->GetXaxis()->SetTitle("Threshold (electrons)");
	hEfficiencyThreshold->GetYaxis()->SetTitle("Efficiency (%)");
	hEfficiencyThreshold->GetYaxis()->SetRangeUser(80,100);
	hEfficiencyThreshold->DrawCopy("E1");
	
//	if(writeFile){
//		TFile* outFile = new TFile(outputFile.c_str(),"RECREATE");
//		hEfficiencyThreshold->Write();
//		outFile->Close();
//	}
}









int getHotPixels(TH2F* pixelHitmap){
	
	TH1F* pixelHits = new TH1F("pixelHits","pixelHits",10000,0,10000);
	
	for(int x=0;x<64;x++){
		for(int y=0;y<64;y++){
			int nHits = pixelHitmap->GetBinContent(pixelHitmap->GetXaxis()->FindBin(x), pixelHitmap->GetYaxis()->FindBin(y));
			pixelHits->Fill(nHits);
		}
	}
//	pixelHits->DrawCopy();
	pixelHits->Fit("gaus","0q");
	TF1* fit = pixelHits->GetFunction("gaus");

	double sigma = fit->GetParameter(2);
	double mean = fit->GetParameter(1);

	int nHotPixels=0;
	for(int p=0;p<10000;p++) if(p > (mean+5*sigma)) nHotPixels+=pixelHits->GetBinContent(pixelHits->FindBin(p));

	return nHotPixels;
	
}









