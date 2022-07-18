#include "kernel.hpp"

int main() {
  // menu
  int choose;
  cout << "1.Threshold" << endl;
  cout << "2.Blur" << endl;
  cin >> choose;
  //
  Kernel k1;
  switch (choose) {
  case 1:
    cout << "Use n to next and q to quit." << endl;
    k1.BinaryThreshold(0);
    k1.BinaryThreshold(25);
    k1.BinaryThreshold(50);
    k1.BinaryThreshold(75);
    k1.BinaryThreshold(100);
    k1.BinaryThreshold(200);
    break;
  case 2:
    k1.blurKernel();
    k1.showBlur();
    break;
  default:
    cout << "Wrong choose" << endl;
  }
  return 0;
}