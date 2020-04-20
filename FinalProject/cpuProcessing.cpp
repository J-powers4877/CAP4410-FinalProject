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

	system("pause");

	namedWindow(sWindowName, WINDOW_KEEPRATIO);
	resizeWindow(sWindowName, mCPUPhoto.cols, mCPUPhoto.rows);
	imshow(sWindowName, mCPUPhoto);
	waitKey(0);
	destroyAllWindows();
}

int cpuProcessing::windowResize(Mat mOriginal)
{

}