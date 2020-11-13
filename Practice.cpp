
#define OPEN_PRACTICE
#ifndef OPEN_PRACTICE
#else
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#endif




using namespace cv;
using namespace std;






#if 0
int main()

{
	
	VideoCapture capture;
	Mat Frame;
	VideoWriter vw;
	capture.open("C:\\Users\\1\\OneDrive\\바탕 화면\\새 폴더 (2)\\Test.avi");
	CV_Assert(capture.isOpened());

	float frame_rate = capture.get(5);
	int delay = 1000 / frame_rate;
	int frame_cnt = 0;
	Mat tmp;
	vector<int> params_jpg;


	while (capture.read(Frame))
	{

	

		
		if (frame_cnt < 50)
		{
			cout << "current frame cnt(100 below) :" << frame_cnt << endl;
		
			Frame -= Scalar(0, 0, 100);
		}
		else if (frame_cnt < 100)
		{
			cout << "current frame cnt(200 over) :" << frame_cnt << endl;
			Frame += Scalar(100, 0, 0);

		}

		else if(frame_cnt<150)
		{
			cout << "current frame cnt(300 over) :" << frame_cnt << endl;
	
			Frame = Frame * 0.05;

		}
		else if (frame_cnt < 200)
		{
			cout << "current frame cnt(400 over) :" << frame_cnt << endl;
		
			Frame = Frame * 0.05;

		}
		int nKey = waitKey(delay);
		if (waitKey(delay) == 0x1B)
		{
			cout << "종료" << endl;
			break;
		}
		else if (nKey == 's' || nKey == 'S')
		{

			cout << "sclicked" << endl;


			if (imwrite("C:\\Users\\1\\OneDrive\\바탕 화면\\새 폴더 (2)\\Sample.jpg", Frame))
			{
				cout << "저장" << endl;


			}
			else
				cout << "저장 실패" << endl;

			waitKey(100000);
		}
		
	
		frame_cnt++;
		imshow(titles, Frame);

	}
	return 0;
}

#endif
