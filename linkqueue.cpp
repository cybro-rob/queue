#include<iostream>
using namespace std;

class Queue;

class Node
{
    int data;
    Node *link;
  public:
    
    friend void enqueue(Queue &);
    friend int dequeue(Queue &);  
    friend void display(Queue &);
};
class Queue
{
    Node *front,*rear,*prev,*temp;
   
  public:
    Queue()
    {
       front=NULL;
       rear=NULL;
       prev=NULL;
       temp=NULL;
    }
    friend void enqueue(Queue &);
    friend int dequeue(Queue &);  
    friend void display(Queue &);

    
};

void enqueue(Queue &t)
{
    Node *ref=t.front;
    cout<<"enter data ";
    int new_data;
    cin>>new_data;
    if(ref==NULL)
    {
        ref=new Node();
        
        ref->data=new_data;
        ref->link=NULL;
        t.front=ref;
        t.rear=ref;       

    }
    else
    {
        Node *new_node;
        ref=t.rear;
        
        new_node=new Node();
        new_node->data=new_data;
        new_node->link=NULL;
        ref->link=new_node;
    
        t.rear=new_node;
        
    }
    
}
int dequeue(Queue &t)
{
    int r=0;
    Node *ft=t.front;
    if(ft==NULL)
    {
        cout<<"no deletion possible "<<endl;

    }
    else
    {
    
        r=ft->data;
        t.front=ft->link;
        
        free(ft);
        
    }
    return r;
}
void display(Queue &t)
{
    Node *tempo=t.front;
    int i=1;
    while(tempo!=NULL)
    {
        
        cout<<"at "<<i<<" place data = "<<tempo->data<<endl;
        tempo=tempo->link;
        i++;
    } 
    
}
int main()
{
    Queue q;
    
  tap:  
    cout<<"press 1. to add a new node in queue "<<endl;
    cout<<"press 2. to delete a node from queue "<<endl;
    cout<<"press 3.to end program "<<endl;
    int t ;
    cin>>t;
    switch (t)
    {
        case 1:
        cout<<"enter how many element u want to enter :";
        int num,data;
        cin>>num;
        for(int i=0;i<num;i++)
        {
            enqueue( q );
        }
        display(q);    
        goto tap;
        case 2:
        cout<<"deleted element ";
        int deldata;
        deldata=dequeue(q);
        
        cout<<deldata<<endl;
        cout<<"list after deletion "<<endl;
        display(q);
        goto tap;
        case 3:
        cout<<"close the program "<<endl;
        break;



    }

    return 0;
}