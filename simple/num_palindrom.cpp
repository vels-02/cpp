/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int reverse(int n)
{
    int rev_n=0;
    
    while(n > 0)
    {
        rev_n = rev_n * 10 + n % 10;
        cout << "rev_n " << rev_n << endl;
        n = n/10;
        
        cout << "n " << n << endl;
    }
    
    return rev_n;
}


bool isPalindrome(int n)
{
    int rev_n = reverse(n);
    
    if(rev_n == n)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    cout<< n << " is a palindrome - " <<  (isPalindrome(n)? "True " : "False") << endl;

    return 0;
}
