#pragma once


class Image
{
	int* img;
	int mx;
	int my;
public:
	Image(int tmx, int tmy);
	virtual ~Image();
	Image(const Image &img);
	Image & operator=(const Image &img);

	int getMx() { return mx; }
	int gerMy() { return my; }
	void changeVal();
	void load(char* fname);
	void show();
	void init();
	void set(int y, int x, int c);
	int get(int y, int x);
	
};

