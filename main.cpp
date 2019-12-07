#include <opencv2/opencv.hpp>
#include <stdlib.h> 
#include <time.h>

bool operator== (const cv::Vec3b& v1, const cv::Vec3b& v2) {
	return v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2] ? true : false;
}
int main() {
	cv::Mat backgrd(500,1000,CV_8UC3,cv::Scalar(0,0,0));
	cv::namedWindow("Out", cv::WINDOW_AUTOSIZE);
	srand(time(NULL));

	int x = rand() % 1000;
	int y = rand() % 500;
	int dx =1;
	int dy =1;
	cv::Vec3b white(255,255,255);
	cv::Vec3b black(0,0,0);

	while (1) {
		if (y+dy < 0 || y+dy > 499) dy = -dy;
		if (x+dx < 0 || x+dx > 999) dx = -dx;
		x += dx;
		y += dy;
		backgrd.at<cv::Vec3b>(y, x) = backgrd.at<cv::Vec3b>(y, x) == black ? white : black;
		cv::imshow("Out", backgrd);
		cv::waitKey(30);
	}
	return 0;
}