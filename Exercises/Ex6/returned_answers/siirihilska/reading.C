#include <iostream>
#include "TH1F.h"
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TStyle.h"

using namespace std;

int main(){
  TFile* myFile = TFile::Open("norm_distributed_tree.root");
  if (!myFile) {
    cout << "Error: cannot find file norm_distributed_tree.root!" << endl;
    return 1;
  }

  TTree* myTree = (TTree*)myFile->Get("t");
  if (!myTree) {
    cout << "Error: cannot find tree t!" << endl;
    myFile->Close();
    return 1;
  }

  float myValue;
  TBranch* myBranch = myTree->GetBranch("x");
  myBranch->SetAddress(&myValue);


  TH1F* myHisto = new  TH1F("histo","",100,-5,5);

  int nev = myTree->GetEntries();
  for (int i = 0; i < nev; ++i){
    myTree->GetEvent(i);
    myHisto->Fill(myValue);
  }


  TCanvas* myCanvas = new TCanvas("plot", "plot",500,500);
  myCanvas->SetFillColor(0);
  myCanvas->SetFrameFillColor(0);
  myCanvas->SetBorderMode(0);


  gStyle->SetOptFit(1);
  myHisto->SetLineWidth(2);
  myHisto->SetFillColor(5);
  myHisto->SetXTitle("Value, arbitrary units");
  myHisto->SetYTitle("Entries");
  myHisto->Draw();

  myCanvas->Modified();
  myCanvas->Update();

  myHisto->Fit("gaus");

  myCanvas->Modified();
  myCanvas->Update();
  myCanvas->Print("plot.png");

  myTree->Print();

  cout << "Entries in tree: " << nev << endl;
  cout << "Entries in histogram: " << myHisto->GetEntries() << endl;

  return 0;
}
