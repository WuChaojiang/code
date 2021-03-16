// OpenCVTest01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int testRoi();

int main()
{
    //Mat image = Mat::zeros(300, 600, CV_8UC3);
    //circle(image, Point(300, 200), 100, Scalar(0, 255, 128), -100);
    //circle(image, Point(400, 200), 100, Scalar(255, 255, 255), -100);
    //imshow("Show Window", image);
    //waitKey(0);

	testRoi();
	return 0;
	std::string filename1 = "d:\\P002.jpg";
	Mat img = imread(filename1, IMREAD_UNCHANGED);
	if (img.empty())
	{
		printf("Could not find the image!\n");
		return -1;
	}

	//imshow("ImputImage", img);
	imshow("ImputImage", img);
	
	int nc = img.channels();
	int heigth = img.rows;
	int width = img.cols;

	for (int row=100; row <= 150; row++)
	{
		for (int col = 100; col <= 150; col++)
		{
			img.at<Vec3b>(row, col)[0] = 255;
			img.at<Vec3b>(row, col)[1] = 255;
			img.at<Vec3b>(row, col)[2] = 255;
		}
	}

	imshow("result", img);

	waitKey(0);
	destroyAllWindows();

	//保存文件
	imwrite("d:\\P002_1.jpg", img);

    return 0;
}

int testRoi() 
{
	Mat image1 = imread("1.jpg");
	Mat image2 = imread("3.jpg");
	if (!image1.data)
	{
		printf("第一张图片读取失败!\n");
		return -1;
	}
	imshow("image1", image1);
	if (!image2.data)
	{
		printf("第二张图片读取失败!\n");
		return -1;
	}
	imshow("image3", image2);

	//定义一个Mat类型并设置ROI区域  
	Mat imageROI = image1(Rect(10, 10, image2.cols, image2.rows));

	//加载掩码  
	Mat mask = imread("3.jpg");

	//将掩码复制到ROI  
	image2.copyTo(imageROI, mask);
	imshow("利用ROI实验窗口叠加", image1);
	waitKey();
	destroyAllWindows();
	
	return 0;
}