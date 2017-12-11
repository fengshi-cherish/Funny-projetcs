#ifdef _MSC_VER
#define _USE_MATH_DEFINES
#include <cmath>
#else
#include <math.h>
#endif
#include <opencv.hpp>
#include <iostream>
#include "fftw3.h"
#include "DeconvolutionTool.h"

using namespace std;
using namespace cv;

int main() {
	Mat input = imread("BlurExample1.jpg");
	/*if (input.data)
		cout << "11111" << endl;*/
	namedWindow("ÊäÈëÍ¼Ïñ", CV_WINDOW_AUTOSIZE);
	imshow("ÊäÈëÍ¼Ïñ", input);
	
	Blur* blur;
	double radius = 29.2;
	double quality = 29;
	double feather = 20;
	double strength = 0;
	int width = input.cols;
	int height = input.rows;

	FocusBlur* focusBlur = new FocusBlur();
	focusBlur->radius = radius;
	focusBlur->edgeFeather = feather;
	focusBlur->correctionStrength = strength;
	//Mat kernelImage = ImageUtils::buildKernelImage(focusBlur);

	blur = focusBlur;
	blur->smooth = quality;
	blur->mode = PREVIEW_GRAY;

	DeconvolutionTool* deconvolutionTool = new DeconvolutionTool();
	deconvolutionTool->initFFT(input);
	Mat output(input.rows, input.cols, CV_8UC3);
	deconvolutionTool->doDeconvolution(input, output, blur);

	/*namedWindow("1");
	imshow("1", kernelImage);*/
	
	
	waitKey(0);
	delete(deconvolutionTool);
	return 0;
}