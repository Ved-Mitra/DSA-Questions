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

Node* oddEvenNodesLL(Node* head)
{
    if(head==NULL || head->next==NULL || head->next->next==NULL)
        return head;
    //BRUTE
    Node* temp=head;
    int nodes=0;
    while(temp!=NULL)
    {
        nodes++;
        temp=temp->next;
    }
    vector<int> hash(nodes);
    temp=head;
    int i=0;
    while(temp!=NULL)
    {
        hash[i]=temp->data;
        temp=temp->next;
        i++;
    }
    temp=head;
    i=0;
    int j=1;
    while(temp!=NULL)
    {
        if(i<nodes)
        {
            temp->data=hash[i];
            i+=2;
        }
        else if(j<nodes)
        {
            temp->data=hash[j];
            j+=2;
        }
        temp=temp->next;
    }
    return head;


    //OPTIMAL
    //link changing
    Node* even=head->next;
    Node* odd=head;
    Node* evenHead=head->next;
    while(odd->next!=NULL && odd->next->next!=NULL)
    {
        odd->next=odd->next->next;
        odd=odd->next;
        even->next=even->next->next;
        even=even->next;
    }
    odd->next=evenHead;
    if(even)
        even->next=NULL;
    return head;
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