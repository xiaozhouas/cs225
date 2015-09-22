#include "rgbapixel.h"

// default construction with opaque and white
RGBAPixel::RGBAPixel()
{
	red = 255;
	green =255;
	blue = 255;
	alpha =255;
}
// with the user input RGB construction 
RGBAPixel::RGBAPixel(uint8_t red, uint8_t green, uint8_t blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	alpha = 255;
}