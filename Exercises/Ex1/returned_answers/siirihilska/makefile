TEX = FeynmanGraphs
PDF = $(TEX).pdf
BIB = References.bib

all: $(PDF)

$(PDF): $(TEX).tex $(BIB)
	latexmk -pdf -bibtex $(TEX)

file: $(PDF)

clean:
	latexmk -C

