#include "kernel.hpp"

// menu
int menu() {
  int choose;
  cout << "1.Threshold" << endl;
  cout << "2.Blur" << endl;
  cin >> choose;
  return choose;
}

int main() {
  Kernel k1;
  switch (menu()) {
  case 1:
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