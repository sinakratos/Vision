#include "threshold.hpp"

Threshold::Threshold() {}
Threshold::~Threshold() { destroyAllWindows(); }

void Threshold::makeBinaryImage(int thresholdingNumber) {
  result = Mat(grayImage.size(), CV_8UC1);
  for (int i = 0; i < grayImage.rows; i++)
    for (int j = 0; j < grayImage.cols; j++)
      if (grayImage.at<uchar>(i, j) > thresholdingNumber) {
        result.at<uchar>(i, j) = 255;
      } else {
        result.at<uchar>(i, j) = 0;
      }
}
void Threshold::BinaryThreshold() {
  int thresholdingNumber = 50;
  cap.open(0);
  char check;
  if (!cap.isOpened()) {
    return;
  }
  cv::namedWindow("Binary", WINDOW_AUTOSIZE);
  cv::createTrackbar("Threshold number", "Binary", &thresholdingNumber, 255);
  while (true) {
    cap >> image;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    makeBinaryImage(thresholdingNumber);
    imshow("Binary", result);
    check = waitKey(1);
    if (check == 110) {
      break;
    } else if (check == 113) {
      exit(0);
    }
  }
  cap.release();
}