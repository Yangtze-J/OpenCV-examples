#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    String imageName( "/home/yang/opencv_example/10_visualing_images/lena.jpg" ); // by default
    if( argc > 1)
    {
        imageName = argv[1];
    }

    Mat image = imread( imageName, IMREAD_COLOR ); // Read the file
    Mat grey;
    cvtColor( image, grey, COLOR_BGR2GRAY );

    Mat sobelx;
    Sobel(grey, sobelx, CV_32F, 1, 0);
    double minVal, maxVal;
    minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities
    Mat draw;
    sobelx.convertTo(draw, CV_8U, 255.0/(maxVal - minVal), -minVal * 255.0/(maxVal - minVal));

    namedWindow( "Display window", WINDOW_AUTOSIZE ); 
    imshow( "Display window", draw);                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}
