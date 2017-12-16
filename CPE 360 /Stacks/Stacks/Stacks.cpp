//
//  main.cpp
//  Stacks
//
//  Created by Joshua on 3/7/17.
//  Copyright © 2017 Joshua. All rights reserved.
//

#include <iostream>
#include<stdlib.h>
using namespace std;

//Function Prototypes
void push(int);
void pop();
void display();

//STEP 1: Create a conceptual 'idea' of a chunk. We'll build a stack of chunks
class chunk
{

public:
    
    int value;
    chunk *next = NULL;
    
    //constructor
    //Give our building blocks a default look and feel
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
//MARK: The Stack
class Stack
{
public:
    
    //Gateway pointer to the structre
    chunk *top = NULL; //NULL starts us with an empty stack
    
    //Functions: with an underlying philosophy: LIFO (Last in First Out)
    
    //MARK: Function1: Add to the stack, popularly called 'push'
    void push(int x)
    {
        //get a new chunk, we are going to add this
        chunk *temp;
        temp = new chunk;
        temp ->value = x;
        
        if (top == NULL) //is my stack empty?
        {
            //new element becomes the top
            top = temp;
        }
        else
        {
            //stack has more than one chunk in there already
            temp ->next = top;
            top = temp;
        }
    }
    
    //MARK: Function 2: Delete from stack, popularly called 'pop'
    void pop()
    {
        if(top == NULL)
        {
            cout << "Empty stack, nothing to delete" << endl;
        }
        else
        {
            chunk *temp;
            temp = top;
            top = temp->next; //top points to the second element
            cout << "About to delete: " << temp ->value <<endl;
            delete temp;
            
        }
    }
    
    //MARK: Displays the structure
    void display()
    {
        chunk *traverse = top;
        if(top == NULL)
        {
            cout << "Empy Stack. Nothing to Display" << endl;
        }
        else
        {
            cout << "Head";
            while (traverse !=NULL)
            {
                cout << "--->" <<traverse->value;
                traverse = traverse ->next;
            }
        }
    }
};

int main()
{
    Stack ourStack;
    int choice = 0;
    
    while(1)
    {
        cout << "\n-----------------------------\n";
        cout << "Press 1 to add to stack" << endl;
        cout << "Press 2 to delete from stack" << endl;
        cout << "Press 3 to display" << endl;
        cout << "Anything else to quit" << endl;
        cout << "-----------------------------\n";
        cout << "Enter an option: ";

        cin >> choice;
        
        switch(choice)
        {
            case 1:
                cout << "Enter a value to add: ";
                int value;
                cin >> value;
                ourStack.push(value);
                break;
                
            case 2:
                ourStack.pop();
                break;
                
            case 3:
                ourStack.display();
                break;
                
            default:
                exit(1);
        }
    }
}
