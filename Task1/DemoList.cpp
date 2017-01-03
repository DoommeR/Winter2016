// DemoList.cpp : Defines the entry point for the console application.
//

#if !defined(_WINDOWS)
#include "stdafx.h"

#endif

#include "Image.h"


int main()
{
	Image a(3,4);
	a.init();
	
	
	Image b(3,4);

	//b=*new Image(a);
	b=a;
	a.changeVal();
	a.show();
	b.show();
	
	int tmp = getchar();

    return 0;
}

