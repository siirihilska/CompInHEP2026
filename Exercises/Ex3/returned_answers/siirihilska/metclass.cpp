#include "metclass.h"
#include <cmath>
using namespace std;

METClass::METClass(double x, double y): meas_x(x), meas_y(y) {}

double METClass::value() const { return sqrt(meas_x*meas_x+meas_y*meas_y); }

double METClass::x() const { return meas_x; }

double METClass::y() const { return meas_y; }

double METClass::phi() const { return atan2(meas_y, meas_x); }
