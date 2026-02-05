#include "metclass.h"
#include <iostream>
using namespace std;

int main() {
  METClass met(5.0,7.0);

  cout << "value: " << met.value() << "\n";
  cout << "x component: " << met.x() << "\n"; 
  cout << "y component: " << met.y() << "\n";
  cout << "phi: " << met.phi() << "\n";
 
  return 0;
}
