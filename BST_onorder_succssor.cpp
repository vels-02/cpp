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
        Node *left;
        Node *right;
        
        Node(int x) : data{x}, left{nullptr}, right{nullptr} {}
};


Node* insertNode(Node* head, int x)
{
    if(head  == nullptr )
        return new Node(x);
    
    if(x > head->data) 
    {
        head->right = insertNode(head->right, x);
    }
    else
    {
        head->left = insertNode(head->left, x);
    }
    
    return head;
}

//LDR
void printInOrder(Node* node)
{
    if(node == nullptr) return;
    
    printInOrder(node->left);
    cout << node->data << " ";
    printInOrder(node->right);
    
}

Node* Find(Node* head, int n)
{
    if(head == nullptr) return nullptr;
    if(n == head->data) return head;
    
    if( n > head->data) return Find(head->right, n);
    else
        return Find(head->left, n);
    
}

Node* FindMin(Node* head)
{
  if(head == nullptr) return nullptr;
  
  while(head->left != nullptr)
  {
      head = head->left;
  }
  return head;
  
}

Node* findSuccessor(Node* head, int data)
{
    Node* current = Find(head, data);
    if(current == nullptr) return nullptr;
    
    // if it has right sub tree  - then right left most is the findSuccessor
    if(current->right != nullptr)
        return FindMin(current->right);
    
    // it has no right subtree
    Node* successor;
    Node* ancester = head;
    
    while( ancester != current)
    {
        if(current->data < ancester->data)
        {
            successor = ancester;
            ancester = ancester->left;
        }
        else
            ancester = ancester->right;
    }
    
    return successor;
    
}

int main()
{

    Node *head = nullptr;
    int n, x;
    cin >> n;
    
    for(int i=0; i < n; i++)
    {
        cin >> x;
        head = insertNode(head, x);
    }
    
    printInOrder(head);
    
    Node *tmp = findSuccessor(head, 12);
    
    cout <<  "\nIn order successor of 12 : " << tmp->data << endl;

    
    return 0;
}
