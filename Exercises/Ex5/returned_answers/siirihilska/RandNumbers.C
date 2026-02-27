#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"

void RandNumbers(Int_t N = 1000, Double_t mean = 0.0, Double_t sigma = 1.0, const char* outFile = "norm_distributed_tree.root")

{

TRandom3 rng(0);

TFile f(outFile, "RECREATE");

TTree t("t", "Tree of random numbers");

Double_t x = 0.0;

t.Branch("x", &x, "x/D");

for (Int_t i=0; i < N; ++i) {x = rng.Gaus(mean, sigma); t.Fill();}

t.Write();
f.Close();

}
