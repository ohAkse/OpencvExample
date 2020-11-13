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
int main()
{
	Mat img = imread("C:\\Users\\1\\OneDrive\\바탕 화면\\Materials\\Test.png", IMREAD_COLOR);
	if (img.empty())
	{
		cout << "경로를 확인" << endl;
	}
	
	Mat arrChannels[3], red_img, blue_img, green_img;

    Scalar red_color = Scalar(255, 0, 0);


    bitwise_and(img, red_color, img);

    imshow("img", img);
   
    split(img, arrChannels);//arrChannels={b,g,r}
   

    bitwise_not(arrChannels[2], arrChannels[2]);
    imshow("arrChannels[2]", arrChannels[2]);
    
    
    Mat FillMatrix=FillMatrix.ones(arrChannels[0].size(), CV_8UC1);//0으로 채울 matrix
	Mat R[] = { FillMatrix,FillMatrix,arrChannels[2]};//빨간색인 부분 다시 복원. 
	merge(R, 3,arrChannels[2]);

    Mat d;
  
   
	int from_to[] = { 0,2,1,1,2,0 };
	Mat red_tmp(arrChannels[0].size(),CV_8UC3);

	

	
	
	
	
//	imshow("red_tmp", arrChannels[0]);



	waitKey();
	return 0;
}
#endif
#if 0
int main(int argc, char* argv[]) {
    // load an image
    cv::Mat lena = imread("C:\\Users\\1\\OneDrive\\바탕 화면\\Materials\\Test.png", IMREAD_COLOR);

    // create a matrix for split
    cv::Mat bgr[3];

    // create a zero matrix
    cv::Mat zFillMatrix = cv::Mat::ones(lena.size(), CV_8UC1);
        // split image into 3 single-channel matrices
     imshow("original", lena);

    for (int i = 0; i < lena.rows; i++)
    {

        for (int j = 0; j < lena.cols; j++)
        {

     

            if ((lena.at<Vec3b>(i, j)[0] == 255 && lena.at<Vec3b>(i, j)[1] == 0 && lena.at<Vec3b>(i, j)[2] == 0))//파란색
            {
                lena.at<Vec3b>(i, j)[0] = 250;
                lena.at<Vec3b>(i, j)[1] = 0;
                lena.at<Vec3b>(i, j)[2] = 00;
   
            }
            else if ((lena.at<Vec3b>(i, j)[0] == 0 && lena.at<Vec3b>(i, j)[1] == 255 && lena.at<Vec3b>(i, j)[2] == 0))//녹색
            {
                lena.at<Vec3b>(i, j)[0] = 0;
                lena.at<Vec3b>(i, j)[1] = 250;
                lena.at<Vec3b>(i, j)[2] = 0;
            }
      
            else if ((lena.at<Vec3b>(i, j)[0] == 0 && lena.at<Vec3b>(i, j)[1] == 0 && lena.at<Vec3b>(i, j)[2] == 255))//빨간색
            {

                lena.at<Vec3b>(i, j)[0] = 0;
                lena.at<Vec3b>(i, j)[1] = 0;
                lena.at<Vec3b>(i, j)[2] = 250;
            }
            else
            {
                lena.at<Vec3b>(i, j)[0] = 0;
                lena.at<Vec3b>(i, j)[1] = 0;
                lena.at<Vec3b>(i, j)[2] = 0;
            }


            
        }
    }
   // cout << lena;
   

    cv::split(lena, bgr);


    // create 3 channel Color Matrix
    cv::Mat R[] = { zFillMatrix, zFillMatrix, bgr[2] };
    cv::Mat G[] = { zFillMatrix, bgr[1], zFillMatrix };
    cv::Mat B[] = { bgr[0], zFillMatrix, zFillMatrix };
    cv::merge(R, 3, bgr[2]);
    cv::merge(G, 3, bgr[1]);
    cv::merge(B, 3, bgr[0]);

    // create 3 windows
   
    cv::namedWindow("Red Channel");
    cv::namedWindow("Green Channel");
    cv::namedWindow("Blue Channel");

    // show 3 windows

    cv::imshow("Red Channel", bgr[2]);  // caution : the red channel index is 2!
    cv::imshow("Green Channel", bgr[1]);
    cv::imshow("Blue Channel", bgr[0]);

    cv::waitKey(0);
    return 0;
}
#endif