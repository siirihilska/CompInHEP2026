import ROOT
from array import array

def get_data():
    widths = []
    masses = []

    with open("br.sm2") as file:
        for row in file:
            data = row.split()

            if data[-1]=='WIDTH':
                next(file)
                next(file)
            else:
                widths.append(data[-1])
                masses.append(data[0])
                
    return array('d',[float(x) for x in masses]), array('d', [float(x) for x in widths])

def plot():
    canvas = ROOT.TCanvas('canvas', 'Width as a function of the Higgs mass', 200,10,700,500)
    canvas.SetFillColor(0)
    canvas.SetGrid()
    canvas.SetLogy()

    x, y = get_data()

    n = 90

    graph = ROOT.TGraph(n, x, y)

    graph.SetMarkerColor(4)
    graph.SetMarkerStyle(21)

    graph.GetXaxis().SetTitle('Higgs mass')
    graph.GetYaxis().SetTitle('Width')

    graph.Draw()

    canvas.Update()
    canvas.Print("plot.png")

if __name__ == "__main__":
    plot()