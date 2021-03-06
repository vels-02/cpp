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

int circularArrSearch(int arr[], int n,int x)
{
    int low = 0, high = n-1; 
    
    while(low <= high)
    {
        int mid = (low+high) / 2;
        
        //find the sorted half-- because we can to binary search
        if( x == arr[mid] ) return mid;
        
        if(arr[mid] <= arr[high] )
        {
            if(x > arr[mid] && x <= arr[high])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
                
        }
        else
        {
            if(arr[low] <= x && x < arr[mid]) 
            {
                high = mid-1;
            }
            else
                low = mid + 1;
        }   
    }
    
    return -1;
}

int main()
{
      int arr[]  = {2, 4, 5, 5, 5, 5, 5, 5, 10, 10, 10, 18, 20};
    
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "first index of 5 is " << BinarySearch(arr, len, 5, true) << endl;
   
    int firstindex = BinarySearch(arr, len, 5, true);
    if(firstindex == -1) {
        cout << "element not found" << endl;
    }
    else
    {
         int lastindex = BinarySearch(arr, len, 5, false);
         
         cout << "Count is : " << (lastindex-firstindex) + 1 << endl;
    }
    
    
    //find an element in ciruclary sorted array
    int arr1[]  = {12,14,18,21, 3, 6,8 ,9 };
    len = sizeof(arr1) / sizeof(arr1[0]);
    
    cout << circularArrSearch(arr1, len, 21);


    return 0;
}
