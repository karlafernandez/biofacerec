#include "FaceFinder.h"


FaceFinder::FaceFinder(void) {
	faces.clear();
}

FaceFinder::FaceFinder(std::string filename) {
	faces.clear();
	findInFile(filename);
	this->filename = filename;
}

FaceFinder::~FaceFinder(void)
{
	faces.clear();
}

void FaceFinder::findInFile(std::string filename) {
	
	std::vector<cv::Rect> facesRect;
	std::string classFilename(HAAR_FACE_CLASSIFIER);
	faces.clear();
	bool success = false;

	success = haarClassifier.load(classFilename);

	if(!success) {
		std::cout << "Wrong cascade classifier filename" << std::endl;
	} else {

		cv::Mat image = cv::imread(filename);

		cv::imshow("Original image", image);

		if(!image.empty()) {

			cv::Mat gray;
			cv::cvtColor(image, gray, CV_BGR2GRAY);
			cv::equalizeHist(gray, gray);

			haarClassifier.detectMultiScale(gray, facesRect, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE);

			for(int i = 0; i < facesRect.size(); i++) {
				cv::Mat faceROI = gray(facesRect[i]);
				this->faces.push_back(faceROI);

				std::stringstream ss;
				ss << "face" << i;
				cv::imshow(ss.str(), faceROI);
			}

		}

		
	}


}