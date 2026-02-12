#include "reconst_track.h"
#include <cmath>

using namespace std;

Reconst_track::Reconst_track(double e, double x, double y, double z): E(e), px(x), py(y), pz(z) {}

double Reconst_track::transverse_mom() const { return sqrt(px*px+py*py); }

double Reconst_track::pseudorapidity() const { 
    double pt = sqrt(px*px+py*py);
    double theta = atan2(pt, pz);
    return -log(tan(theta / 2.0));
}

