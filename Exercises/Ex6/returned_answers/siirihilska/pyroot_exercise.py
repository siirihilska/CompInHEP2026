import ROOT
import random
from array import array
import os

def random_numbers():
    N = 1000
    mean = 0.0
    sigma = 1.0 
    outFile = "norm_distributed_numbers.root"

    f = ROOT.TFile(outFile, "RECREATE")

    t = ROOT.TTree("t", "Tree of random numbers")

    x = array("d", [0])

    t.Branch("x",x,"x/D")

    for i in range(N):
        x[0] = random.gauss(mean, sigma)
        t.Fill()

    t.Write()
    f.Close()

def reading():
    filename = "norm_distributed_numbers.root"

    if not os.path.isfile(filename):
        print("Error: cannot find file norm_distributed_numbers.root!")

    file = ROOT.TFile.Open("norm_distributed_numbers.root")
    tree = file.Get("t")

    if not tree:
        print("Error: cannot find tree t!")
    
    x = array('d', [0.])
    tree.SetBranchAddress("x", x)
    tree.GetEntry(0)

    histo = ROOT.TH1F("histo","",100,-5,5)

    tree.Draw("x >> histo")

    canvas = ROOT.TCanvas("plot", "plot",500,500)
    canvas.SetFillColor(0)
    canvas.SetFrameFillColor(0)
    canvas.SetBorderMode(0)

    ROOT.gStyle.SetOptFit(1)

    histo.SetLineWidth(2)
    histo.SetFillColor(5)
    histo.SetXTitle("Value, arbitrary units")
    histo.SetYTitle("Entries")
    histo.Draw()

    canvas.Modified()
    canvas.Update()

    histo.Fit("gaus")

    canvas.Modified()
    canvas.Update()
    canvas.Print("plot.png")

    #tree.Print()

    
if __name__ == "__main__":
    random_numbers()
    reading()