#include "kernel.hpp"
#include "threshold.hpp"

int main() {
  // menu
  Threshold T;
  Kernel k;
  int choose;
  cout << "1.Threshold" << endl;
  cout << "2.Blur" << endl;
  cin >> choose;
  //
  switch (choose) {
  case 1:
    T.BinaryThreshold();
    break;
  case 2:
    k.blurKernel();
    k.showBlur();
    break;
  default:
    cout << "Wrong choose" << endl;
  }
  return 0;
}