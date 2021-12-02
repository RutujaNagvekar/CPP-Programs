#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class Stack     // Singly Linear Linked List
{
private:
    PNODE first;
    int size;
    
public:
    Stack()
    {
        first = NULL;
        size = 0;
    }
    
    void push(int no)   // InsertFirst()
    {
        PNODE newn = new NODE;
        
        newn -> data = no;
        newn -> next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn -> next = first;
            first = newn;
        }
        size++;
    }
    
    int pop()   // DeleteFirst()
    {
        PNODE temp = first;
        int pno = 0;
        
        if(size == 0)
        {
            cout<<"Stack is empty\n";
            return -1;
        }
        
        if(size == 1)
        {
            pno = first -> data;
            delete first;
            first = NULL;
        }
        else
        {
            pno = first -> data;
            first = first -> next;
            delete temp;
        }
       size--;
       return pno;       
    }
    
    void Display()
    {
        PNODE temp = first;
        
        while(temp != NULL)
        {
            cout<<"|"<<temp -> data<<"|"<<"\n";
            temp = temp -> next;
        }
        cout<<"\n";
    }
    
    int Count()
    {
        return size;
    }
};

int main()
{
    Stack obj;
    
    obj.push(11);
    obj.push(21);
    obj.push(51);
    obj.push(101);
    
    cout<<"Elements of stack\n";
    obj.Display();
    
    int iret = obj.pop();       // 101
    cout<<"Popped element is : "<<iret<<"\n";                     // 101
    
    cout<<"Elements of stack\n";
    obj.Display();          // 51       21      11
    iret = obj.Count();
    
    cout<<"Size of stack is : "<<iret<<"\n";        // 3
    
    return 0;
}
