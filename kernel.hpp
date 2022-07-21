#ifndef KERNEL_HPP
#define KERNEL_HPP
#include "config.hpp"

class Kernel {
private:
  VideoCapture cap;
  Mat image;
  Mat Blur;
  Mat result;

public:
  Kernel();
  ~Kernel();
  void blurKernel();
  void showBlur();
};
#endif // KERNEL_HPP
