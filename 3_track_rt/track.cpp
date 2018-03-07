#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstring> 

using namespace std;
using namespace cv;

int main() {  
    // declares all required variables  
    //! [vars]  
    Rect2d roi;  
    Mat frame;  
    //! [vars]  
  
    // create a tracker object  
    Ptr<Tracker> tracker = TrackerKCF::create();   
    //! [create]  
  
    // set input video  
    //! [setvideo]  
    //std::string video = "/home/cuoid/kcfDemo/demo1/vtest.avi";  
    //VideoCapture cap(video);
    VideoCapture cap(0);
    //! [setvideo]  
  
    // get bounding box  
    //! [getframe]  
    cap >> frame;  
    //! [getframe]  
    //! [selectroi]选择目标roi以GUI的形式
    if(!frame.empty()){
        roi=selectROI("tracker",frame);
    }  
    //! [selectroi]  
  
    //quit if ROI was not selected  
    if (roi.width == 0 || roi.height == 0)  
        return 0;  
  
    // initialize the tracker  
    //! [init]  
    tracker->init(frame, roi);  
    //! [init]  
  
    // perform the tracking process  
    printf("Start the tracking process\n");  
    for (;; ) {  
        // get frame from the video  
        cap >> frame;  
        // stop the program if no more images  
        if (frame.rows == 0 || frame.cols == 0)  
            break;  
  
        // update the tracking result  
        //! [update]  
        tracker->update(frame, roi);  
        //! [update]  
  
        //! [visualization]  
        // draw the tracked object  
        rectangle(frame, roi, Scalar(255, 0, 0), 2, 1);  
  
        // show image with the tracked object
        if(!frame.empty()){
            imshow("tracker",frame);
	}  
        //! [visualization]  
        //quit on ESC button  
        if (waitKey(1) == 27)  
            break;  
    }  
  
    return 0;  
}
