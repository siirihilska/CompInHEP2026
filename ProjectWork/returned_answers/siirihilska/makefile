NBEXEC = jupyter nbconvert --to notebook --execute --inplace
OUTDIR = output

.PHONY: all generate analysis clean

all: generate analysis

generate:
	mkdir -p $(OUTDIR)
	$(NBEXEC) Event_Generation.ipynb

analysis:
	mkdir -p $(OUTDIR)
	$(NBEXEC) Analysis.ipynb

clean:
	rm -rf $(OUTDIR)
	rm -f *.nbconvert.ipynb
