using namespace std;

std::string makestring(double number) {
	std::ostringstream ss;
	ss << number;
	return ss.str();
}

bool debug = false;

void display(){
	
	// Set some style options
  gROOT->ProcessLine(".x /afs/cern.ch/eng/clic/work/clicpix/ToTMap/lhcbStyle.C");
  gStyle->SetPalette(1);

	// Directory for root files
	string dir = "/afs/cern.ch/eng/clic/work/clicpix/histos/";
	
	// Database of files
	string fileList = "/afs/cern.ch/eng/clic/work/clicpix/macros/runListMay2015FullNominal.dat";
  
  // Make debugging histograms
  TH1F* hResolutionX = new TH1F("hResolutionX","hResolutionX",1010,-1,100);
  TH1F* hResidualsMeanX = new TH1F("hResidualsMeanX","hResidualsMeanX",1010,-1,100);
  
  // Make objects for reading database list
  ifstream inFile; string line; int fileNumber=0;
  // Open file
  inFile.open(fileList.c_str());
  // While file still contains data
  while(inFile.good()){
    // Loop over lines
    getline(inFile,line);
    // Read line
    char RUN[20], ALIGN[20], DUT[20]; int ANG(0); int VOL(0);
    sscanf(line.c_str(),"%s %s %s %i %i",&RUN,&ALIGN,&DUT,&ANG,&VOL);
    // Check if we want this run
    size_t check1 = line.find("1");
    if(check1==string::npos) continue;
    if(line.find("#") != string::npos) continue; // Hash key makes it ignore a run
    
    // Open file
    string filename = dir+"histograms"+string(RUN)+".root";
    TFile* file = new TFile(filename.c_str(),"OPEN");
    cout<<"Opening file "<<filename<<endl;
    
    if(!file){cout<<"File for run "<<RUN<<" does not exist"<<endl; continue;}

    // Get temporary histograms
    TH1F* hGlobalResidualsX = (TH1F*)gDirectory->Get("/tpanal/ClicpixAnalysis/hGlobalResidualsX");
    hGlobalResidualsX->Fit("gaus","0q");
    TF1* fit = hGlobalResidualsX->GetFunction("gaus");
    double sigma = 1000.*fit->GetParameter(2);
    double mean = 1000.*fit->GetParameter(1);
    hResolutionX->Fill(fileNumber,sigma);
    hResidualsMeanX->Fill(fileNumber,mean);
    
    // Increment file number
    fileNumber++;
  }
  
  // Plot debugging histograms
  TCanvas* canv = new TCanvas();
  hResolutionX->GetYaxis()->SetTitle("Resolution (#mum)");
  hResolutionX->DrawCopy("p");

  TCanvas* canv2 = new TCanvas();
  hResidualsMeanX->GetYaxis()->SetTitle("Residual mean (#mum)");
  hResidualsMeanX->DrawCopy("p");
  
}






