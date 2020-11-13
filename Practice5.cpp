#include <opencv2\/opencv.hpp>
using namespace std;
using namespace cv;



Mat make_palatte(int rows)
{
	Mat hsv(rows, 1, CV_8UC3);
	for (int i = 0; i < rows; i++)
	{
		uchar hue = saturate_cast<uchar>((float)i / rows * 180);
		hsv.at<Vec3b>(i) = Vec3b(hue, 255, 255);
	
	}
	cvtColor(hsv, hsv, COLOR_HSV2BGR);

	return hsv;
}
void draw_histo_hue(Mat hist, Mat& hist_img, Size size = Size(256, 200))
{
	Mat hsv_palatte = make_palatte(hist.rows);

	hist_img = Mat(size, CV_8UC3, Scalar(255, 255, 255));// hist_img가 최종적으로 그려지는 Mat

	float bin =(float) hist_img.cols / hist_img.rows+10; //그래프 간격.
	normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);
	for (int i = 0; i < hist.rows; i++)
	{
		float start_x = i * bin;
		float end_x = (i + 1) * bin;
		Point2f pt1(start_x, 0);
		Point2f pt2(end_x, hist.at<float>(i));
		
		Scalar color = hsv_palatte.at<Vec3b>(i);
		if (pt2.y > 0)
		{
			rectangle(hist_img, pt1, pt2,color, -1);
		}

	
	}
	flip(hist_img, hist_img, 0);

	imshow("draw_hist", hsv_palatte);
}



void calc_histo(Mat image, Mat& hist, int bins, int range_max = 256)
{

	hist = Mat(bins, 1, CV_32F, Scalar(0));

	float gap = range_max / bins;
	for (int i = 0; i < image.rows; i++)
	{

		for (int j = 0; j < image.cols; j++)
		{
			int idx = image.at<uchar>(i, j) / gap;
			hist.at<float>(idx)++;
		}
	}
}

void draw_hist(Mat hist, Mat& hist_img)
{
	hist_img = Mat(Size(256, 200), CV_8U, Scalar(255));
	float bin = hist_img.cols / hist_img.rows; //그래프 간격.
	normalize(hist, hist, 0,hist_img.rows, NORM_MINMAX);
	for (int i = 0; i < hist.rows; i++)
	{
		float start_x = i * bin;
		float end_x = (i + 1) * bin;
		Point2f pt1(start_x, 0);
		Point2f pt2(end_x, hist.at<float>(i));
		if (pt2.y > 0)
		{
			rectangle(hist_img, pt1, pt2, Scalar(0), -1);
		}
		

	}
	flip(hist_img, hist_img, 0);

}
	int main()
	{
		Mat img = imread("C:\\Users\\1\\OneDrive\\바탕 화면\\Materials\\test2.jpg", 1);
	

		CV_Assert(img.data);
		Mat HSV_img, HSV_arr[3];
		cvtColor(img, HSV_img, COLOR_BGR2HSV);
		split(HSV_img, HSV_arr);// HSV 색상으로 바꾸고 채널 분리
		
		Mat hue_hist, hue_hist_img;
		calc_histo(HSV_arr[0], hue_hist, 18, 180);//뭔지는 모르겠지만 B->H에 대한 채널값을 히스토 계싼
		draw_histo_hue(hue_hist, hue_hist_img, Size(360, 200));

		imshow("img", img);
		imshow("hue_hist_img", hue_hist_img);
	
		waitKey();


	}
	


