#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
//    String imageName( "/home/yang/opencv_example/6_load_modify_save/lena.jpg" ); // by default
//    if( argc > 1)
//    {
//        imageName = argv[1];
//    }

    char* imageName = argv[1];

    Mat image;
    image = imread( imageName, IMREAD_COLOR ); // Read the file
    if( argc !=2 || !image.data )                      // Check for invalid input
    {
        cout <<  "NO image data " << std::endl ;
        return -1;
    }

    Mat gray_image;
    cvtColor( image, gray_image, COLOR_BGR2GRAY );

    imwrite( "/home/yang/opencv_example/6_load_modify_save/Gray_Image.jpg", gray_image );

    namedWindow( "Gray image", WINDOW_AUTOSIZE );
    namedWindow( "Display window", WINDOW_AUTOSIZE ); 


    imshow( "Display window", image );                // Show our image inside it.
    imshow( "Gray image",gray_image);
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}
