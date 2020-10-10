/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Binary
{
    public:
    
    int data;
    Binary *left, *right;
    
    Binary(int val) : data{val}, left{nullptr}, right{nullptr} {}
};

//NLR
void print_preorder(Binary *binary)
{
    if(binary == nullptr)
        return;
    cout << binary->data << "  ";
    print_preorder(binary->left);
    print_preorder(binary->right);
    
}

//LNR
void print_inorder(Binary *binary)
{
    if(binary == nullptr)
        return;
    print_inorder(binary->left);
    cout << binary->data << "  ";
    print_inorder(binary->right);
    
}

//LRN
void print_postorder(Binary *binary)
{
    if(binary == nullptr)
        return;
    print_postorder(binary->left);
    print_postorder(binary->right);
    cout << binary->data << "  ";
    
}


int main()
{
    
    Binary *root = new Binary(1);
    Binary *left = new Binary(2);
    Binary *right = new Binary(3);
    Binary *leftleft = new Binary(4);
    Binary *leftright = new Binary(5);
    Binary *rightleft = new Binary(6);
    Binary *rightright = new Binary(7);
    
    root->left = left;
    root->right = right;
    left->left = leftleft;
    left->right = leftright;
    right->left = rightleft;
    right->right = rightright;
    
    print_preorder(root);
    cout << endl;
    print_inorder(root);
    cout << endl;
    print_postorder(root);
    cout << endl;
    
    delete(root);
    delete(left);
    delete(right);
    delete(leftleft);
    delete(leftright);
    delete(rightleft);
    delete(rightright);
    
    return 0;
}
