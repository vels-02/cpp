/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


class Node
{
public:
  int data;
  Node *next;
};

void
print_linkedlist (Node * lst)
{
    
  if (lst == NULL) {
    cout << "List is empty" << endl;
    return;
  }
  Node *start = lst;
  while (lst->next != NULL && lst->next != start)
    {
      cout << lst->data << ' ';
      lst = lst->next;
    }
    
    cout << lst->data << endl;
}

bool isCircular(Node *head)
{
    if(head == NULL) { 
        cout << "List is empty" << endl;
        return true;
    }
    
    Node *node = head->next;
    
    while(node != NULL && node != head)
    {
        node = node->next;
    }
    return (head == node);
    
}

void splitList(Node *head, Node **head1, Node **head2)
{
    
Node *fast_ptr = head;
Node *slow_ptr = head;
if(head == NULL)  
        return;  

while(fast_ptr->next != head  && 
        fast_ptr->next->next != head)
{
    fast_ptr = fast_ptr->next->next;
    slow_ptr = slow_ptr->next;
}
  
//if it is on find the end 
if(fast_ptr->next->next == head) {
    fast_ptr = fast_ptr->next;
}

//set the first half head
*head1 = head;

//set the second of head;
if(head->next != head)
    *head2 =  slow_ptr->next;

//second Circular
fast_ptr->next = slow_ptr->next;

//first Circular
slow_ptr->next = head;


}


int
main ()
{
  Node *head = NULL;
  Node *second = NULL; 
  Node *third = NULL;
  Node *four = NULL;
  Node *five = NULL;
  Node *six = NULL;

  head = new Node;
  second = new Node;
  third = new Node;
  four = new Node;
  five = new Node;
  six = new Node;
 
  
  head->data = 10;
  head->next = second;

  second->data = 20;
  second->next = third;

  third->data = 30;
  third->next = four;
  
  four->data = 40;
  four->next = five;
  
  five->data = 50;
  five->next = head;

  six->data = 60;
  six->next = head;


  print_linkedlist (head);
  
  cout << "\nIs List is Circular : " << ( isCircular(head) ? "True":"False") << endl;
  
  
  Node *head1 = NULL;
  Node *head2 = NULL;
  
  
  splitList(head, &head1, &head2);
  
  print_linkedlist(head1);
  
  print_linkedlist(head2);
  
  
  
  

  delete head;
  delete second;
  delete third;
  delete four;
  delete five;

  return 0;
}
