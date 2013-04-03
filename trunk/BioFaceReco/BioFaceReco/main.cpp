#include <iostream>
#include <opencv2\opencv.hpp>

#include "FaceFinder.h"

int main(int argc, char** argv) {
	
	FaceFinder ff;

	ff.findInFile("picture.jpg");

	//system("pause");
	cv::waitKey(0);
	return 0;
}