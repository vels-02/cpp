/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


class Node {
  public:
    int data;
    Node *left;
    Node *right;
    
    Node(int v) : data{v}, left{nullptr},right{nullptr} {}
    
};


//LNR
void printInorder(Node *head)
{
    if( head == nullptr) return;
    printInorder(head->left);
    cout << head->data << " " ;
    printInorder(head->right);
    
}


Node* inserNode(Node* head, int data)
{
    
    if(head == nullptr) return new Node(data);
    
    //new value is small put it in left
    if(head->data > data) {
        head->left = inserNode(head->left, data);
    }
    else
    {
        head->right = inserNode(head->right, data);
    }
    
    
    return head;
    
}


int main()
{
    
    int N, val;
    cin >> N;
    cin >> val;
    N--;
    Node* head = inserNode(nullptr, val);
    
    while(N--)
    {
        cin >> val;
        inserNode(head, val);
    }
    
    printInorder(head);

    return 0;
}
