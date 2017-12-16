//
//  main.cpp
//  Lego
//
//  Created by Joshua on 3/2/17.
//  Copyright © 2017 Joshua. All rights reserved.
//

#include <iostream>
using namespace std;

//Class
class legoChunk
{
    
public:
    
    int x, y;
    legoChunk *next = NULL;
    
    //constructor
    legoChunk (int = 0, int= 0);
    
    int getX ()
    {
        return (x);
    }
    int getY()
    {
        return (y);
    }
    
};

//must have for code to work
legoChunk::legoChunk (int a, int b)
{
    x = a;
    y = b;
}

int main ()
{
    //First step: create a pointer. WHY? because we need to store addresses for chunks in the heap
    legoChunk *ptr;
    
    //Second step: use the pointer to get a chunk in the heap
    ptr = new legoChunk;
    
    //Use the arrow "->" operator to access elements in the chunk
    cout << "x: "<<ptr->x<<endl;
    ptr ->x = 10;
    ptr ->y =20;
    cout << "x is now: "<<ptr ->x <<", and y: " << ptr->y<<endl;
    
    //Use the pointer in the first chunk, and create a second chunk.
    //We want the pointer of the first to point to this second chunk
    ptr->next = new legoChunk;
    ptr ->next->x =45;
    ptr ->next->y=55;
    
    cout << "x in the first chunk: " <<ptr ->x << ", and second chunk: " << ptr->next->x <<endl;
    
    //Use the pointer of the second chunk to create a third chunk
    //We now have this going on: ptr->1st->2nd->3rd
    ptr -> next -> next = new legoChunk;
    ptr ->next->next->x=10;
    ptr ->next->next->y=11;
    
    //One more chunk. Let's get the third one pointing to the fourth one
    ptr ->next ->next->next = new legoChunk;
    ptr ->next ->next->next->x = 5;
    ptr ->next ->next->next->y = 7;
    
    //delete the second chunk!! HOW?
    // get a temp pointer to point to the second chunk
    legoChunk *temp;
    temp = ptr->next;
    
    //now take the pointer of the FIRST one and point to the THIRD one
    ptr->next = ptr->next->next;
    
    //now you can safely delete the SECOND chunk, which temp is pointing to
    delete temp;
}


