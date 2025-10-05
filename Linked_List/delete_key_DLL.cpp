#include<bits/stdc++.h>
using namespace std;


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
Node* deleteAllOccurenceOfKeyInDLL(Node* head,int key)
{
    Node* temp=head;
    if(temp->data==key)
    {
        Node* newHead=head->next;
        newHead->back=NULL;
        head->next=NULL;
        free(head);
        return newHead;
    }
    Node* prev=temp;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            prev=temp->back;
            prev->next=temp->next;
            if(temp->next!=NULL)
                temp->next->back=prev;
            free(temp);
            temp=prev->next->next;
        }
        else
            temp=temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr={1,4,5,78};
    Node* head=createArrayToDLL(arr);

    //cout << head->data << endl;

    
    return 0;
}