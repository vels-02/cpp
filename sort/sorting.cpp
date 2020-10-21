/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void selectionsort(int arr[], int len)
{
  for(int i = 0; i < len-1; i++)
  {
      int iMin = i;
      for(int j = i; j < len; j++)
      {
          if(arr[j] < arr[iMin])
            iMin = j;
      }
      
      int temp = arr[i];
      arr[i] = arr[iMin];
      arr[iMin] = temp;
      
  }
}

void bubblesort(int arr[] , int len)
{
    for(int i = 0; i < len-1; i++)
    {
        int flag = 0;
        for(int j = 0 ; j < len-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
            
        }
        
        if(flag == 0) break;
    }
}

void insertionSort(int arr[], int len)
{
    
    for(int i = 1; i < len; i++)
    {
        int val = arr[i];
        int hole = i;
        
        while(hole > 0 && arr[hole-1] > val) {
        
            arr[hole] = arr[hole-1];
            hole = hole-1;
        }
        
        arr[hole] = val;
        
    }
    
    
}



void print(int arr[], int size)
{
    for(int i=0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
}


void Mergefunction(int arr[], int l, int m, int r)
{
   
   int n1 = m - l + 1;
   int n2 = r-m;
   
   int L[n1], R[n2];
   
   for( int i = 0; i < n1; i++)
        L[i] = arr[l+i];
    
    for( int j = 0; j < n2; j++)
        R[j] = arr[ m +1 + j];
        
    // Merge the temp arrays 
    // Initial index of first subarray 
    int i = 0;  
      
    // Initial index of second subarray 
    int j = 0;  
      
    // Initial index of merged subarray 
    int k = l; 
    
    while( i < n1  && i < n2)
    {
        if( L[i] <= R[j] )
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(i < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergesort(int arr[] , int l, int r)
{
    if( l < r)
    {
        int m = l+(r-l) / 2;
        
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        cout << "l :" << l << " m:" << m << " r:" << r << endl;
        Mergefunction(arr, l, m, r);
    }
    
}

int parition(int arr[], int startIndex, int endIndex)
{
    int pivot = arr[endIndex];
    int pIndex= startIndex;
    
    for(int i=startIndex; i < endIndex; i++)
    {
        if(arr[i] <= pivot)
        {
            int tmp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = tmp;
            pIndex++;
            
        }
    }
    int tmp  = arr[pIndex];
    arr[pIndex] = arr[endIndex];
    arr[endIndex] = tmp;
    cout << "pIndex :" << pIndex << endl;
    return pIndex;
    
}

void quicksort(int arr[] , int start, int end)
{
    if(start < end)
    {
        int pIndex = parition(arr, start, end);
        quicksort(arr, start, pIndex-1);
        quicksort(arr, pIndex+1, end);
        
    }
    
}

int main()
{
    
    int arr[] = {8,3,1,5,9,4,7,6};
    
    int len = sizeof(arr)/ sizeof(arr[0]);
    
    print(arr,len);
    
    //selectionsort(arr, len);
    //bubblesort(arr, len);
    //insertionSort(arr, len);
    mergesort(arr, 0, len-1);
    //quicksort(arr, 0, len-1);
    
    print(arr, len);

    return 0;
}

