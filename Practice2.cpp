#include "Practice.cpp"
#include <opencv2/imgproc/imgproc.hpp>
#ifdef OPEN_PRACTICE
#else
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#endif


#if 0
#include <conio.h>
using namespace std;
using namespace cv;
#define EXPAND_SIZE 100

void Rotation(Mat img, Mat& dst, double degree, Point pt)
{

	double radian = degree / 180 * CV_PI;
	double sin_value = sin(radian);
	double cos_value = cos(radian);

	Rect rect(Point(0, 0), img.size());
	dst = Mat(img.size(), img.type(), Scalar(255));
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			int jj = j - pt.x;
			int ii = i - pt.y;
			double x = jj * cos_value + ii * sin_value;
			double y = -jj * sin_value + ii * cos_value;


		}

}

}


Mat getAffineMap(Point2d center, double dgree, double fx = 1, double fy = 1, Point2d translate = Point(0, 0))
{

	Mat rot_map = Mat::eye(3, 3, CV_64F);
	Mat center_trans = Mat::eye(3, 3, CV_64F);
	Mat org_trans = Mat::eye(3, 3, CV_64F);
	Mat scale_map = Mat::eye(3, 3, CV_64F);
	Mat trans_map = Mat::eye(3, 3, CV_64F);
	float theta = dgree * CV_PI / 180;
	rot_map.at<double>(0, 0) = cos(theta);
	rot_map.at<double>(0, 1) = sin(theta);
	rot_map.at<double>(1, 0) = -sin(theta);
	rot_map.at<double>(1, 1) = cos(theta);


	center_trans.at<double>(0, 2) = center.x;
	center_trans.at<double>(1, 2) = center.y;
	org_trans.at<double>(0, 2) = -center.x;
	org_trans.at<double>(1, 2) = -center.x;


	scale_map.at<double>(0, 0) = fx;
	scale_map.at<double>(1, 1) = fy;
	trans_map.at<double>(0, 2) = translate.x;
	trans_map.at<double>(1, 2) = translate.y;
	Mat ret_map = center_trans * rot_map * trans_map * scale_map * org_trans;
	ret_map.resize(2);

	return ret_map;

}


int main()
{


    VideoCapture capture(0);

    if (!capture.isOpened()) {

        cout << "doesn't open\n";

        return 0;

    }


    Size size = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));

    cout << "Size = " << size << endl;


    imshow("frame", NULL);

    waitKey(100);


    int delay = 30;

    int frameNum = -1;

    Mat frame;

    namedWindow("frame", WINDOW_AUTOSIZE);

   namedWindow("expand", WINDOW_AUTOSIZE);


    int afterExpand_w = (int)capture.get(CAP_PROP_FRAME_WIDTH);

    int afterExpand_h = (int)capture.get(CAP_PROP_FRAME_HEIGHT);

    int expand = 0;


    Mat cutVideoPlay;

    Mat realCutVideoPlay;
  

    while (1) {

        capture >> frame;

        if (frame.empty()) {

            cout << "don't play video\n";

            return 0;

        }

        imshow("frame", frame);
        int b = _kbhit();

        if (_kbhit()) {

            char kb = _getch();
            cout << "ASD";
            if (kb == '+') {

                afterExpand_h -= EXPAND_SIZE;

                afterExpand_w -= EXPAND_SIZE;


                if ((afterExpand_h <= 0) || (afterExpand_w <= 0)) {

                    afterExpand_h += EXPAND_SIZE;

                    afterExpand_w += EXPAND_SIZE;

                }

                cout << afterExpand_w << " " << afterExpand_h << endl;

            }

            else if (kb == '-') {

                afterExpand_h += EXPAND_SIZE;

                afterExpand_w += EXPAND_SIZE;


                if ((afterExpand_h > capture.get(CAP_PROP_FRAME_HEIGHT)) ||

                    (afterExpand_w > capture.get(CAP_PROP_FRAME_WIDTH))) {

                    afterExpand_h -= EXPAND_SIZE;

                    afterExpand_w -= EXPAND_SIZE;

                }

                cout << afterExpand_w << " " << afterExpand_h << endl;

            }

            expand = 1;

        }


        if (expand == 1) {

            if ((afterExpand_h == capture.get(CAP_PROP_FRAME_HEIGHT)) ||

                (afterExpand_w == capture.get(CAP_PROP_FRAME_WIDTH))) {

                realCutVideoPlay = frame;

            }

            else {

                Rect cutVideoRange(EXPAND_SIZE, EXPAND_SIZE, afterExpand_w, afterExpand_h);

                Mat cutVideo = frame(cutVideoRange);

                resize(cutVideo, cutVideoPlay, Size(), (capture.get(CAP_PROP_FRAME_WIDTH) / afterExpand_w),

                    (capture.get(CAP_PROP_FRAME_HEIGHT) / afterExpand_h));

                realCutVideoPlay = cutVideoPlay;

            }

            imshow("expand", realCutVideoPlay);

        }

        waitKey(delay);

    }

    return 0;

}
#endif