//
//  main.cpp
//  Queue
//
//  Created by Joshua on 3/21/17.
//  Copyright © 2017 Joshua. All rights reserved.
//

#include <iostream>
#include<stdlib.h>
using namespace std;

//function prototypes
void enqueue(int);
void dequeue();
void display();

//step1: Conceptually define a chunk. We'll build a queue of chunks

class chunk
{
public:
    int value;
    chunk *next = NULL;
    
    chunk (int = 0);
    
    int getValue ()
    {
        return (value);
    }
};

chunk::chunk (int a)
{
    value = a;
}

class Queue
{
public:
    chunk *head = NULL;
    
    void enqueue(int value)
    {
        chunk *temp;
        temp = new chunk;
        temp->value = value;
        
        //knit it into the structure
        if(head== NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    
    void dequeue()
    {
        if (head == NULL)
        {
            cout << "Empty queue, nothing to delete" << endl;
        }
        else if (head->next == NULL)
        {
            cout << "About to delete: " << head ->value << endl;
            delete head;
            head = NULL;
        }
        else
        {
            chunk *chase, *follow;
            chase = follow = head;
            while(chase->next != NULL)
            {
                follow = chase;
                chase = chase ->next;
            }
            follow ->next = NULL;
            cout << "About to delete: " << chase -> value <<endl;
            delete chase;
        }
    }
    
    void display()
    {
        chunk *temp;
        if(head==NULL)
        {
            cout << "Empty Queue" << endl;
        }
        else
        {
            cout << "Head";
            temp = head;
            while(temp != NULL)
            {
                cout << "--->" << temp ->value;
                temp = temp->next;
            }
        }
    }
    
};

int main()
{
    Queue ourQueue;
    int choice = 0;
    
    while(1)
    {
        cout << "\n-----------------------------\n";
        cout << "Press 1 to add to stack" << endl;
        cout << "Press 2 to delete from stack" << endl;
        cout << "Press 3 to display" << endl;
        cout << "Anything else to quit" << endl;
        cout << "-----------------------------\n";
        cout << "Enter an option: " << endl;
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                cout << "Enter a value to add: ";
                int value;
                cin >> value;
                ourQueue.enqueue(value);
                break;
                
            case 2:
                ourQueue.dequeue();
                break;
                
            case 3:
                ourQueue.display();
                break;
                
            default:
                exit(1);
        }
    }

}
