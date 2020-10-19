/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5

class fctor
{
  public:
     int operator()(string  msg)
        {
            cout << " functor class : " << msg << endl;
        }
    
};


void *wait(void *t) {
   int i;
   long tid;

   tid = (long)t;

   sleep(3);
   cout << "Sleeping in thread " << endl;
   cout << "Thread with id : " << tid << "  ...exiting " << endl;
   pthread_exit(NULL);
}

struct thread_data
{
  int thread_id;
  char *msg;
    
};


void *printhello(void *thread_arg)
{
    long tid;
    
    struct thread_data *targ = (thread_data*)thread_arg;
    cout <<  "Thread Id : " << targ->thread_id ;
    cout << "  Message : " <<  targ->msg << endl;
    pthread_exit(NULL);
}



int main()
{
 
   int rc;
   int i;
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   void *status;

   // Initialize and set thread joinable
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  
     for( i = 0; i < NUM_THREADS; i++ ) {
        rc =  pthread_create(&threads[i], &attr, wait, (void *)i );
        if(rc)
        {
            cout << "Unable to create thread[" << i << "]" << endl;
            exit(-1);
        }
    }
    
    
    pthread_attr_destroy(&attr);
    for(int i =0; i < NUM_THREADS; ++i)
    {
        rc = pthread_join(threads[i], &status);
        
        if(rc){
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }
        
        cout << "Main thread " << i << " completed with status " << status << endl;
    }
   

   cout << "Main: program exiting." << endl;
   pthread_exit(NULL);

    

    return 0;
}
