import ROOT

ROOT.EnableImplicitMT()

df = ROOT.RDataFrame("Events", "DYJetsToLL.root")

df_selected = df.Filter("HLT_IsoMu24 > 0.5 ", "HLT IsoMu24 trigger")

h = df_selected.Histo1D(("h_pu", "Pileup distribution;N_{PV};Events", 100, 0, 100),"PV_npvs")

canvas = ROOT.TCanvas()
h.Draw()

canvas.SaveAs("pileup.png")