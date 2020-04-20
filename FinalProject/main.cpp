#include <opencv2/opencv.hpp>

#include "cpuProcessing.h"
#include "socketProcessing.h"

using namespace cv;
using namespace std;

char cMainMenu;

cpuProcessing cpuStuff;

void displayMenu()
{
	while (true)
	{
		system("cls");
		cout << "- Please Enter the cooresponding letter of what action you would like to perform-" << endl;
		cout << "- A: Detect a broken CPU Pin" << endl;
		cout << "- B: Detect a broken Socket Pin" << endl;
		cout << "- C: Close the program" << endl;

		cin >> cMainMenu;
		cin.ignore(1, '\n');

		switch (cMainMenu)
		{
		case 'A':
		case 'a':
			//TODO: Complete Switch Case A
			cpuStuff.initial();
			break;
		case 'B':
		case 'b':
			//TODO: Complete Switch Case B
			break;
		case 'C':
		case 'c':
			exit(0);
		}
	}
}

int main()
{
	displayMenu();
}