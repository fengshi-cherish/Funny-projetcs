#pragma once
#ifdef _MSC_VER
#define _USE_MATH_DEFINES
#include <cmath>
#else
#include <math.h>
#endif
#include <opencv.hpp>
#include "ImageUtils.h"
#include "ProcessingContext.h"
#include "fftw3.h"

using namespace std;
using namespace cv;

class DeconvolutionTool{
public:
	DeconvolutionTool();
	~DeconvolutionTool();
	void initFFT(const InputArray inputImage);
	bool doDeconvolution(InputArray inputImage, OutputArray OutputImage, Blur *blur);
	//int getThreadsCount();
	static void visualizeFFT(fftw_complex *fft, const int WIDTH, const int HEIGHT, String path);
	static void buildKernel(double* outKernelFFT, const int WIDTH, const int HEIGHT, const Blur* blur);
	static void multiplayRealFFTs(fftw_complex *outFFT, const fftw_complex *kernelFFT, const int width, const int height);
	void cancelProcessing();
	void setTVIterationsCount(int value);
	void setPreviewMethod(int value);

//signals:
//	void progressEvent(int, QString);

private:
	void removeFFTObjects();
	/*void setProgressInterval(int begin, int end, String text);
	void setProgressSubValue(int percentValue);*/
	void deconvolutionByWiener(ProcessingContext* processingContext);
	void deconvolutionByTikhonov(ProcessingContext *processingContext);
	void deconvolutionByTotalVariationPrior(ProcessingContext *processingContext);

	void buildLaplacian(fftw_complex* outLaplacianFFT, const int WIDTH, const int HEIGHT);
	void doDeconvolutionForChannel(ProcessingContext* processingContext, const CurrentChannel channel);

	volatile bool isProcessingCancelled;

	int beginCurrentProgress, endCurrentProgress;
	String currentProgressText;

	int width, height;
	int threadsCount;
	int tvIterationsCount;
	int previewMethod;

	double *inputImageMatrix;
	double *outputImageMatrix;
	double *kernelMatrix;

	fftw_complex *inputImageFFT;
	fftw_complex *outputImageFFT;
	fftw_complex *kernelFFT;
	fftw_complex *kernelTempFFT;

	fftw_plan realForwardPlan;
	fftw_plan realBackwardPlan;
	fftw_plan realForwardKernelPlan;
	fftw_plan forwardLaplacianPlan;
	fftw_plan backwardLaplacianPlan;

	double *laplacianMatrix;
	double *outLaplacianMatrix;
	fftw_complex *laplacianMatrixFFT;
};