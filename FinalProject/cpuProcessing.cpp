#include "cpuProcessing.h"

void cpuProcessing::initial()
{
	system("cls");
	cout << "Please enter the location of the photo you would like to analyse: ";
	cin >> sUserPhoto;
	cin.ignore(1, '\n');

	mCPUPhoto = imread(sUserPhoto);

	sWindowName = "Test";

	cout << "Width : " << mCPUPhoto.cols << endl;
	cout << "Height: " << mCPUPhoto.rows << endl;

	windowResize(mCPUPhoto);

	system("pause");

	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, dNewWidth, dNewHeight);
	imshow(sWindowName, mCPUPhoto);
	waitKey(0);
	destroyAllWindows();
}

void cpuProcessing::windowResize(Mat mOriginal)
{
	if (mOriginal.cols > 2000)
	{
		dNewWidth = mOriginal.cols / 4;
	}
	else if (mOriginal.cols > 1000)
	{
		dNewWidth = mOriginal.cols / 2;
	}
	else
	{
		dNewWidth = mOriginal.cols;
	}

	if (mOriginal.rows > 2000)
	{
		dNewHeight = mOriginal.rows / 4;
	}
	else if (mOriginal.rows > 1000)
	{
		dNewHeight = mOriginal.rows / 2;
	}
	else
	{
		dNewHeight = mOriginal.rows;
	}
}