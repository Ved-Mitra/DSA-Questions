#include<bits/stdc++.h>
using namespace std;


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
Node* sort012LL(Node* head)
{
    //BRUTE
    //COUNT 0,1,2 and then assign values

    Node* LL_0=new Node(-1);
    Node* LL_1=new Node(-1);
    Node* LL_2=new Node(-1);
    Node* temp0=LL_0;
    Node* temp1=LL_1;
    Node* temp2=LL_2;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            LL_0->next=temp;
            LL_0=temp;
        }
        else if(temp->data==1)
        {
            LL_1->next=temp;
            LL_1=temp;
        }
        else
        {
            LL_2->next=temp;
            LL_2=temp;
        }
        temp=temp->next;
    }
    LL_0->next=(temp1->next)? (temp1->next):(temp2->next);
    LL_1->next=temp2->next;
    LL_2->next=NULL;
    Node* newHead=temp0->next;
    delete temp0;
    delete temp1;
    delete temp2;
    return newHead;
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