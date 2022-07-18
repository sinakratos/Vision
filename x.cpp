#include <iostream>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/opencv.hpp>
// namespace
using namespace std;
using namespace cv;
class Kernel {
private:
  Mat image;
  Mat Blur;
  Mat result;

public:
  Kernel();
  ~Kernel();
  void blurKernel();
  void show();
};

Kernel::Kernel() {
  image = imread("test.png", 0);
  Blur = (Mat_<float>(3, 3) << 0.0625, 0.125, 0.0625, 0.125, 0.25, 0.125,
          0.0625, 0.125, 0.0625);
  int dstRow = image.rows - Blur.rows + 1;
  int dstCol = image.cols - Blur.cols + 1;
  result = (dstRow, dstCol, image.type());
  blurKernel();
  show();
}

void Kernel::blurKernel() {
  if (!image.data) {
    cerr << "Error reading robot image" << endl;
    exit(0);
  }
  float sum = 0.0, x, y;
  for (int i = 0; i < image.rows; i++) {
    for (int j = 0; j < image.cols; j++) {
      sum = 0.0;
      for (int m = 0; m < Blur.rows; m++) {
        if (m == 0) {
          x = i;
        } else if (m == 1) {
          x = i + 1;
        } else if (m == 2) {
          x = i + 2;
        }

        for (int n = 0; n < Blur.cols; n++) {
          if (n == 0) {
            y = j;
          } else if (n == 1) {
            y = j + 1;
          } else if (n == 2) {
            y = j + 2;
          }

          if (!(x > image.rows && y > image.cols)) {
            sum += Blur.at<float>(m, n) * image.at<uchar>(x, y);
          }
        }
      }
      result.at<uchar>(i, j) = sum;
    }
  }
}

void Kernel::show() {
  imshow("Original image", image);
  imshow("blur image", result);
  waitKey(0);
}
Kernel::~Kernel() { destroyAllWindows(); }
int main() {
  Kernel k1;

  return 0;
}