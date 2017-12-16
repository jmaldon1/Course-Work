//
//  main.cpp
//  Recursion: Hanoi
//
//  Created by Joshua on 2/21/17.
//  Copyright © 2017 Joshua. All rights reserved.
//

#include <iostream>
using namespace std;

//function prototype
void hanoi(int,char,char,char);

int main()
{
    int N;
    char S = 'S';
    char D = 'D';
    char I = 'I';
    
    cout << "Enter the number of discs: ";
    cin >> N;
    
    hanoi(N, S, D, I);
    
}

//function
void hanoi (int N, char S, char D, char I)
{
    if (N==1)
    {
        cout << "Move disc: " << N << " from " << S << " to " << D << endl;
    }
    else
    {
        hanoi (N-1, S, I, D);
        cout << "Move disc: " << N << " from " << S << " to " << D << endl;
        hanoi (N-1, I, D, S);
    }
}
