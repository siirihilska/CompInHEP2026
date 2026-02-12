#include <iostream>
#include "reconst_track.h"
#include "sim_particles.h"

using namespace std;

int main() {
    Reconst_track track(10.0, 3.0, 4.0, 5.0);

    cout << " Test first class " << endl;
    cout << " pT = " << track.transverse_mom() << endl;
    cout << " eta = " << track.pseudorapidity() << endl;
    cout << endl;

    Sim_particles electron(10.0, 3.0, 4.0, 5.0, 11, 22);

    cout << " Test second class " << endl;
    cout << " pT = " <<  electron.transverse_mom() << endl;
    cout << " eta = " << electron.pseudorapidity() << endl;
    cout << " particle id = " << electron.get_id() << endl;
    cout << " parent particle id = " << electron.get_parent_id() << endl;

    return 0;
}

