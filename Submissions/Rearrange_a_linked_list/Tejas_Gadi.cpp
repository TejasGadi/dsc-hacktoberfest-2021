#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;
    //Default constructor without any parameters
    node()
    {
        data=0;
        next=NULL;
    }
    //Parameterized constructor with val as parameter
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insert_at_tail(node *head,int val)
{
    node* ptr=new node(val);
    
    node* h=head;
    
    while(h->next!=NULL)
    {
        h=h->next;
    }
    h->next=ptr;
}

void display(node* head)
{
    node* h=head;
    while(h!=NULL)
    {
        cout<<h->data<<"->";
        h=h->next;
    }
    cout<<"NULL"<<endl;
}
void rearrange_even_after_odd(node* head)
{
    node* odd=head;
    node* even=head->next;
    node* even_first=even;
    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next =even_first;
    if(odd->next==NULL)
    {
        even->next=NULL;
    }
}
int main()
{
    int n,t=0,incr=0;
    node* head;
    cout<<"Enter the number of elements of LinkedList:"<<endl;
    cin>>n;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(incr==0)
        {
            head=new node(t);
            incr++;
            continue;
        }
        insert_at_tail(head,t);
    }
    cout<<"Linked list:"<<endl;
    display(head);
    rearrange_even_after_odd(head);
    cout<<"Linked list after Rearranging:"<<endl;
    display(head);

    return 0;
}