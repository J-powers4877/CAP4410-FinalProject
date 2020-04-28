#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

class cpuProcessing
{
	Mat mCPUPhoto;

	string sUserPhoto;
	string sWindowName;

	double dNewWidth;
	double dNewHeight;

public:
	void initial();
	void windowResize(Mat mOriginal);
};