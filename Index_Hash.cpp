/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

bool has[50][2];


bool search(int X)
{
    if( X >= 0)
    {
        if(has[X][0] == 1)
            return true;
        else
            return false;
    }
    
    X = abs(X);
    cout << "X = " << X << endl;
    if(has[X][1] == 1)
        return true;
    return false;
}



void insert(int a[], int size)
{
    
    for(int i = 0; i < size; i++)
    {
        if( a[i]  >= 0 )
            has[a[i]][0] = 1;
        else
            has[abs(a[i])][1] = 1;
    }
    
}



int main()
{
    
    int a[] = { -1, 9, -5, -8, -5, -2 }; 
    
    int size = sizeof(a) / sizeof(a[0]);
    
    insert(a,size);
    
    int x = -6;
    
    if( search(x)) 
        cout << "Present" << endl;
    else
        cout << "Not Present" << endl;
    
    return 0;
}
