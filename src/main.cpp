#include <opencv2/opencv.hpp>
#define CVUI_IMPLEMENTATION
#include <iostream>
#include "../include/cvui.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "usage: cv_img_tools <Image_Path>\n";
    return -1;
  }

  cvui::init("Image");
  cv::Mat image = cv::imread(argv[1], 1);
  if (!image.data) {
    std::cout << "No image data.\n";
    return -1;
  }
  while (true) {
    cvui::text(image, 200, 200, "Hello, World!");
    cvui::imshow("Image", image);
    if (cv::waitKey(20) == 27) {
      break;
    }
  }
}
