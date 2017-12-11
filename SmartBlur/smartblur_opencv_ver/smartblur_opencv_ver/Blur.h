#pragma once

enum ProcessMode {
	PREVIEW_GRAY,
	PREVIEW_COLOR,
	HIGH_QUALITY
};

class Blur
{
public:
	ProcessMode mode;
	double radius;
	double smooth;
	//const virtual String getName() const = 0;

};

