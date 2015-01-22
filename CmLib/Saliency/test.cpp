/*
 * test.cpp
 *
 */
#include <opencv2/opencv.hpp>
#define CV_VERSION_ID CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)
#define cvLIB(name) lnkLIB("opencv_" name CV_VERSION_ID)

#pragma comment( lib, cvLIB("core"))
#pragma comment( lib, cvLIB("imgproc"))
#pragma comment( lib, cvLIB("highgui"))
#pragma comment(lib, cvLIB("contrib"))
using namespace cv;

#include "CmSalCut.h"

using namespace std;

int main() {
    string imagePath = "/Users/pihatonttu/matlab/straw.jpg";
    string outPath = "/Users/pihatonttu/git/CmCode/straws.jpg";
    string outPath2 = "/Users/pihatonttu/git/CmCode/strawss.jpg";
    CmSalCut::Run(imagePath, outPath, outPath2);
}


