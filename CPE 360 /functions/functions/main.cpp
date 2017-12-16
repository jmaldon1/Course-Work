//
//  main.cpp
//  functions
//
//  Created by Joshua on 2/16/17.
//  Copyright © 2017 Joshua. All rights reserved.
//

#include <iostream>
using namespace std;

int factorial (int);

int main()
{
    int c;
    
    c = factorial(5);
    
    cout << "Factorial for 5 is: " << c << endl;
    
}

int factorial(int N)
{
    int result = 1;
    
    for(int i = N; i >=1; i--)
    {
        result *= i; //resut = result * i
    }
    return result;
}
