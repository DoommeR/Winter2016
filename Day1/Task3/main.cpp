// DemoList.cpp : Defines the entry point for the console application.
//g++ DemoList.cpp Image.cpp List.cpp -o dl


#include "Image.h"
#include "List.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
//#include "Recognizer.h"


int main()
{
	
	std::vector<cv::Mat> stickers;
	cv::Mat image = cv::imread("stc.jpg");
	
	
	int tmp = getchar();


    return 0;
}

