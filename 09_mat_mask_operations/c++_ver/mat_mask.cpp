#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

static void help(char* progName)
{
    cout << endl
        <<  "This program shows how to filter images with mask: the write it yourself and the"
        << "filter2d way. " << endl
        <<  "Usage:"                                                                        << endl
        << progName << " [image_path -- default ../lena.jpg] [G -- grayscale] "        << endl << endl;
}

void Sharpen(const Mat& myImage, Mat& Result);

int main(int argc ,char* argv[])
{
    help(argv[0]);
    // const char* filename = argc >=2? argv[1] : "~/opencv_example/9_mat_mask_operations/c++_ver/lena.jpg"; 
    const char* filename = argc >=2? argv[1] : "../lena.jpg"; 
    Mat src, dst0, dst1;
    if(argc >= 3 && !strcmp("G" , argv[2])) 
	src = imread(filename, 0);
    else
	src = imread(filename, 1);

    if(src.empty())
    {
	cerr << "Cannot open image " << endl;
	return -1;
    }

    namedWindow("Input image", WINDOW_AUTOSIZE);
    namedWindow("Ouput image", WINDOW_AUTOSIZE);



}
