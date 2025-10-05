#include<bits/stdc++.h>
using namespace std;


class Node //I get benefits like data abstraction, polmorphism, etc
{
    public:
    int data;
    Node *next;
    Node *child;

    public:
    Node(int data1,Node *next1)
    {
        data=data1;
        next=next1;
        child=NULL;
    }

    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
        child=NULL;
    }

    public:
    Node(int data1,Node* next1,Node* child1)
    {
        data=data1;
        next=next1;
        child=child1;
    }

    public:
    Node(int data1,Node* child1)
    {
        data=data1;
        next=nullptr;
        child=child1;
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
Node* flattening_LL(Node* head)
{
    /*
    LL is given in like
    1. every child pointer is sorted
    2. next poiinter is not sorted

    like ll given:
    3 -> 2 -> 1 -> 4 -> 5-> NULL
    |    |    |    |    |
    NUL  10   7    9    6
         |    |    |    |
        NUL  11   NUL   8
              |         |
             12        NUL
              |
             NUL

    Convert it into a sorted LL in vertical i.e. in child pointer
    */

    //BRUTE
    //add them to array and sort then convert into LL


    //OPTIMAL
    //TC-O(n*m)
    //SC-O(1)
    //using property of sorted child LL
    if(head==NULL || head->next==NULL)
        return head;
    Node* temp=head;
    Node* newHead=head;
    while(temp->next!=NULL)
    {
        Node* temp2=temp->next;
        newHead=mergeTwoLists(newHead,temp2);
        temp=temp->next;
    }
    return newHead;

}
Node* mergeTwoLists(Node* list1, Node* list2)
{
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(list1!=NULL && list2!=NULL)
    {
        if(list1->data < list2->data)
        {
            temp->child=list1;
            temp=list1;
            list1=list1->child;
        }
        else
        {
            temp->child=list2;
            temp=list2;
            list2=list2->child;
        }
        temp->next=NULL;
    }
    if(list1)
        temp->child=list1;
    else
        temp->child=list2;
    return dummyNode->child;
}

int main()
{
    vector<int> arr={2,4,8,98,56,7};

    Node *head=convertArrayToLL(arr);

    return 0;
}