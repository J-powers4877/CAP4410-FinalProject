#include "cpuProcessing.h"

void cpuProcessing::initial()
{
	/*
	Clear the CMD Line
	Prompt User
	Wait for User Input
	*/
	system("cls");
	cout << "Please enter the location of the non-defective photo you would like to analyse: \n";
	cin >> sUserPhoto;
	cin.ignore(1, '\n');
	
	//Read User Photo as Grayscale into Mat object
	mCPUGoodPhoto = imread(sUserPhoto, IMREAD_GRAYSCALE);
	//Use OTSU Threshold on the User image
	threshold(mCPUGoodPhoto, mCPUGoodGray, 0, 255, THRESH_BINARY | THRESH_OTSU);
	
	//Prompt User for other Photo
	//Wait for User Input
	cout << "Please enter the location of the potentially defective photo you would like to analyse: \n";
	cin >> sUserPhoto;
	cin.ignore(1, '\n');
	
	//Read User Photo as Grayscale into Mat Object
	mCPUBadPhoto = imread(sUserPhoto, IMREAD_GRAYSCALE);
	//Use OTSU Threshold on the User image
	threshold(mCPUBadPhoto, mCPUBadGray, 0, 255, THRESH_BINARY | THRESH_OTSU);
	
	//If image is too large, resize the window to account for
	windowResize(mCPUGoodPhoto);
	//Run Bitwise XOR on images to get differences.
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
	
	//Display output
	sWindowName = "Output";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, dNewWidth, dNewHeight);
	imshow(sWindowName, mXOR);
	
	//Wait for input
	waitKey(0);
	//Close all windows
	destroyAllWindows();

	system("cls");

	//Prompt user for Save Feature
	cout << "Would you like to save the photo?" << endl;
	cout << "Y for yes; N for no." << endl;
	cin >> cUserSave;
	cin.ignore(1, '\n');

	//Switch case for user input
	switch (cUserSave)
	{
	case 'Y':
	case 'y':
		cout << "The image will be saved with the name Output.jpg" << endl;
		cout << "Please enter the location of the file location where you want the image saved at: " << endl;
		cin >> sUserFile;
		cin.ignore(1, '\n');

		//Add file name to location input by user
		sUserFile += "\\Output.JPG";
		imwrite(sUserFile, mXOR);

		printf("The photo was saved as %s .", sUserFile);
		system("pause");
	case 'N':
	case 'n':
		cout << "Image not saved." << endl;
		system("pause");
	}
}

//Used to resize oversized windows.
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