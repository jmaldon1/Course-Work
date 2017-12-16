//
//  main.cpp
//  CrashCourseC++
//
//  Created by Joshua on 2/14/17.
//  Copyright © 2017 Joshua. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int x = 0;
    float f = 0.0;
    char c = 'y';
    
    //MARK: Loops
    //KNOWN: How many times is known
    for (int i = 0; i< 10; i++)
    {
        cout << "Print this ten times" << endl;
        cout << "My counter is currently: " << i << endl;
        
    }
    
    //UNKOWN: how many times is unkown, but you want to keep going until a certain 'condition' is ture
    while (x != -1)
    {
        cout << "Printing this still" << endl;
        cin >> x;
    }
}
