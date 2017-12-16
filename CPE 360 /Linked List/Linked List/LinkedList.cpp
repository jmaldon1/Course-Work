//
//  main.cpp
//  Linked List
//
//  Created by Joshua on 3/21/17.
//  Copyright © 2017 Joshua. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

//function prototypes
void insertAtHead(int);
void insertAtPosition(int, int);
void removeFromPosition(int);
void display();

class chunk
{
public:
    int value;
    int position;
    chunk *next = NULL;
    
    chunk (int = 0, int = 0);
    
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
    chunk *head = NULL;
    int length=0;
    
    //adds the first chunk to the structure
    void insertAtHead(int value)
    {
        chunk *temp;
        temp = new chunk;
        temp->value = value;
        
        if (head == NULL) //is my stack empty?
        {
            //new element becomes the top
            head = temp;
        }
        else //stack has more than one chunk in there already
        {
            //Adds a chunk right after head
            temp ->next = head;
            head = temp;
        }
        
        length ++;
    }
    
    //adds all other chunks at any position to the structure
    void insertAtPosition(int position, int value)
    {
        chunk *temp;
        temp = new chunk;
        temp ->value = value;
        
        chunk *aux = head;
        for (int i=1; i<= position; i++)
        {
            aux = aux -> next;
        }
        
        temp->next = aux->next;
        aux ->next = temp;
        length ++;
    }
    
    //removes any chunk from the structure
    void removeFromPosition(int position)
    {
        //nothing to delete
        if (head == NULL)
        {
            cout << "Empty List, nothing to delete" << endl;
        }
        //if there is only 1 chunk, then delete that
        else if (head->next == NULL)
        {
            cout << "About to delete: " << head ->value << endl;
            delete head;
            head = NULL;
            length--;
        }
        //if there is more than one chunk, choose which to delete
        else
        {
            //Deletes the first chunk on the stack, if the user chose the first chunk
            if(position ==0)
            {
                chunk *temp;
                temp =head;
                head = temp->next; //head points to the second element
                cout << "About to delete: " << temp ->value <<endl;
                delete temp;
            }
            else//This will go to the position that the user has selected and delete that chunk
            {
                chunk *chase=head, *follow=head;
                for(int i=1;i<=position;i++)
                {
                    follow= chase;
                    chase = chase->next;
                }
                follow ->next = chase->next;
                delete chase;
            }
            length--;
            
        }
    }
    
    void display()
    {
        chunk *temp;
        if(head==NULL)
        {
            cout << "Empty Structure" << endl;
        }
        else
        {
            cout << "Head";
            temp = head;
            while(temp != NULL)
            {
                cout <<"--->" << temp ->value;
                temp = temp->next;
            }
        }
    }
    
    //Midterm Star problem 2
    //assuming that there exists a loop in the structure
    void detectAndRemoveLoops(int length)
    {
        chunk *chase=head, *follow=head;
        for(int i=1; i<=length;i++)
        {
            follow= chase;
            chase = chase->next;
        }
        if (chase!=NULL)
        {
            chase = NULL;
        }
    }
    
    //Midterm Star Problem 1
    void mergLinkedList(chunk *firstList, chunk* secondList)
    {
        chunk *first = firstList, *second = secondList;
        chunk *firstNext, *secondNext;
        
        while (first != NULL && second != NULL)
        {
            firstNext = first->next;
            secondNext = second->next;
            second->next=firstNext;
            first->next = second;
            first = firstNext;
            second = secondNext;
            
        }
        secondList = second;
    }
     
};

int main()
{
    //Variables
    LinkedList ourList;
    int choice = 0;
    int length = 0;
    int position;
    
    //Menu
    while(1)
    {
        cout << "\n---------------------------------------\n";
        cout << "Press 1 to add to stack" << endl;
        cout << "Press 2 to delete from stack" << endl;
        cout << "Press 3 to display" << endl;
        cout << "Anything else to quit" << endl;
        cout << "Current # of Chunks in the Structure: " << length << endl;
        cout << "---------------------------------------\n";
        cout << "Enter an option: ";
        cin >> choice;
        cout << endl;
        
        
        switch(choice)
        {
            case 1:
                if (length == 0)
                {
                    cout << "Enter a value to add: ";
                    int value;
                    cin >> value;
                    ourList.insertAtHead(value);
                }
                if (length > 0)
                {
                    //ask the position the user wants to add a chunk after
                    cout << "Enter the position that you would like to add a chunk: ";
                    cin >> position;
                    position = position-1;
        
                    //check if position is valid
                    while(position >= length || position < -1)
                    {
                        cout << "Invalid position(must be <= length), Please reenter: ";
                        cin >> position;
                        position = position-1;
                    }
                    
                    //allows the user to insert a chunk right after Head
                    if(position == -1)
                    {
                        cout << "Enter a value to add: ";
                        int value;
                        cin >> value;
                        ourList.insertAtHead(value);
                    }
                    else
                    {
                    //enter a value to be put into the chunk
                    cout << "Enter a value to add: ";
                    int value;
                    cin >> value;
                    ourList.insertAtPosition(position, value);
                    }
                }
                
                length ++;
                
                break;
                
            case 2:
                //if there is more than 1 element in the structure, ask the user what position they want to delete a chunk
                if(length > 1)
                {
                    cout << "Enter the position that you would like to delete a chunk: ";
                    int position;
                    cin >> position;
                    position = position-1;
                
                    //check if position is valid
                    while(position >= length || position < 0)
                    {
                        cout << "Invalid position(must be <= length), Please reenter: ";
                        cin >> position;
                        position = position-1;
                    }
                    ourList.removeFromPosition(position);
                    length--;
                }
                //if there is only 1 chunk in the structure, than it will do this
                else if (length == 1)
                {
                    position = 0;
                    ourList.removeFromPosition(position);
                    length--;
                }
                else
                {
                    position = 0;
                    ourList.removeFromPosition(position);
                }
                
                
                cout << "There are now " << length << " chunks in your Structure" << endl;
                
                break;
                
                
            case 3:
                
                ourList.display();
                
                break;
                
            default:
                exit(1);
        }
    }
}

