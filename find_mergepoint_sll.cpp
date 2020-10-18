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
    Node *next;
    
    Node(int x) : data{x}, next{nullptr} {}
};




Node* insertNode(Node *root, int x)
{
    
    Node* new_node = new Node(x);
    
    if(root == nullptr)
    {
        root = new_node;
        return root; 
    }
    
    Node* tmp = root;
    
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    
    tmp->next = new_node;
    return  root;
}

void printlist(Node* root)
{
    if(root == nullptr) { cout << endl; 
    return; }
    
    cout << root->data << " ";
    printlist(root->next);
    
}


int findLength(Node* root)
{
    
    if(root == nullptr) return -1;
    int count = 0;;
    
    while(root != nullptr)
    {
        count++;
        root = root->next;
        
    }
    
    return count;
}


Node* findMergePoint(Node *A, Node *B)
{
    
    int m = findLength(A);
    int n = findLength(B);
    
    int d = n -  m;
    
    cout << m << " " << n << " " << d << endl;
    
    
    if(m > n)
    {
        Node *temp = A;
        A = B;
        B = temp;
        d = m - n;
    }
    
    for(int i=0; i < d; i++)
    {
        B = B->next; 
    }
    
    while(A != NULL && B != NULL)
    {
        if( A == B )
        {
            return A;
        }
        
        A = A ->next;
        B = B ->next;
    }
    
    return nullptr;
    
}

int main()
{
    
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    
 /*   int N, N1,x;
    
    cin >> N;
    
    while(N--)
    {
        cin >> x;
        head1 = insertNode(head1, x);
    }

    printlist(head1);

   cin >> N1;
   while(N1--)
    {
        cin >> x;
        head2 = insertNode(head2, x);
    }

    printlist(head2);
    
    
    */
    Node *temp[7];
    for(int i=0;i<7;i++) {
        temp[i] = new Node(0);
    }
    temp[0]->data = 4;
    temp[0]->next = temp[1];
    temp[1]->data = 6;
    temp[1]->next = temp[2];
    temp[2]->data = 7;
    temp[2]->next = temp[3];
    temp[3]->data = 1;
    temp[3]->next = NULL;
    temp[4]->data = 9;
    temp[4]->next = temp[5];
    temp[5]->data = 3;
    temp[5]->next = temp[6];
    temp[6]->data = 5;
    temp[6]->next = temp[3];

    head1 = temp[0];
    head2 = temp[4];
    
    Node* node = findMergePoint(head1, head2);
    
    if(node != nullptr)
        cout << "Merging node is : "  << node->data << endl;
    
    
    return 0;
}
