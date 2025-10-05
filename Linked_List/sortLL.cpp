#include<bits/stdc++.h>
using namespace std;

//TC-N*log N
//SC-O(N)


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

Node* middleNode(Node* head)
{
    Node* fast=head;
    Node* slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node* merge_LL(Node* list1,Node* list2)
{
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(list1!=NULL && list2!=NULL)
    {
        if(list1->data < list2->data)
        {
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else
        {
            temp->next=list2;
            temp=list2;
            list2=list2->next;
        }
    }
    if(list1)
        temp->next=list1;
    else
        temp->next=list2;
    return dummyNode->next; 
}
Node* mergeSort_LL(Node* head)
{
    //BRUTE
    //add element to array and then sort and assign

    //OPTIMAL
    if(head==NULL || head->next==NULL)
        return head;
    Node* mid=middleNode(head);
    Node* leftHead=head;
    Node* rightHead=mid->next;
    mid->next=NULL;
    leftHead=mergeSort_LL(leftHead);
    rightHead=mergeSort_LL(rightHead);
    return merge_LL(leftHead,rightHead);
}

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    vector<int> arr(n);
    cout  << "Enter the elements of the array : " << endl;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    Node* head=convertArrayToLL(arr);
    
}