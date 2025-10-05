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
Node* add2NumbersLL(Node* num1,Node* num2)
{
    Node* dummyNode=new Node(-1);
    Node* curr=dummyNode;
    Node* temp1=num1;
    Node* temp2=num2;
    int carry=0;
    while(temp1!=NULL || temp2!=NULL)
    {
        int sum=carry;
        if(temp1)
            sum+=temp1->data;
        if(temp2)
            sum+=temp2->data;
        Node *newNode=new Node(sum%10);
        carry=sum/10;
        curr->next=newNode;
        curr=curr->next;
        if(temp1)
            temp1=temp1->next;
        if(temp2)
            temp2=temp2->next;
    }
    if(carry)
    {
        Node *newnNode=new Node (carry);
        curr->next=newnNode;
    }
    return dummyNode->next;
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