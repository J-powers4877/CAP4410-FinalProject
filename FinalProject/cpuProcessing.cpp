#include "cpuProcessing.h"

void cpuProcessing::initial()
{
	system("cls");
	cout << "Please enter the location of the non-defective photo you would like to analyse: ";
	cin >> sUserPhoto;
	cin.ignore(1, '\n');
	
	mCPUGoodPhoto = imread(sUserPhoto, IMREAD_GRAYSCALE);
	threshold(mCPUGoodPhoto, mCPUGoodGray, 128, 255, THRESH_BINARY | THRESH_OTSU);
	
	cout << "Please enter the location of the potentially defective photo you would like to analyse: ";
	cin >> sUserPhoto;
	cin.ignore(1, '\n');
	
	mCPUBadPhoto = imread(sUserPhoto, IMREAD_GRAYSCALE);
	threshold(mCPUBadPhoto, mCPUBadGray, 128, 255, THRESH_BINARY | THRESH_OTSU);
	
	windowResize(mCPUGoodPhoto);
	bitwise_xor(mCPUGoodGray, mCPUBadGray, mXOR);
	
	system("pause");
	
	//Delete comments to view all steps.
	//sWindowName = "Original";
	//namedWindow(sWindowName, WINDOW_NORMAL);
	//resizeWindow(sWindowName, dNewWidth, dNewHeight);
	//imshow(sWindowName, mCPUGoodPhoto);
	//sWindowName = "Original";
	//namedWindow(sWindowName, WINDOW_NORMAL);
	//resizeWindow(sWindowName, dNewWidth, dNewHeight);
	//imshow(sWindowName, mCPUBadPhoto);
	//
	//sWindowName = "Gray";
	//namedWindow(sWindowName, WINDOW_NORMAL);
	//resizeWindow(sWindowName, dNewWidth, dNewHeight);
	//imshow(sWindowName, mCPUGoodGray);
	//sWindowName = "Gray";
	//namedWindow(sWindowName, WINDOW_NORMAL);
	//resizeWindow(sWindowName, dNewWidth, dNewHeight);
	//imshow(sWindowName, mCPUBadGray);
	
	sWindowName = "Output";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, dNewWidth, dNewHeight);
	imshow(sWindowName, mXOR);
	
	waitKey(0);
	destroyAllWindows();

	cout << "Would you like to save the photo?" << endl;
	cout << "Y for yes; N for no." << endl;
	cin >> cUserSave;
	cin.ignore(1, '\n');

	switch (cUserSave)
	{
	case 'Y':
	case 'y':
		cout << "Please enter the location of the file location where you want the image saved at:";
		cin >> sUserFile;
		cin.ignore(1, '\n');

		sUserFile += "\\Output.JPG";
		imwrite(sUserFile, mXOR);

		printf("The photo was saved as %s .", sUserFile);
		system("pause");
	}
}

void cpuProcessing::windowResize(Mat mOriginal)
{
	if (mOriginal.cols < mOriginal.rows)
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
	else
	{
		if (mOriginal.cols > 2000)
		{
			dNewWidth = mOriginal.cols / 3;
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
			dNewHeight = mOriginal.rows / 3;
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
}