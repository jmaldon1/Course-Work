//
//  main.cpp
//  a1
//
//  Created by Joshua on 2/7/17.
//  Copyright © 2017 Joshua. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int x ;
    
    x=5;
    int *pal; //can only store address
    pal = &x;
    
    x=10;
    *pal = 20; 
    
    cout << "x is now: " << x << endl; 

}
