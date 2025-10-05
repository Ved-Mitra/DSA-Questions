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
vector<pair<int,int>> findAllPairsWithGivenSumInDLL(Node* head,int sum)
{
    //given head of sorted DLL return all pairs with sum 
    vector<pair<int,int>> ans;
    if(head==NULL || head->next==NULL)
        return {{}};
    
    //BRUTE
    Node* temp1=head;
    while(temp1!=NULL)
    {
        Node* temp2=temp1->next;
        while(temp2!=NULL && (temp1->data + temp2->data <= sum))
        {
            if(temp1->data + temp2->data == sum)
            {
                ans.push_back({temp1->data,temp2->data});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return ans;


    //OPTIMAL
    Node* left=head;
    Node* right=head;
    while(right->next!=NULL)
        right=right->next;
    while(left->data <= right->data)
    {
        int add=left->data + right->data;
        if(add<sum)
            left=left->next;
        else if(add>sum)
            right=right->back;
        else
        {
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->back;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr={1,4,5,78};
    Node* head=createArrayToDLL(arr);

    return 0;
}