#ifndef RECONST_TRACK_H
#define RECONST_TRACK_H

class Reconst_track {
private:
    double E;
    double px;
    double py;
    double pz;

public:
    Reconst_track(double e, double x, double y, double z);

    double transverse_mom() const;
    double pseudorapidity() const;

};

#endif
