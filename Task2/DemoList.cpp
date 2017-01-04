// DemoList.cpp : Defines the entry point for the console application.
//g++ DemoList.cpp Image.cpp List.cpp -o dl


#include "Image.h"
#include "List.h"

int main()
{
	Image a(3,4),
		  b(3,4);
	a.init();
	
	
	

	//b=*new Image(a);
	b=a;
	a.changeVal();
	a.show();
	b.show();
	
	int tmp = getchar();


	List ls=*new List();
	node nd;
	ls.insertNode(&nd,0);
	ls.insertNode(&nd,0);
	ls.insertNode(&nd,0);
	ls.printer();
	//nd=ls.getNode(0);
	std::cout <<"node =  " << nd.xyz<< std::endl; 
	ls.retListLen();
    return 0;
}

