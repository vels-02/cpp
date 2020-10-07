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
  if (lst == NULL)
    cout << "List is empty";
  while (lst)
    {
      cout << lst->data << ' ';
      lst = lst->next;
    }

}



int
main ()
{
  Node *head = NULL;
  Node *second = NULL;
  Node *third = NULL;

  head = new Node;
  second = new Node;
  third = new Node;

  head->data = 10;
  head->next = second;

  second->data = 20;
  second->next = third;

  third->data = 30;
  third->next = NULL;

  print_linkedlist (head);

  delete head;
  delete second;
  delete third;

  return 0;
}
