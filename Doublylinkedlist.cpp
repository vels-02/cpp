/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    Node *prev;
};

void addBegin(Node **start, int data)
{
    
    if( *start == NULL)
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }

    Node *last = (*start)->prev;
    
    Node *new_node = new Node();
    new_node->data = data;
    (*start)->prev = new_node;
    last->next = new_node;
    new_node->next = *start;
    new_node->prev = last;
    (*start) = new_node;
    
}

void addAfter(Node **start, int data, int item)
{
    Node *new_node = new Node();
    new_node->data = data;
    
    Node *temp = *start;
    
    while( ( temp->next != *start ) && (temp ->data != item) )
    {
        temp = temp->next;
    }
    
    Node *next_node = temp->next;
    
    temp->next = new_node;
    new_node->next = next_node;
    new_node->prev = temp;
    next_node->prev = new_node;
    
    
}


void addEnd(Node **start, int data)
{
    if( *start == NULL)
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    
    Node *last = (*start)->prev;
    
    Node *new_node = new Node();
    new_node->data = data;
    
    new_node->next = (*start);
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}

void printList(Node *node)
{
    if(node == NULL) {
        cout << "empty list" << endl;
        return;
    }
    //forward
    Node *tmp = node;
    cout << "Forward direction" << endl;
    while( tmp->next != node)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << tmp->data << endl;
    
    cout << "Reverse direction" << endl;
    Node *last = node->prev;
    tmp = last;
    while( tmp->prev != last)
    {
        cout << tmp->data << " ";
        tmp = tmp->prev;
    }
    cout << tmp->data << endl;

}



int main()
{
    
    Node *start = NULL;
    addEnd(&start, 10);
    addEnd(&start, 20);
    addEnd(&start, 30);
    addEnd(&start, 40);
    addEnd(&start, 50);
    
    addBegin(&start, 9);
    addBegin(&start, 7);
    addBegin(&start, 5);
    addBegin(&start, 3);
    
    addAfter(&start, 4, 3);
    addAfter(&start, 8, 7);
   
   
    printList(start);
    
    return 0;
}
