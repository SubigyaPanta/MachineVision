#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include <opencv/cv.hpp>
#include <opencv2/core.hpp>
#include "libfreenect.hpp"

using namespace std;
using namespace cv;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Mat image;
    image = imread("../facial_landmarks.jpg", 1);
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);

    return 0;
}