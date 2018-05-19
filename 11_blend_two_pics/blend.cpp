#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    String img1( "/home/yang/opencv_example/11_blend_two_pics/lena.jpg" ); // by default
    String img2( "/home/yang/opencv_example/11_blend_two_pics/Gray_Image.jpg" );
    if( argc > 2)
    {
        img1 = argv[1];
	img2 = argv[2];
    }

    double alpha = 0.5; double beta; double input;
    Mat src1, src2, dst;

    cout << " Simple Linear Blender " << endl;
    cout << "-----------------------" << endl;
    cout << "* Enter alpha [0.0-1.0]: ";
    cin  >> input;

    // We use the alpha provided by the user if it is between 0 and 1
    if( input >= 0 && input <= 1 )
     { alpha = input; }

    src1 = imread( img1, 1 ); // Read the file
    src2 = imread( img2, 1 );

    if( src1.empty() ) { cout << "Error loading src1" << endl; return -1; }
    if( src2.empty() ) { cout << "Error loading src2" << endl; return -1; }
    beta = ( 1.0 - alpha );
    addWeighted( src1, alpha, src2, beta, 0.0, dst);

    namedWindow("blend",WINDOW_AUTOSIZE);
    imshow( "blend", dst);
    waitKey(0);

    return 0;
}
