/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <list>

using namespace std;

class Hash
{
    private:
        int Buckets;
        list<int> *table;
    public:
        Hash(int n);
        void Insert(int x);
        void deleteItem(int x);
        void display_table();
        bool searchItem(int key);
        int hash_function(int x) { return (x % Buckets); } 
};


Hash::Hash(int n)
{
    Buckets = n;
    table = new list<int>[Buckets];
}


void Hash::Insert(int x)
{
    int index = hash_function(x);
    table[index].push_back(x);
}

void Hash::deleteItem(int x)
{
    int index = hash_function(x);
    
    list<int>::iterator i;
    
    for(i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == x)
            break;
    }
    
    
    //remove
    if( i != table[index].end() )
         table[index].erase(i);
    
}

bool Hash::searchItem(int key)
{
    int index = hash_function(key);
    
    list<int>::iterator i;
    
    for(i = table[index].begin(); i != table[index].end(); i++ )
    {
        if( *i == key)
            return true;
    }
    return false;
}

void Hash::display_table()
{
    
    for(int i=0; i < Buckets; i++)
    {
        cout << i;
        for( auto x: table[i])
        {
            cout << "-->" << x;
        }
        cout << endl;
    }
}


int main()
{
    
    int a[] = {15, 11, 27, 8, 12}; 
    int n = sizeof(a)/sizeof(a[0]); 
  
    Hash h(7);
    
    for(int i=0; i < n; i++)
         h.Insert(a[i]);
         
    h.display_table();
    
    h.deleteItem(12);
    
    h.display_table();
    
    if(h.searchItem(11))
        cout << "Key 11 is present" << endl;
    else
        cout << "not present" << endl;
    
    
  
    return 0;
}