/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;


int factorial(int n)
{
    int res = 1;
    cout << n << endl;
    while(n)
    {
        res = res * n;
        n--;
    }
    
    cout << "Factorial : " << res << endl;
    
    return res;
}

//int factorial_future(std::future<int>& f)
int factorial_future(std::shared_future<int> f)
{
    int res = 1;

    
    //get the set_value
    int n = f.get();
    
    while(n)
    {
        res = res * n;
        n--;
    }
    
    cout << "Factorial : " << res << endl;
    
    return res;
}


int main()
{
    //std::thread t1(factorial, 5);
    //t1.join();
    std::future<int> fu = std::async(std::launch::async, factorial, 5); // in future once you done get me the result;
    cout << "funture only " << fu.get() << endl;  // access the value from future;
    
    
    std::promise<int> p;
    std::future<int> fu1 = p.get_future();
    
    std::shared_future<int> sf = fu1.share();
    
    std::future<int> fut = std::async(std::launch::async, factorial_future, sf); //promised to send the value later
    std::future<int> fut1 = std::async(std::launch::async, factorial_future, sf);
    std::future<int> fut2 = std::async(std::launch::async, factorial_future, sf);
    std::future<int> fut3 = std::async(std::launch::async, factorial_future, sf);


    // doing some work
    std::this_thread::sleep_for(chrono::seconds(2));
    p.set_value(4);
    cout << "Promised funture  " << fut.get() << endl;
    cout << "Promised funture  " << fut1.get() << endl;
    cout << "Promised funture  " << fut2.get() << endl;
    cout << "Promised funture  " << fut3.get() << endl;

    return 0;
}
