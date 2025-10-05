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
Node* startPointLL(Node* head)
{
    //BRUTE
    unordered_map<Node*,int>hash;
    Node *temp=head;
    while(temp!=NULL)
    {
        hash[temp]++;
        if(hash[temp]>1)
            return temp;
        temp=temp->next;
    }
    return NULL;


    //OPTIMAL
    //Tortoise and Hare algorithm
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            slow=head;
            while(fast!=slow)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
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