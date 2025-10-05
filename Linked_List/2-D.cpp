#include<bits/stdc++.h>
using namespace std;

/*
struct Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    public:
    Node(int data1,Node *next1,*prev1)
    {
        data=data1;
        next=next1;
        prev=prev1;
    }
};
*/

class Node //I get benefits like data abstraction, polmorphism, etc
{
    public:
    int data;
    Node *next;
    Node *back;

    public:
    Node(int data1,Node *next1,Node *back1)
    {
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node* createArrayToDLL(vector<int> &arr)
{
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++)
    {
        Node *temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
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
Node* deleteInDLL_Pos(Node* head,int pos)
{
    if(head==NULL)
        return head;
    if(pos==1) //delete head
    {
        Node* temp=head;
        head=head->next;
        if(head)
            head->back=nullptr;
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
            prev->next=temp->next;
            if(temp->next)
                temp->next->back=prev;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* deleteInDLL_Value(Node* head, int target)
{
    if(head==NULL)
        return head;
    if(head->data==target) //delete head
    {
        Node* temp=head;
        head=head->next;
        if(head)
            head->back=nullptr;
        delete temp; // or free(temp)
        return head;
    }
    Node *temp=head,*prev=NULL;
    while(temp!=NULL)
    {
        if(temp->data==target)
        {
            prev->next=prev->next->next;
            if(temp->next)
                temp->next->back=prev;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* insertInDLL_Pos(Node* head,int pos,int val)
{
    if(pos==1)
    {
        Node* temp=new Node(val,head,nullptr);
        head->back=temp;
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
            temp1->back=temp;
            if(temp->next)
                temp->next->back=temp1;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node* insertInDLL_Value(Node* head, int val,int target)
{
    //Insert before Value
    if(head==NULL)
        return NULL;
    if(head->data==target)
    {
        Node* temp=new Node(val,head,nullptr);
        head->back=temp;
        return temp;
    }
    Node* temp=head;
    while(temp!=NULL && temp->next!=nullptr)
    {
        if(temp->next->data==target)
        {
            Node* temp1=new Node(val);
            temp1->next=temp->next;
            temp->next=temp1;
            temp1->back=temp;
            if(temp->next)
                temp->next->back=temp1;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node* reverseInDLL(Node* head)
{
    Node* temp=head;

    //BRUTE
    stack<int> st;
    while(temp!=nullptr)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr)
    {
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;

    //OPTIMAL
    temp=head;
    Node* swap=nullptr;
    Node* prev=nullptr;
    while(temp!=nullptr)
    {
        swap=temp->next;
        temp->next=temp->back;
        temp->back=swap;
        prev=temp;
        temp=temp->back;
    }
    return prev->back;
}

int main()
{
    vector<int> arr={1,4,5,78};
    Node* head=createArrayToDLL(arr);

    //cout << head->data << endl;

    Node *temp=insertInDLL_Value(head,2,10);
    while(temp!=NULL)
    {
        cout << temp->data << " " ;
        temp=temp->next;
    }
    return 0;
}