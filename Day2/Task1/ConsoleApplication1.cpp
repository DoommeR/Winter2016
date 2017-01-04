// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>

using namespace std;
int main()
{
	List<int> imglist;
	
	imglist.InsertNode(101, 0);
	imglist.InsertNode(1, 0);
	imglist.InsertNode(131, 0);
	imglist.PrintList();
	cout << "kek";
	int tmp = getchar();
    return 0;
}

