#pragma once

#include "ImageUtils.h"
#include <opencv.hpp>

using namespace cv;

class ProcessingContext {

public:
	Mat inputImage;
	Mat outputImage;
	double *inputImageMatrix;
	double *outputImageMatrix;
	fftw_complex *inputImageFFT;
	fftw_complex *outputImageFFT;
	fftw_complex *kernelFFT;
	int width;
	int height;
	Blur *blur;
};

