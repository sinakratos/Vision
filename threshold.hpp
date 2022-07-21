#ifndef THRESHOLD__HPP
#define THRESHOLD__HPP
#include "config.hpp"

class Threshold {
private:
  Mat image;
  Mat Blur;
  Mat result;
  Mat grayImage;
  VideoCapture cap;

public:
  Threshold();
  ~Threshold();
  void BinaryThreshold();
  void makeBinaryImage(int);
};
#endif // THRESHOLD__HPP
