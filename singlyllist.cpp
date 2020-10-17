/******************************************************************************

Singly linked list

1. insert node begin, end, after an element, at kth position
2 Delete a node begin, end. 

*******************************************************************************/

#include <iostream>

using namespace std;


class Node
{
  public:
    int data;
    Node *next;
};

Node *head = NULL;

Node* Reverse()
{
    Node *current, *prev=NULL , *next;
    
    if(head == NULL) return NULL;
    
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    
    
    return head;
    
}
Node* pre= NULL;
Node* reverse_recusrion(Node* head){
     //Node* newNode;
     if(head == NULL){
          //newNode = pre;   
          return pre;
     } 
 
     Node* temp = head->next;
     head->next = pre;
     pre = head;
     return reverse_recusrion(temp);
}


 Node* addtoEmpty(Node *list, int x)
{
    Node *tmp = new Node;
    
    tmp->data = x;
    list = tmp;
    list->next = NULL;
    
    return list;
    
}



void InsertNode(int x)
{
    
    Node* tmp = new Node();
    tmp->data = x;
    tmp->next = head;
    head = tmp;
}

void InsertEnd(int x)
{
    Node* tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    
    Node* tmp1 = head;
    while(tmp1->next != NULL)
    {
        tmp1 = tmp1->next;
    }
    
    tmp1->next = tmp;
    
}

Node* insertNodeEnd(Node* head, int x)
{
    Node *tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    if(head == NULL)
    {
        head = tmp;
        return head;
    }
    
    Node* tmp1 = head;
    while(tmp1->next != NULL)
    {
        tmp1 = tmp1->next;
    }
    tmp1->next = tmp;
    return head;
}

Node* insertNodeStart(Node* head, int x)
{
    Node *tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    if(head == NULL)
    {
        head = tmp;
        return head;
    }
    
    tmp->next = head;
    head = tmp;
    
    return head;
}

Node* insertNodeafter(Node* head, int pos, int x)
{

    if(head == NULL)
    {
        return head;
    }
    
    Node* tmp, *p = head;
    
    do {
        if(p->data == pos)
        {
            cout << "pos found" << endl;
            tmp = new Node();
            tmp->data = x;
            tmp->next = p->next;
            p->next = tmp;
            return head;
        }
        
        p = p->next;
        
    }while(p != NULL);
    
    return head;
}


Node* insertNodekthpos(Node* head, int pos, int x)
{
    Node *temp1 = new Node();
    temp1->data = x;
    temp1->next = NULL;
    
    //insert first
    if(pos == 1)
    {
        temp1->next = head;
        head = temp1;
        return head;
    }
    
    Node* temp2 = head;
    for(int i = 0; i < pos-2; i++)
    {
        temp2 = temp2->next;
    }
    
    temp1->next = temp2->next;
    temp2->next = temp1;
    
    return head;
}
Node* deleteatpos(Node* head, int pos)
{
    if(head == NULL) {
        cout << "list is empty"  << endl;
        return head;
    }
        
        if(pos == 1)
        {
            Node* tmp = head;
            head = tmp->next;
            delete tmp;
            return head;
        }
        
        Node* tmp1 = head;

        for(int i = 0; i < pos-2; i++)
        {
            tmp1 = tmp1->next;
        }
        
        Node *tmp2 = tmp1->next;
        tmp1->next = tmp2->next;
        delete tmp2;
        
        return head;
}


Node* deleteHead(Node* head)
{
    if(head == NULL)
    {
        cout << "head is null " << endl;
        return head;
    }
    
    Node* tmp = head;
    delete tmp;
    head = head->next;
    
    return head;
    
}


Node* deleteTail(Node* head)
{
    if(head == NULL)
    {
        cout << "head is null " << endl;
        return head;
    }
    if(head -> next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node* ptr = head;
        Node* ptr1;
        while(ptr->next != NULL)
        {
            ptr1  = ptr;
            ptr = ptr->next;
        }
        
        ptr1->next = NULL;
        delete ptr;
         
        return head;
    }
    
}




void printlist(Node* list)
{
    
    if(list == NULL ) { 
        printf("List is empty \n");;
    }
    
    Node* p  = list;
    
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    
    cout << endl;
}

void print_recursion(Node* node)
{

    if(node == NULL )
    {
        cout << endl;
        return;
    }
    cout << node->data << " ";
    print_recursion(node->next);
    

}

void print_reverse(Node* node)
{

    if(node == NULL )
    {
        return;
    }
    print_reverse(node->next);
    cout << node->data << " ";
    

}

int main()
{


/*
    InsertNode(10);
    InsertNode(20);
    InsertNode(30);
    InsertNode(40);
    InsertNode(50);
    
    InsertEnd(5);
*/

    Node *head1 = NULL;
    head1 = insertNodeEnd(head1, 5);
    head1 = insertNodeEnd(head1, 10);
    head1 = insertNodeEnd(head1, 20);
    head1 = insertNodeEnd(head1, 30);
    head1 = insertNodeEnd(head1, 40);
    head1 = insertNodeStart(head1, 4);
    
    head1 = insertNodeStart(head1, 3 );
    
    head1 = insertNodeafter(head1, 30, 35);
    head1 = insertNodeafter(head1, 30, 33);
    
    head1 = insertNodekthpos(head1, 1, 2);
    printlist(head1);
    
    head1 = insertNodekthpos(head1, 7, 25);
    
 
    

    printlist(head1);
    
    head1 = deleteHead(head1);
    printlist(head1);
    head1 = deleteHead(head1);
    printlist(head1);
    head1 = deleteHead(head1);
    printlist(head1);
    
    head1 = deleteTail(head1);
    printlist(head1);
    
    head1 = deleteatpos(head1, 4); //delete 4th node - 25*/
    printlist(head1);

    print_recursion(head1); 
    
    print_reverse(head1);
    cout << endl;
    

    head1 = reverse_recusrion(head1);
    printlist(head1);

 
    return 0;
}
