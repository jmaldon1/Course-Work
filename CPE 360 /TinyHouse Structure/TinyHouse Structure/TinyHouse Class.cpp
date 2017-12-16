//
//  main.cpp
//  TinyHouse Structure
//
//  Created by Joshua on 2/28/17.
//  Copyright © 2017 Joshua. All rights reserved.
//

#include <iostream>
using namespace std;

//Class
class TinyHouse
{
    
public:
    
    int rooms, doors, windows;
    
    TinyHouse (int = 3, int = 2, int = 4);
    
    int getRooms ()
    {
        return (rooms);
    }
    int getDoors ()
    {
        return (doors);
    }
    int getWindows ()
    {
        return (windows);
    }
    
};

//must have for code to work
TinyHouse::TinyHouse (int a, int b, int c)
{
    rooms= a;
    doors = b;
    windows= c;
}

int main ()
{
    //allows us to access the class using the name 'var'
    TinyHouse var;
    
    //var.getDoors is used to access the class
    cout << var.getDoors() << endl;
    
    //creates a pointer named pal that points to TinyHouse
    TinyHouse *pal;
    pal = new TinyHouse;
    
    //pal is pointing to doors, which is within TinyHouse and changes its value to 40
    pal -> doors = 40;
    
    //prints the pointer to doors
    cout << pal->doors << endl;
    
    //deletes the pal pointer
    delete pal;
    
}
