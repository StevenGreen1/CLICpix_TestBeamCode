void CircleMaskGen(float x, float y, float r, std::string description)
{
    int pixelSize = 64;
    float xPos = x;
    float yPos = y;
    float radius = r;

    TH2F *pTH2F = new TH2F("Name","Title",pixelSize,0,(float)(pixelSize),pixelSize,0,(float)(pixelSize));

    for (int row = 0; row < pixelSize; row++)
    {
        for (int column = 0; column < pixelSize; column++)
        {
            float dist = pow(pow(xPos-(float)(column),2) + pow(yPos-(float)(row),2),0.5);
            if (dist > radius)
            {
                pTH2F->Fill((float)(column),(float)(row));

                std::string outputFileName = "CircleMask_" + description + ".txt";
                ofstream outFile(outputFileName.c_str(), std::ios_base::app);
                outFile << "p " << row << " " << column << std::endl; // put on file
            }
        }
    }
    pTH2F->GetYaxis()->SetTitle("Row");
    pTH2F->GetXaxis()->SetTitle("Column");
    pTH2F->Draw("COLZ");
}
