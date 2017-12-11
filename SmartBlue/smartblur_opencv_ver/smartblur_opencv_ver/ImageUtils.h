#pragma once
#ifdef _MSC_VER
#define _USE_MATH_DEFINES
#include <cmath>
#else
#include <math.h>
#endif
#include <opencv.hpp>
#include "fftw3.h"
#include "Blur.h"
#include "FocusBlur.h"
#include "ProcessingContext.h"


using namespace cv;
enum CurrentChannel {
	RED,
	GREEN,
	BLUE,
	GRAY
};


// Optimized version of pow(-1, x+y)
inline signed char centerFFTKoef(int x, int y) {
	return((x + y) & 1) == 0 ? 1 : -1;
	// return pow(-1, x+y);
	// return 1;
}

class ImageUtils {

public:
	static Mat buildKernelImage(const FocusBlur* focusBlur);
	/*static QImage* buildKernelImage(const MotionBlur* motionBlur);
	static QImage *buildKernelImage(const GaussianBlur* gaussianBlur);*/

	//static void fillInputMatrix(ProcessingContext *processingContext, const CurrentChannel channel);
	static void fillMatrixFromImage(ProcessingContext *processingContext, const CurrentChannel channel);
	static void fillImageFromMatrix(ProcessingContext *processingContext, const CurrentChannel channel);
};

