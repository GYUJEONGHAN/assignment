#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

void myMedianFilter(InputArray input, OutputArray output, int windowSize){

    Mat input_ = input.getMat();
    Mat output_ = output.getMat();
    vector<uchar> vcs;
    uchar sample;
    uchar median;

    for(int y=0; y<output_.rows;y++) for(int x=0;x<output_.cols;x++){
        for(int s=-windowSize;s<=windowSize;s++) for(int t=-windowSize;t<=windowSize;t++)
        {
            sample = input_.at<uchar>(min(output_.rows-1,max(0,y+t)),min(output_.cols-1,max(0,x+s)));
            vcs.push_back(sample);
        }
        sort(vcs.begin(), vcs.end());
        median = vcs[vcs.size()/2];
        output_.at<uchar>(y,x)=median;
        vcs.clear();

    }
}

int main(int argc, const char * argv[]) {
    
    Mat input = imread("/Users/gyujh/Desktop/12.png",0);
    Mat output = input.clone();
    
    imshow("before medianfilter", input);
    myMedianFilter(input, output, 5);
    imshow("after medianfilter", output);
    waitKey();

    return 0;
}
