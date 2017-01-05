// OpenCVprj.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

#include <iostream>

using namespace cv;
using namespace std;

int main(int, char**) {
	VideoCapture cap("video.MOV"); // Открываем камеру или файл

	if(!cap.isOpened())     // check if we succeeded
		return -1;
	
	double fps = cap.get(CV_CAP_PROP_FPS);     //get the frames per seconds of the video 
	std::cout << "Frame per seconds : " << fps << std::endl; 
	namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"   
	
	
	int trd = 200;
	
	Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_STD);
	
	while (1)
	{
		Mat frame;
		vector<Vec4f> lines_std;
		//Mat edges;
		Mat gray_img;
		bool bSuccess = cap.read(frame); // read a new frame from video 
		if (!bSuccess)
		{
			std::cout << "Cannot read the frame from video file" << std::endl;
			break;
		}
		
		double start = double(getTickCount());

		cvtColor(frame, gray_img, COLOR_BGR2GRAY);
		//Canny(frame, frame, trd*0.4, trd, 3);
		ls->detect(gray_img, lines_std);

		double duration_ms = (double(getTickCount()) - start) * 1000 / getTickFrequency();
		std::cout << "It took " << duration_ms << " ms." << std::endl;

		//ls->drawSegments(frame, lines_std);

		resize(frame, frame, Size(800, 600));
		imshow("MyVideo", frame); //show the frame in "MyVideo" window   
		
		if (waitKey(30) == 27)
		{
			break;
		}
	}
}