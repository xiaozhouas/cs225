#include "scene.h"
#include <iostream>
using namespace std;

	void Scene::_copy(Scene const & other)
	{
		_max = other._max;
		_images = new Image*[_max];
		_coordinateX = new int[_max];
		_coordinateY = new int[_max];
		for(int i =0; i<_max; i++)
		{
			if (other._images[i])
			{
			_coordinateX[i] = other._coordinateX[i];
			_coordinateY[i]	= other._coordinateY[i];
			_images[i] = new Image (*(other._images[i]));
			}
			else
			{
			_coordinateX[i] = 0;
			_coordinateY[i]	= 0;
			_images[i] = NULL;
			}
		}

	}

	void Scene::_clear()
	{
		delete [] _coordinateX;
		delete [] _coordinateY;

		for (int i =0; i<_max;i++ )
		{
			delete _images[i];
			_images[i] = NULL;
		}
		delete [] _images;
		_images = NULL;
		_coordinateX = NULL;
		_coordinateY = NULL;
	}




	//Default Construction
	Scene::Scene(int max)
	{
		_max = max;
		_coordinateX = new int[_max];
		_coordinateY = new int[_max];
		_images = new Image*[_max];
		for (int i =0; i<_max;i++ )
		{	
			_images[i] = NULL;
			_coordinateX[i] =0;
			_coordinateY[i] =0;
		}
		

	}

	//Deconstruction to free memory
	Scene::~Scene()
	{
		_clear();
	}

	//Another Construction, The copy constructor makes this Scene an independent copy of the source.
	Scene::Scene(const Scene &source)
	{
		_copy(source);
	}



	//The assignment operator for the Scene class
	const Scene & Scene::operator= (const Scene &source)
	{
		if(this == &source)
		{
			return *this;

		}
		else
		{
			_clear();
			_copy(source);
			return *this;
		}
			
	}

	//Modifies the size of the array of Image pointers without changing their indices.
	void Scene::changemaxlayers (int newmax)
	{
	
		if (newmax<1)
		{	
			cout << "index out of bounds" << endl;
			return;
		}
		if (newmax == _max)
		{
			return;
		}
		//cout<< "here:" << __LINE__<< endl;
		if (newmax<_max)
		{
			for (int i = newmax+1; i<_max;i++)
				{
					if (_images[i])
					{
						cout << "invalid newmax" << endl;
						return;
					}
					else
					{
						delete _images[i];
						_images[i]=NULL;
					} 
				}
			return;
		}
		else 
		{
			Image ** copy;
			int * cordX, *cordY;
			copy = new Image * [newmax];
			cordX = new int [newmax];
			cordY = new int [newmax];
			//cout<< "here:" << __LINE__<< endl;
			for(int i = 0; i<_max; i++)
			{
				if(_images[i])
				{
				copy[i] = new Image (*(_images[i]));
				cordX[i] = _coordinateX[i];
				cordY[i] = _coordinateY[i];
				}
				else
				{
				copy[i] = NULL;
				cordX[i] = 0;
				cordY[i] = 0;
				}
			}
			for (int i=_max; i< newmax; i++ )
			{
				copy[i] = NULL;
				cordX[i] = 0;
				cordY[i] = 0;	
			}
			//cout<< "here:" << __LINE__<< endl;
			_clear();
			_max = newmax;
			_images = new Image *[newmax];
			_coordinateX = new int[newmax];
			_coordinateY = new int[newmax];
			_images = new Image*[_max];
			//cout<< "here:" << __LINE__<< endl;
			for (int i =0; i<newmax;i++ )
			{	
				//cout<< "here:" << __LINE__<< "i =="<< i<< endl;
				if(copy[i])
				{
				//cout<< "here:" << __LINE__<< endl;
				_images[i] = new Image (*(copy[i]));;
				//cout<< "here:" << __LINE__<< endl;
				_coordinateX[i] = cordX[i];
				_coordinateY[i] = cordY[i];
				//cout<< "here:" << __LINE__<< endl;
				}
			}
			//cout<< "here:" << __LINE__<< endl;
			delete [] copy;
			delete [] cordX;
			delete [] cordY;
			//cout<< "here:" << __LINE__<< endl;
			//cout<< "here:" << __LINE__<<"_max = " << _max<<endl;
			for (int i =0; i<newmax;i++)
			{
				delete copy[i];
				copy[i] = NULL;
			}
			copy = NULL;
			cordY = NULL;
			cordX = NULL;
		}	
		return;

	}

	//This function will add a picture to the scene, by placing it in the array cell corresponding 
	//to the given index, and storing its x coordinate and y coordinate.
	void Scene::addpicture (const char *FileName, int index, int x, int y)
	{
		if (index<0 || index >=_max)
		{	
			cout << "index out of bounds" << endl;
			return;
		}
		else
		{	
			if(_images[index])
			{
				delete _images[index];
			}
			_images[index] = new Image;
			_images[index]->readFromFile(FileName);
			_coordinateX[index] = x;
			_coordinateY[index] = y;
		}
	}

	//Moves an Image from one layer to another.
	void Scene::changelayer (int index, int newindex)
	{
		if (index == newindex)
		{
			return; 
		}
		if (index <0 || index >=_max || newindex<0 || newindex >=_max)
		{
			cout << "invalid index" << endl;
			return;
		}
		if (_images[newindex])
		{
			delete _images[newindex];
		}
		_images[newindex] = _images[index];
		_coordinateX[newindex] = _coordinateX[index];
		_coordinateY[newindex] = _coordinateY[index];
		_images[index]= NULL;
		return;
	}

	//Changes the x and y coordinates of the Image in the specified layer.
	void Scene::translate (int index, int xcoord, int ycoord)
	{
		if (index <0 || index >=_max)
		{
			cout << "invalid index" << endl;
			return;
		}
		if (!_images[index])
		{
			return;
		}
		_coordinateX[index] = xcoord;
		_coordinateY[index] = ycoord;
		return;
	}

	//Deletes the Image at the given index.
	void Scene::deletepicture (int index)
	{
		if (index <0 || index >=_max || !(_images[index]))
		{
			cout << "invalid index" << endl;
			return;
		}
		delete _images[index];
		_images[index]= NULL;
		_coordinateX[index] = 0;
		_coordinateY[index] = 0;

	}

	//This function will return a pointer to the Image at the specified index, not a copy of it.	
	Image * Scene::getpicture (int index) const
	{
		if (index <0 || index >=_max || !(_images[index]))
		{
			cout << "invalid index" << endl;
			return NULL;
		}
		return (_images)[index];

	}
	

	//Draws the whole scene on one Image and returns that Image by value.
	Image Scene::drawscene () const
	{
		int maxWidth =1;
		int maxHeight =1;

		int *width, *height, *cordX,*cordY;
		width = new int [_max];
		height = new int [_max];
		cordX = new int [_max];
		cordY = new int [_max];
			 // cout<< "there:" << __LINE__<< endl;
		for(int i=0; i<_max; i++)
		{	
			if (_images[i])
			{
			width[i]= (_images)[i]->width();
			height[i] =(_images)[i]->height();
			cordX[i] = _coordinateX[i];
			cordY[i] = _coordinateY[i];
			}
		}
		 // cout<< "there:" << __LINE__<< endl;
		for (int i =0; i<_max;i++)
		{
			if(_images[i])
			{
			maxWidth = (maxWidth > (cordX[i]+width[i]))? maxWidth : (cordX[i] + width[i]);
			maxHeight = (maxHeight > (cordY[i]+ height[i]))? maxHeight : (cordY[i]+ height[i]);

			}
		}
		 // cout<< "there:" << __LINE__<< endl;
		 //  cout<< "width:" << maxWidth<< endl;
		 //   cout<< "height:" << maxHeight<< endl;
		Image output;
		// cout<< "there:" << __LINE__<< endl;
		output.resize(maxWidth,maxHeight);
		 //cout<< "there:" << __LINE__<< endl;
		for (int i = 0; i<_max;i++)			
		{
			if (_images[i])
			{
				 //cout<< "there:" << __LINE__<< endl;
				for (int y =cordY[i]; y< (cordY[i]+height[i]);y++) 
				{
					 //cout<< "there:" << __LINE__<< endl;
					for (int x =cordX[i]; x < (cordX[i]+width[i]); x++)
					{
						*output(x,y) = *(*_images[i])(x-cordX[i],y-cordY[i]); 
					}
				}
			}
		}
		delete width;
		delete height;
		delete cordY;
		delete cordX;
		width = NULL;
		height = NULL;
		cordX = NULL;
		cordY = NULL;

		return output;
		//cout<< "there:" << __LINE__<< endl;


	}