#ifndef KERNEL_HPP
#define KERNEL_HPP
#include "config.hpp"

class Kernel {
private:
  Mat image;
  Mat Blur;
  Mat result;
  Mat grayImage;
  VideoCapture cap;

public:
  Kernel();
  ~Kernel();
  void blurKernel();
  void showBlur();
  void BinaryThreshold(int);
  void makeBinaryImage(int);
};
#endif // KERNEL_HPP
