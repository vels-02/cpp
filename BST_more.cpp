/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue> 
#include <limits.h>
using namespace std;



class Node
{
    public:
        int data;
        Node* left;
        Node* right;
};


Node* CreateNewNode(int x)
{
    Node* new_node = new Node;
    new_node->data = x;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void InsertNode(Node** node, int val)
{
    
    if(*node == NULL)
    {
        Node* temp = CreateNewNode(val);
        *node = temp;
        return;
    }
    
    if( val <= (*node)->data )
    {
        InsertNode(&(*node)->left, val);
    }
    else
    {
        InsertNode(&(*node)->right, val);

    }


    
}

void printBST(Node* node){
    if(node == NULL) return;
    
    cout << node->data << " ";
    printBST(node->left);
    printBST(node->right);
    
}

void printBST_bfs(Node* node){
    if(node == NULL) return;

    queue<Node*> nq;
    
    nq.push(node);
    
    while( !nq.empty())
    {
        Node* n = nq.front();
        cout << n->data << " ";
        if(n->left != NULL) 
            nq.push(n->left);
        if(n->right != NULL)
            nq.push(n->right);
        nq.pop();
    }
    
    cout << endl;
}



bool search(Node* node, int x)
{
    if(node == NULL ) return false;
    
    if(node->data == x) return true;
    
    bool res;
    if( x < node->data) 
    {
        return search(node->left, x);   
    }
    else
    {
        return search(node->right, x); 
    }
    
}


int FindMin(Node* node)
{
    if(node == NULL) return -1;
    
    if(node->left == NULL)
        return node->data;
        
    if(node->left != NULL)
        return FindMin(node->left);
}

Node* FindMinNode(Node* node)
{
    if(node == NULL) return node;
    
    if(node->left == NULL)
        return node;
        
    if(node->left != NULL)
        return FindMinNode(node->left);
}

int FindMax(Node* node)
{
    if(node == NULL) return -1;
    
  
    if(node->right == NULL)
    {
        
        return node->data;
    }
        
    if(node->right != NULL)
    {
        return FindMax(node->right);
    }
}

Node* delete_node(Node* node, int val)
{
    if(node == NULL) 
    {
        cout << " node is NULL ..so return node" << endl;
        return node;
    }
    
    if(val < node->data) 
    {
        node->left = delete_node(node->left, val);
    }
    else if(val > node->data)
    {
         node->right = delete_node(node->right, val);
    }
    else
    {
        cout << "found value " << endl;
        //if leaf node
        if(node->left == NULL && node->right == NULL)
        {
            cout << "leaf" << endl;
            delete node;
            node = NULL;
        }
        else if(node->right == NULL)
        {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else if(node->left == NULL)
        {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else
        {
            Node* temp = FindMinNode(node->right);
            node->data = temp->data;
            node->right  = delete_node(node->right, temp->data);
        }
    }
    
    return node;
}

bool issubtreeLessor(Node* node,int value)
{
    if(node == NULL) return true;
     if(  node->data < value &&  
            issubtreeLessor(node->left, value) && 
                issubtreeLessor(node->right, value) )
                {
                    return true;
                }
                else return false;
}

bool issubtreeGreater(Node* node,int value)
{
    if(node == NULL) return true;
        if( node->data > value  &&  
            issubtreeGreater(node->left, value) && 
                issubtreeGreater(node->right, value) )
                {
                    return true;
                }
                else return false;

}

bool isBST(Node* root)
{
    
    if(root == NULL) return true;
    if( issubtreeLessor(root->left, root->data ) &&
        issubtreeGreater(root->right, root->data) &&
        isBST(root->left) &&
        isBST(root->right) )
    {
        return true;
    }
    else
        return false;
}

bool isBST_range(Node* root,int min, int max)
{
    
    if(root == NULL) return true;
    if( root->data > min  &&
        root->data < max &&
        isBST_range(root->left,min, root->data ) &&
        isBST_range(root->right,root->data, max) )
    {
        return true;
    }
    else
        return false;
}

int main()
{


    Node* root = NULL;
    
 /*   InsertNode(&root, 30);
    InsertNode(&root, 58);
    InsertNode(&root, 25);
    InsertNode(&root, 10);
    InsertNode(&root, 40);
    InsertNode(&root, 20);
    InsertNode(&root, 50);
    InsertNode(&root, 1);*/
    
    
    InsertNode(&root, 12);
    InsertNode(&root, 5);
    InsertNode(&root, 15);
    InsertNode(&root, 3);
    InsertNode(&root, 7);
    InsertNode(&root, 13);
    InsertNode(&root, 17);
    InsertNode(&root, 1);
    InsertNode(&root, 9);
    InsertNode(&root, 19);
    
    /*
             30
           /    \
          25     58
        /       /     
      10      40
     /       /  \
    1       20   50
    */
    

    
    
    if( search(root, 58) ) 
        cout<< "\n58 present" << endl;
    else
        cout << "\nnot present" << endl;


    cout << "Min Value of tree is " << FindMin(root) << endl;
    cout << "Max Value of tree is " << FindMax(root) << endl;
    
    printBST_bfs(root);
    
    //root = delete_node(root, 1);
    root = delete_node(root, 15);

    
    printBST_bfs(root);
    
    
    
    cout << "Is BST " <<  isBST(root) << endl;
    
    cout << "Is BST - method2 " << isBST_range(root, INT_MIN, INT_MAX);

    return 0;
}
