#include<bits/stdc++.h>
using namespace std;

/*
struct Node
{
    public:
    int data;
    Node *next;

    public:
    Node(int data1,Node *next1)
    {
        data=data1;
        next=next1;
    }
};
*/

class Node //I get benefits like data abstraction, polmorphism, etc
{
    public:
    int data;
    Node *next;

    public:
    Node(int data1,Node *next1)
    {
        data=data1;
        next=next1;
    }

    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};

Node* convertArrayToLL(vector<int> &arr)
{
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void transverseLL(Node *head)
{
    Node *temp=head;
    while(temp!=nullptr)
    {
        cout << temp->data << endl;
        temp=temp->next;
    }
}
int lengthOfLL(Node *head)
{
    int cnt=0;
    Node *temp=head;
    while(temp!=nullptr)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
bool Search(Node *head,int target)
{
    Node *temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==target)
            return true;
        temp=temp->next;
    }
    return false;
}
Node* deleteInLL_Pos(Node *head,int pos)
{
    if(head==NULL)
        return head;
    if(pos==1) //delete head
    {
        Node* temp=head;
        head=head->next;
        delete temp; // or free(temp)
        return head;
    }
    Node *temp=head,*prev=NULL;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==pos)
        {
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* deleteInLL_Value(Node* head, int target)
{
    if(head==NULL)
        return head;
    if(head->data==target) //delete head
    {
        Node* temp=head;
        head=head->next;
        delete temp; // or free(temp)
        return head;
    }
    Node *temp=head,*prev=NULL;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        if(temp->data==target)
        {
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* insertInLL_Pos(Node* head,int pos,int val)
{
    if(pos==1)
    {
        Node* temp=new Node(val,head);
        return temp;
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==pos-1)
        {
            Node* temp1=new Node(val);
            temp1->next=temp->next;
            temp->next=temp1;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node* insertInLL_Value(Node* head, int val,int target)
{
    //Insert before Value
    if(head==NULL)
        return NULL;
    if(head->data==target)
    {
        Node* temp=new Node(val,head);
        return temp;
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        if(temp->next->data==target)
        {
            Node* temp1=new Node(val);
            temp1->next=temp->next;
            temp->next=temp1;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node* reverseLL(Node* head)
{
    Node* temp=head;
    Node* prev=nullptr;
    while(temp)
    {
        Node* node=temp;
        temp=temp->next;
        node->next=prev;
        prev=node;
    }
    return prev;
}

int main()
{
    vector<int> arr={2};
    /*
    Node *y= new Node(arr[0],nullptr); //creating a pointer
    cout << y << endl;
    cout << y->data << endl;

    Node x=Node(arr[1],nullptr); //Creating an object
    cout << x.data << endl;
    */

    Node *head=convertArrayToLL(arr);
    //cout << head->data << endl;

    //LINKED LIST is 1-indexed

    Node* temp=deleteInLL_Pos(head,1);
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
    return 0;
}