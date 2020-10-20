/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>
#include <chrono>
#include <deque>
#include <mutex>
#include <condition_variable>

using namespace std;

std::deque<int> dq;
std::mutex mu;
std::condition_variable cond;


void function1()
{
    int count = 10;
    
    while(count > 0)
    {
        std::unique_lock<std::mutex> locker(mu);
        dq.push_front(count);
        locker.unlock();
        cond.notify_one();
        cout << count << endl;
        std::this_thread::sleep_for(chrono::seconds(1));
        count--;
    }
}


void function2()
{
   int data = 0;
   
   while(data != 1)
   {
       std::unique_lock<std::mutex> locker(mu);
       cond.wait(locker, [](){return !dq.empty();});
       data = dq.back();
       dq.pop_back();
       locker.unlock();
       cout << "t1 got a value from T1 : " << data << endl;
   }
}

int main()
{
    
    thread t1(function1);
    thread t2(function2);
    t1.join();
    t2.join();

    cout << "Main end" << endl;
    
    return 0;
    
}
