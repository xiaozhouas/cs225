//include the header file
#include "image.h"
#include <iostream>
using namespace std;

//Flips the image about a vertical line through its center by swapping pixels.
void Image::flipleft()
{
	
	int height = this->height();
	int width = this->width();
	//PNG copy(*this);
	// Image copy;
	// copy.resize(width,height);
	for (int y = 0; y < height; y++ )
	{
		for (int x =0; x < width/2; x++)
		{
			RGBAPixel myPixel = *(*this)(x,y);
			*(*this)(x,y) = *(*this)(width-x-1,y);
			*(*this)(width-x-1,y) = myPixel;
			// *copy(x,y) = *(*this)(x,y);
			//*(*this)(x,y) = *copy(width-1-x, y);
		}
	}
	// for (int y = 0; y < height; y++ )
	// {
	// 	for (int x =0; x < width; x++)
	// 	{
			
	// 		*(*this)(x,y) = *copy(width-1-x, y);
	// 	}
	// }

} 
//Makes each RGB component of each pixel iequal to 255 minus its original valu.
void Image::invertcolors()
{
	int height = this->height();
	int width = this->width();

	for (int y = 0; y < height; y++ )
	{
	for (int x =0; x < width; x++)
		{
			(*this)(x,y)->red = 255 -(*this)(x,y)->red;
			(*this)(x,y)->green = 255 -(*this)(x,y)->green;
			(*this)(x,y)->blue = 255 -(*this)(x,y)->blue;

		}
	}



}
//Adds to the red, green, and blue parts of each pixel in the image.
void Image::adjustbrightness(int r, int g, int b)
{
	int height = this->height();
	int width = this->width();

	for (int y = 0; y < height; y++ )
	{
	for (int x =0; x < width; x++)
		{	
			//check the if it is the case of over flow for red
			if ((*this)(x,y)->red +r >=0 && (*this)(x,y)->red +r <=255 )
			{
				(*this)(x,y)->red = (*this)(x,y)->red +r;
			}
			else if ((*this)(x,y)->red +r < 0 )
			{
				(*this)(x,y)->red = 0;
			}
			else if ((*this)(x,y)->red +r > 255 )
			{
				(*this)(x,y)->red = 255;
			}

			//same thing again for green	
			if ((*this)(x,y)-> green+g >=0 && (*this)(x,y)->green +g <=255 )
			{
				(*this)(x,y)->green = (*this)(x,y)->green +g;
			}
			else if ((*this)(x,y)->green +g < 0 )
			{
				(*this)(x,y)->green = 0;
			}
			else if ((*this)(x,y)->green +g > 255 )
			{
				(*this)(x,y)->green = 255;
			}

			//repeat for blue
			if ((*this)(x,y)->blue +b >=0 && (*this)(x,y)->blue +b <=255 )
			{
				(*this)(x,y)->blue = (*this)(x,y)->blue +b;
			}
			else if ((*this)(x,y)->blue +b < 0 )
			{
				(*this)(x,y)->blue = 0;
			}
			else if ((*this)(x,y)->blue +b > 255 )
			{
				(*this)(x,y)->blue = 255;
			}

		}
	}


}

