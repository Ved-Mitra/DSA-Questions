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
Node* reverseLL_iterative(Node* head)
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
    Node* prev=nullptr,*front=nullptr;
    while(temp!=nullptr)
    {
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* reverseLL_recursive(Node* head)
{
    if(head==nullptr || head->next==nullptr)
        return head;
    Node* newHead=reverseLL_recursive(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=nullptr;
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