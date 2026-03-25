#include "Pythia8/Pythia.h"
#include "TH1F.h"
#include "TCanvas.h"

#include <iostream>
#include <cmath>
using namespace Pythia8;
int main() {
    Pythia pythia;
    pythia.readString("Beams:idA = 2212");
    pythia.readString("Beams:idB = 2212");
    pythia.readString("Beams:eCM = 13600.");
    pythia.readString("SoftQCD:inelastic = on");       

    pythia.init();
    TH1F *pTMu = new TH1F("pT","dN/dpMu", 100, 0, 50);
    TH1F *etaMu = new TH1F("eta","dN/detaMu", 100, -5, 5);

    int nMu = 0;

    for (int iEvent=0; iEvent < 10000; ++iEvent) {
        if (!pythia.next()) continue;

        for (int i = 0; i < pythia.event.size(); ++i) {
          if (abs(pythia.event[i].id()) == 13) {
            pTMu->Fill( pythia.event[i].pT() );
            etaMu->Fill( pythia.event[i].eta() );

            if (pythia.event[i].pT() > 5.0 && fabs(pythia.event[i].eta()) > 2.5) {
                nMu++;
            }
          }
        }
    }

    TCanvas *canvas1 = new TCanvas("pTCanvas", "pT distr.", 700, 600);
    pTMu->Draw();
    canvas1->SaveAs("pt_distribution.png");

    TCanvas *canvas2 = new TCanvas("etaCanvas", "eta distr.", 700, 600);
    etaMu->Draw();
    canvas2->SaveAs("eta_distribution.png");

    double nProb = nMu/10000;

    std::cout << "Number of muons with pT > 5 GeV/c and |eta| > 2.5: " << nMu << std::endl;
    std::cout << std::fixed << std::setprecision(3) << "Probability to detect a muon from a minimum bias event: " << nProb << std::endl;

    pythia.stat();

    return 0;
}