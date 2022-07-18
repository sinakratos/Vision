#include "kernel.hpp"
#include <opencv4/opencv2/highgui.hpp>
#include <string>

Kernel::Kernel() {}
Kernel::~Kernel() { destroyAllWindows(); }

void Kernel::blurKernel() {

  image = imread("test.png", 0);
  Blur = (Mat_<float>(3, 3) << 0.0625, 0.125, 0.0625, 0.125, 0.25, 0.125,
          0.0625, 0.125, 0.0625);
  int dstRow = image.rows - Blur.rows + 1;
  int dstCol = image.cols - Blur.cols + 1;
  result = Mat(dstRow, dstCol, image.type());
  imshow("blur image", result);

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

void Kernel::showBlur() {
  imshow("Original image", image);
  imshow("blur image", result);
  waitKey(0);
}

void Kernel::makeBinaryImage(int thresholdingNumber) {
  result = Mat(grayImage.size(), CV_8UC1);
  for (int i = 0; i < grayImage.rows; i++)
    for (int j = 0; j < grayImage.cols; j++)
      if (grayImage.at<uchar>(i, j) > thresholdingNumber) {
        result.at<uchar>(i, j) = 255;
      } else {
        result.at<uchar>(i, j) = 0;
      }
}
void Kernel::BinaryThreshold(int thresholdingNumber) {
  cap.open(0);
  char check;
  if (!cap.isOpened()) {
    exit(0);
  }
  cout << thresholdingNumber << endl;
  while (true) {
    cap >> image;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    makeBinaryImage(thresholdingNumber);
    imshow("threshold", result);
    check = waitKey(1);
    if (check == 110) {
      break;
    } else if (check == 113) {
      exit(0);
    }
  }
  cap.release();
}