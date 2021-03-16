#pragma once
#include <string>
#include <opencv2/core/core.hpp>

namespace
{
	cv::Mat roi(
		const std::string& dst, 
		const std::string& src,
		const cv::Rect& rect );
}
