#include "List.h"

List::List()
{
head=NULL;
}

List::~List()
{
    /*while(head!=NULL)
    {
        node *tmp =head->next;
        delete head;
        head=tmp;
    }*/
}

void List::insertNode(node *newNode, int position)
{
    
    if (head==NULL)
    { 
        
        newNode->xyz=0;
        head=newNode;
        listLenght=0;
        std::cout <<"fist" << std::endl; 
    }
    else
    { 
        std::cout <<"sec" << std::endl;
        newNode->xyz=++listLenght;
        head->next=newNode;
        head=newNode;
        newNode->next=NULL;
    }
}

void List::removeNode(int position)
{

}

node List::getNode(int position)
{
    node *a=head,
         *b=a;

    if (position>listLenght) {node a; a.xyz=0; return a;}
    while (position){

        a=b;
        b=a->next;
        
        position--;

    }

    return *a;
}

void List::retListLen()
{

std::cout <<"listlen=" << listLenght<< std::endl; 

}