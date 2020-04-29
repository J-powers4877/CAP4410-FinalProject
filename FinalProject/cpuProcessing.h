#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

class cpuProcessing
{
	Mat mCPUGoodPhoto;
	Mat mCPUBadPhoto;
	Mat mCPUGoodGray;
	Mat mCPUBadGray;
	Mat mXOR;

	string sUserPhoto;
	string sWindowName;
	string sUserFile;

	char cUserSave;

	double dNewWidth;
	double dNewHeight;

public:
	void initial();
	void windowResize(Mat mOriginal);
};