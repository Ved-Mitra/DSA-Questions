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

Node* inersection2LL(Node* headA,Node* headB)
{
    //BRUTE
    Node* temp1=headA;
    Node* temp2=headB;
    unordered_set<Node*> st;
    while(temp1!=NULL)
    {
        st.insert(temp1);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        if(st.find(temp2)!=st.end())
            return temp2;
        temp2=temp2->next;
    }
    return NULL;


    //BETTER
    temp1=headA;
    temp2=headB;
    map<Node*,int>hash;
    while(temp1!=NULL)
    {
        hash[temp1]++;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        hash[temp2]++;
        if(hash[temp2]>1)
            return temp2;
        temp2=temp2->next;
    }
    return NULL;


    //OPTIMAL
    temp1=headA;
    temp2=headB;
    int count1=0,count2=0;
    while(temp1!=NULL)
    {
        count1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        count2++;
        temp2=temp2->next;
    }
    Node* ans=nullptr;
    if(count1<count2)
    {
        ans=collisionNode(headA,headB,count2-count1);
    }
    else
    {
        ans=collisionNode(headB,headA,count1-count2);
    }
    return ans;



    //MOST OPTIMAL
    temp1=headA;
    temp2=headB;
    if(headA==NULL || headB==NULL)
        return NULL;
    while(temp1!=temp2)
    {
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2)
            return temp1;
        if(temp1==NULL)
            temp1=headB;
        if(temp2==NULL)
            temp2=headA;
    }
    return temp1;
}
Node* collisionNode(Node* s_head,Node* b_head,int diff)
{
    Node* temp1=s_head;
    Node* temp2=b_head;
    int count=0;
    while(count<diff && temp2!=NULL)
    {
        temp2=temp2->next;
        count++;
    }
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1==temp2)
            return temp1;
        temp1=temp1->next;
        temp2=temp2->next;
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