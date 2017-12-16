//
//  main.cpp
//  Test1Review
//
//  Created by Joshua on 3/27/17.
//  Copyright © 2017 Joshua. All rights reserved.
//

#include <iostream>
#include<stdlib.h>
using namespace std;

class chunk
{
public:
    int value;
    int position;
    
    chunk *next= NULL;
    
    chunk(int=0, int =0 );
    
    int getValue ()
    {
        return (value);
    }
    int getPosition ()
    {
        return (position);
    }

};
chunk::chunk (int a, int b)
{
    value = a;
    position = b;
}

class LinkedList
{
public:
    chunk *head =NULL;
    int length =0;
    
    void insertAtHead(int value)
    {
        chunk *temp;
        temp = new chunk;
        temp ->value = value;
        
        if(head == NULL)
        {
            head = temp;
        }
    }
    void insertAtPos(int value, int position)
    {
        chunk *temp;
        temp = new chunk;
        temp ->value = value;
        
        chunk *aux=head;
        for (int i=1;i <= position; i++)
        {
            aux = aux ->next;
        }
        aux->next = temp->next;
        aux ->next=temp;
        
    }
    void removeFromPos(int value, int position)
    {
        
    }
    
    
};
int main()
{
    
}

