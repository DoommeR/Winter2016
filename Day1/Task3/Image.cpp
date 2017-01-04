#include <iostream>
#include "Image.h"


Image::Image(int tmy, int tmx):mx(tmx),my(tmy)
{
	img = new int[tmx*tmy];
}


Image::~Image()
{
	std::cout <<"~Image_destructor"<< std::endl; 
	//if (img) delete[] img;
}

void Image::load(char* fname)
{
}

void Image::show()
{
	for (int i = 0; i < my; i++) {
		for (int j = 0; j < mx; j++)
		{
			std::cout << get(i, j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Image::init()
{
	for (int i = 0; i<my; i++)
		for (int j = 0; j < mx; j++)
		{
			set(i,j,0);
		}
}

void Image::set(int y, int x, int c)
{
	img[mx*y + x] = c;
}

int Image::get(int y, int x)
{
	return img[mx*y + x];
}

void Image::changeVal()
{
	img[3]=1;
}

Image::Image(const Image &img)
{
	*this=img;
}

Image& Image::operator=(const Image &img){

	if (this == &img) {
		return *this;
    }
	return *this;
}