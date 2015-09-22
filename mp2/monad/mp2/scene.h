#ifndef SCENE_H
#define SCENE_H

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
#include "image.h"

class Scene
{
public:
	//Default Construction
	Scene(int max);
	//Deconstruction to free memory
	~Scene();
	//Another Construction
	Scene(const Scene &source);

	const Scene & 	operator= (const Scene &source);
	void changemaxlayers (int newmax);
	void addpicture (const char *FileName, int index, int x, int y);
	void changelayer (int index, int newindex);
	void translate (int index, int xcoord, int ycoord);
	void deletepicture (int index);
	Image * getpicture (int index) const;
	Image 	drawscene () const;

	

private:
	/* data */
	int * _coordinateX;
	int * _coordinateY;
	int _max;
	Image ** _images;

	// private helper function
	void _copy(Scene const & other);
	void _clear();

};

#endif