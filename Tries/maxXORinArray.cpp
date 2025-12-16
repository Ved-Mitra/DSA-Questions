#include <bits/stdc++.h>
using namespace std;

struct Node
{
   Node* links[2];
   bool flag=false;

   Node()
   {
        for(int i=0;i<2;i++)
            links[i]=nullptr;
    }

   bool containsKey(bool bit)
   {
        return (links[bit]!=NULL);
   }

   void put(bool bit,Node* node)
   {
        links[bit]=node;
   }

   Node* get(bool bit)
   {
       return links[bit];
   }

   void setEnd()
   {
       flag=true;
   }

   bool isEnd()
   {
       return flag;
   }

   bool isEmpty()
   {
       for(int i=0;i<2;i++)
           if(links[i]!=nullptr)
               return false;
       return true;
   }
};

int maxXOR(vector<int> &arr)
{
    Node* root=new Node();
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        Node* node = root;
        for(int j=31;j>=0;j--)
        {
                bool bit= (arr[i]>>j) & 1; 
                if(!node->containsKey(bit))
                {
                    node->put(bit, new Node());
                }
                //moves to reference trie
                node = node->get(bit);
        }
        node->setEnd();
    }
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        Node* node=root;
        int num=0;
        for(int j=31;j>=0;j--)
        {
            bool arrElementBit= (arr[i]>>j) & 1;
            bool targetBit= !arrElementBit;
            bool partnerBit=0;
            if(node->containsKey(targetBit))
            {
                node=node->get(targetBit);
                partnerBit=targetBit;
            }
            else
            {
                node=node->get(arrElementBit);
                partnerBit=arrElementBit;
            }
            
            if(partnerBit)
                num = num | (1<<j);
        }
        ans=max(ans,arr[i]^num);
    }
    return ans;
}

int main()
{

}