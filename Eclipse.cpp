
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

string title = "Eclipse Practice";

void OnClicked(int event, int x, int y, int flag, void*data)
{

	bool* bClicked = (bool*)&data;
	*bClicked = true;
	const int n = EVENT_MBUTTONDOWN + EVENT_FLAG_MBUTTON;
	cout << "Event : " << event << "  " << "Flag:" << flag << endl;
	if (*bClicked)
	{
		switch (event + flag)
		{
		case  EVENT_MBUTTONDOWN + EVENT_FLAG_MBUTTON:
		{
			cout << "´­·¯Áü";
			Mat mm = Mat(300, 400, CV_8U);
			ellipse(mm, Point(x, y), Size(3, 3), 0, 0, 360, Scalar(100), 2);
			imshow(title, mm);
			break;

		}
		default:
			cout << "test :" << n << endl;

		}
	}
	else
		cout << "failed to click" << endl;

	

}
#if 0
int main()
{
	Mat m = Mat(300, 400, CV_8U);
	string namedWindow(title, WINDOW_NORMAL);
	bool bFlag = false;
	imshow(title, m);
	setMouseCallback(title, OnClicked, &bFlag);
	waitKey();
}
#endif