#pragma once

#include "Blur.h"


class FocusBlur : public Blur
{
public:
	double edgeFeather;
	double correctionStrength;
	/*const String getName() const {
		return "FocusBlur";
	}*/
};
