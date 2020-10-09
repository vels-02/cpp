/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <memory>

struct Node 
{
  
  int  data;
  struct Node *next;
    
};

struct Node* addtoEmpty(Node *list, int x)
{
    struct Node *tmp = (struct Node*)malloc(sizeof(Node));
    
    tmp->data = x;
    list = tmp;
    list->next = list;
    
    return list;
    
}

struct Node* addtoBegin(Node *list, int x)
{
 
    if(list == NULL )
    {
     return addtoEmpty(list,x);
    }
    
    struct Node *tmp = (struct Node*)malloc(sizeof(Node));
    tmp->data = x;
    tmp->next = list->next;
    list->next = tmp;
    
    return list;
    
}

struct Node* addtoEnd(Node *list, int x)
{
    if(list == NULL )
    {
     return addtoEmpty(list,x);
    }
    
    struct Node *temp = (struct Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = list->next;
    list->next = temp;
    list = temp;
    
    return list;
}

struct Node* addAfter(Node *list, int data, int item)
{
    if(list == NULL ) return NULL;
    
    struct Node *p;
    struct Node *temp;
    
    p = list->next;
    
    do {
        if(p->data == item)
        {
            temp = (struct Node*)malloc(sizeof(Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            
            if(p == list)
                list = temp;
            return list;
        }
        p = p->next;
    }while(p != list->next);

   printf(" not present in the list. \n");
}


void traverse(struct Node *list)
{
    
    struct Node *p;
    
    if(list == NULL ) { 
        printf("List is empty \n");;
    }
    else 
    {
        p = list->next;
        do
        {
            printf("%d ", p->data);
            p = p->next ;
        } while(p != list->next);
    }
    
}

int main()
{
    struct Node *list = NULL;
    
    list = addtoEmpty(list, 10);
    list = addtoBegin(list, 5);
    list = addtoEnd(list, 20);
    list = addtoBegin(list, 3);
    list = addtoBegin(list, 2);
    list = addtoBegin(list, 1);
    list = addAfter(list, 17, 10);
    list = addAfter(list, 18, 17);
    
    
    
    traverse(list);
    

    return 0;
}
