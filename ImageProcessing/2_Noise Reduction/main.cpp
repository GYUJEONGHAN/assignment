#include <iostream>
#include <array>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>

using namespace cv;
using namespace std;
//string origin = "origin";
//string result = "region filling";
Mat SE = getStructuringElement(MORPH_CROSS, Size(3, 3), Point(1, 1));
Mat erosion, dilation;
Mat src;


void region_filling(int x, int y) {
  /* const Mat& src = input.getMat();
   output.create(src.size(), src.type());*/
  
  // Mat dst = output.getMat();
   Mat boundary = src - erosion;
   Mat bd_rv = ~boundary;
   Mat a;
   
    
   Mat av(342, 284, CV_8UC3, Scalar(0, 0, 0));
   cvtColor(av, a, COLOR_BGR2GRAY);
   rectangle(a, Point(x,y), Point(x,y), Scalar(255, 255, 255));
  
   for (int i = 0; i < 300; i++) {
       dilate(a, a, SE);    //dilation
       bitwise_and(a, bd_rv, a);
       imshow("In Progress..", a);
      //dilate(a, dil_img, SE, Point(-1,-1),i);
      //bitwise_and(img_inv, dil_img, dst);
      imshow("result", a);
      waitKey(1);
   }
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        destroyWindow("origin");
        region_filling(x, y);
    }
}
   
//클릭하면 region filling, opencv C++ Structure Element,


int main() {

   //Mat src = imread("C:\\Users\\sjang\\Desktop\\Profile.png", 0);
   Mat src = imread("/Users/gyujh/Desktop/Profile.png", IMREAD_GRAYSCALE);
    
   erode(src, erosion, Mat());
   dilate(src, dilation, Mat());

   Mat boundary = src - erosion;

   imshow("origin", boundary);
   setMouseCallback("origin", CallBackFunc, NULL);

    
   waitKey(0);
   return 0;
}

