#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <math.h>


using namespace std;
using namespace cv;

Mat src;
Mat erosion, dilation;

void region_filling(int x, int y){
    Mat boundary = src - erosion;
    Mat bnd_reverse = ~boundary;
    Mat a, b;
    Mat mask = getStructuringElement(MORPH_CROSS, Size(3, 3), Point(1, 1));
    Mat av(342, 284, CV_8UC3, Scalar(0, 0, 0)); //같은 픽셀의 검은 화면 생성
    cvtColor(av, a, COLOR_BGR2GRAY); //binary 이미지로 변환
    rectangle(a, Point(x,y), Point(x,y), Scalar(255, 255, 255)); // 클릭한 곳에 사각형 그리기
    
    while(true){
        a.copyTo(b); //비교용 이미지 복사
        dilate(a, a, mask);    //dilation
        bitwise_and(a, bnd_reverse, a);   //boundary 이미지의 여집합과 교차점 탐색
        imshow("In Progress..", a);
        if (sum(a) == sum(b)) //비교하여 같다면 region filling 중단
        {
            break;
        }
        waitKey(1);
    }
    destroyWindow("In Progress..");
    imshow("Done", boundary + a); //경계선과 합치기
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        destroyWindow("boundary");
        region_filling(x, y);
    }
}

int main(){
    src = imread("/Users/gyujh/Desktop/Profile.png", IMREAD_GRAYSCALE);
    if(src.empty()){
        cout << "이미지를 열 수 없습니다." << endl;
        return -1;
    }
    
    erode(src, erosion, Mat());
    dilate(src, dilation, Mat());

    Mat boundary = src - erosion;
    imshow("boundary", boundary);
    setMouseCallback("boundary", CallBackFunc, NULL);
    waitKey(0);

    return 0;
}
