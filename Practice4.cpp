#include "Practice.cpp"
#include <opencv2/imgproc/imgproc.hpp>
#ifdef OPEN_PRACTICE
#else
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#endif


using namespace std;
using namespace cv;
#if 0
Mat getAffineMap(Point2d center, double dgree, double fx = 1, double fy = 1,Point2d translate=Point(0,0))
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
#endif
#if 0
int main()
{

	Mat image = imread("C:\\Users\\1\\OneDrive\\바탕 화면\\구활금 자료\\Sample.jpg");
	CV_Assert(image.data);

	Point center = image.size() / 2;
	double angle = 45.0;
	Mat dst1;
	Mat aff_map1 = getAffineMap(center, angle);
	warpAffine(image, dst1, aff_map1, image.size());
	imshow("image", image);
	imshow("dst - rotation", dst1); 
	waitKey();


}
#endif