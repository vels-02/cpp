/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;


class Node {
  public:
    int data;
    Node *next;
};


void sortedInsert(Node **head_ref, Node *new_node)
{
    
    Node *current = *head_ref;
    
    if(current == NULL)
    {
        new_node->next = new_node;
        *head_ref = new_node;
    }
    else if( current->data >= new_node->data)
    {
        
        while(current->next != *head_ref)  
            current = current->next; 
        
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
        
    }
    else
    {
        while(current->next != *head_ref &&
                current->next->data < new_node->data){
                    current = current->next;
                }
                
        new_node->next = current->next;
        current->next = new_node;
        
    }
    
    
}

void printList(Node *head)
{
    if(head == NULL ) return;
    
    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
        
    } while(temp != head);
}

int main()
{
    int arr[] = {12, 56, 2, 11, 1, 90};
    
     Node *head = NULL;
     Node *temp ;
     
    int size = sizeof(arr) / sizeof(arr[0]) ;
    
    cout << size << endl;
    for(int i = 0; i < size; i++)
    {
        
         temp = new Node();
         temp->data = arr[i];
         sortedInsert(&head, temp);
        
    }
    
    printList(head);

    return 0;
}
