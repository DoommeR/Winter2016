#include <stdio.h>
#include <iostream>
#include "Image.h"

struct node {
  Image *img;
  int xyz;
  node *next=NULL;
};

class List{
node *head=NULL;
int listLenght;

public:
List();
~List();
void insertNode(node *newNode, int position);
void removeNode(int position);
node getNode(int position);
void retListLen();
void printer(){
  node * temp = head;

    while (temp!=NULL)
    { 
     std::cout<<temp->xyz<<std::endl;
      temp=temp->next; 
        
    }
}

};