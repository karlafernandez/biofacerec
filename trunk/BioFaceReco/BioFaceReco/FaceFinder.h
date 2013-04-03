#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <opencv2\opencv.hpp>
#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\highgui\highgui.hpp>

const static char* HAAR_FACE_CLASSIFIER = "haarcascades\\haarcascade_frontalface_default.xml";

class FaceFinder
{
public:
	FaceFinder(void);
	FaceFinder(std::string filename);
	~FaceFinder(void);
	void findInFile(std::string filename);

	std::string getCurrentFilename() const;
	std::vector<cv::Mat> getFacesVector() const;

private:
	
	cv::CascadeClassifier haarClassifier;
	std::vector<cv::Mat> faces;
	std::string filename;

};

inline std::string FaceFinder::getCurrentFilename() const {
	return filename;
}

inline std::vector<cv::Mat> FaceFinder::getFacesVector() const {
	return faces;
}
