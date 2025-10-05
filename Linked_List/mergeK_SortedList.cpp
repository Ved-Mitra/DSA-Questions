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
Node* mergeTwoLists(Node* list1, Node* list2)
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
Node* mergeKLists_SCOptimized(vector<Node*>& lists)
{
    int n=lists.size();
    if(n==0)
        return NULL;
    Node *list1=lists[0];
    for(int i=1;i<n;i++)
    {
        list1=mergeTwoLists(list1,lists[i]);
    }
    return list1;
}
Node* mergeKLists_TCOptimized(vector<Node*>lists)
{
    int n=lists.size();
    if(n==0)
        return NULL;
    int m=0;
    for(int i=0;i<n;i++)
    {
        Node *temp=lists[i];
        while(temp!=NULL)
        {
            m++;
            temp=temp->next;
        }
    }
    vector<int> arr(m);
    int j=0;
    for(int i=0;i<n && j<m;i++)
    {
        Node *temp=lists[i];
        while(temp!=NULL && j<m)
        {
            arr[j]=temp->data;
            j++;
            temp=temp->next;
        }
    }
    sort(arr.begin(),arr.end());
    j=0;
    Node* dummyNode=new Node(-1);
    Node* temp1=dummyNode;
    while(j<m)
    {
        Node* temp=new Node(arr[j]);
        j++;
        temp1->next=temp;
        temp1=temp;
    }
    return dummyNode->next;
}
Node* mergeKLists_SC_TC_Optimized(vector<Node*>lists)
{
    //MIN-HEAP --> a data structure that returns  the minimum
    //priority queue
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
    for(int i=0;i<lists.size();i++)
        if(lists[i])
            pq.push({lists[i]->data,lists[i]});
    Node* dummyNode=new Node (-1);
    Node* temp=dummyNode;
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        if(it.second->next)
            pq.push({it.second->next->data,it.second->next});
        temp->next=it.second;
        temp=temp->next;
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