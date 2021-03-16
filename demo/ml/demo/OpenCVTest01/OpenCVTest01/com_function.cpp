#pragma once
#include "com_function.h"
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

namespace
{
	cv::Mat roi(
		const std::string& dst, 
		const std::string& src, 
		const cv::Rect& rect)
	{
		Mat result = imread(dst, IMREAD_UNCHANGED);
		return result;
	}
}