/******************************************************************************

find first and last occurance of num in array sorted

*******************************************************************************/

#include <iostream>

using namespace std;


int BinarySearch(int arr[], int n, int x,bool firstoccur)
{
    int low, high, res = -1;
    int mid;
    
    low = 0; 
    high = n-1;
    
    while(low <= high)
    {
        mid = (low+high) / 2;
        if( arr[mid] == x)
        {
            res = mid;
            if(firstoccur)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if( x < arr[mid] )
            {
                high = mid -1;
            }
            else if( x > arr[mid] )
            {
                low = mid+1;
            }
            else
            {
                return -1;
            }
        }
    }
    
    return res;
    
}

int main()
{


    int arr[]  = {2, 4, 10, 10, 10, 18, 20};
    
    int len = sizeof(arr) / sizeof(arr[0]);
    
    cout << "index of 10 is " << BinarySearch(arr, 7, 10, true) << endl;

    return 0;
}
