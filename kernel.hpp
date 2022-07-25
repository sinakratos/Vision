#ifndef KERNEL_HPP
#define KERNEL_HPP
#include "config.hpp"

class Kernel {
private:
  Mat image;
  Mat Blur;
  Mat result;

public:
  Kernel();
  ~Kernel();
  void blurKernel();
  void showBlur();
};
#endif // KERNEL_HPP‍
