import awkward as ak
import numpy as np
import uproot
from coffea import processor
from coffea.nanoevents import NanoEventsFactory, NanoAODSchema
import hist
import matplotlib.pyplot as plt

f = uproot.open("DYJetsToLL.root")
print(f["Events"].keys())


class DYProcessor(processor.ProcessorABC):
    def __init__(self):
        self._accumulator = processor.dict_accumulator({
            "pileup": hist.Hist.new.Reg(100, 0, 100, name="nPU").Double()
        })

    @property
    def accumulator(self):
        return self._accumulator
    
    def process(self, events):
        output = self.accumulator.copy()

        trig = events.HLT.IsoMu24
        selected = events[trig]

        npu = selected.PV.npvs

        output["pileup"].fill(nPU=npu)


        return output

    def postprocess(self, accumulator):
        return accumulator
    

files = {"DY": ["DYJetsToLL.root"]}

runner = processor.Runner(executor=processor.IterativeExecutor(), schema=NanoAODSchema)

out = runner(files, DYProcessor(), treename="Events")

h = out["pileup"]

h.plot()
plt.xlabel("Number of pileup interactions")
plt.ylabel("Events")
plt.title("Pileup Distribution")
plt.show()