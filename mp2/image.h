#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <png.h>

// c++ style includes
#include <string>
#include <iostream>
#include <sstream>

// local includes
#include "rgbapixel.h"
#include "png.h"

//image is a subclass of PNG and extends the functionality of PNG
class Image : public PNG
{
public:
	//default construction function
	// Image();
	// Image(size_t width, size_t height) :PNG( width,  height){};

	//Flips the image about a vertical line through its center by swapping pixels.
	void flipleft();

	//Adds to the red, green, and blue parts of each pixel in the image.
	void adjustbrightness(int r, int g, int b);

	//Makes each RGB component of each pixel iequal to 255 minus its original valu.
	void invertcolors();

};
#endif