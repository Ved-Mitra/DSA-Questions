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
Node* removeDuplicatesSortedDLL(Node* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            if(temp==head)
            {
                Node* delNode=head;
                head=head->next;
                head->back=NULL;
                delete delNode;
            }
            Node* nextNode=temp->next;
            Node* prevNode=temp->back;

            if(prevNode)
                prevNode->next=nextNode;
            if(nextNode)
                nextNode->back=prevNode;
            delete temp;
            temp=nextNode;
        }
        temp=temp->next;
    }
    return head;


    //METHOD-2
    while(temp!=NULL && temp->next!=NULL)
    {
        Node* nextNode=temp->next;
        while(nextNode!=NULL && nextNode->data==temp->data)
        {
            Node* duplicate=nextNode;
            nextNode=nextNode->next;
            free(duplicate);
        }
        temp->next=nextNode;
        if(nextNode!=NULL) 
            nextNode->back=temp;
    }
    return head;
}

int main()
{
    vector<int> arr={1,4,5,78};
    Node* head=createArrayToDLL(arr);

    return 0;
}