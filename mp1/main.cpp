#include <algorithm>
#include <iostream>

#include "rgbapixel.h"
#include "png.h"

using namespace std;

PNG rotateImage(PNG initImage, PNG outImage)
{

	 for (size_t yi = 0; yi < outImage.height(); yi++)
    {
        for (size_t xi = 0; xi < outImage.width(); xi++)
        {
        	*outImage(xi,yi)= *initImage(outImage.width()-1-xi,outImage.height()-1-yi );
        }
    } 
    return outImage;

}

int main(){

	PNG image("in.png");

	PNG blank(image.width(),image.height());
   	
   	blank = rotateImage(image, blank);

   	return blank.writeToFile("out.png");

}

