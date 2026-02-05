#ifndef METCLASS_H
#define METCLASS_H

class METClass {
private:
    double meas_x;
    double meas_y;

public:
    METClass(double x, double y);

    double value() const;
    double x() const;
    double y() const;
    double phi() const;
};

#endif
