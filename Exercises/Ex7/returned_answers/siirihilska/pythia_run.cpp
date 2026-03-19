#include "Pythia8/Pythia.h"
#include "TH1F.h"
#include "TCanvas.h"

#include <iostream>
using namespace Pythia8;

int main() {

    Pythia pythia;
    pythia.readString("Beams:idA = 2212");  
    pythia.readString("Beams:idB = 2212");  
    pythia.readString("Beams:eCM = 13600.");
    pythia.readString("HiggsSM:all = on");
    pythia.readString("25:m0=125");
    pythia.readString("PDF:pSet=LHAPDF6:cteq6l1");

    pythia.init();

    TH1F *masses = new TH1F("mass", "Higgs mass distribution", 50, 120, 130);

    for (int iEvent = 0; iEvent < 1000; ++iEvent){
        if (!pythia.next()) continue;

        for (int i = 0; i < pythia.event.size(); ++i) {
            if (pythia.event[i].id() == 25) {
                masses->Fill(pythia.event[i].m());
            }
        }
    }

    TCanvas *canvas = new TCanvas("canvas", "Higgs mass", 700, 600);
    masses->Draw();
    canvas->SaveAs("mass_distribution.png");

    pythia.stat();

    return 0;
}