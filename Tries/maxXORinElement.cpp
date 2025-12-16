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

vector<int> maxXOR(vector<int> &arr,vector<vector<int>> &queries)
{
    int n=arr.size();
    int m=queries.size();
    sort(arr.begin(),arr.end());
    vector<int> ans(m);
    vector<pair<pair<int,int>,int>> query(m);
    for(int i=0;i<m;i++)
        query[i]={{queries[i][1],queries[i][0]},i};
    sort(query.begin(),query.end());

    Node* root=new Node();
    int j=0;//for arr;
    for(int i=0;i<m;i++)
    {
        while(j<n && arr[j]<=query[i].first.first)
        {
            Node* node=root;
            for(int k=31;k>=0;k--)
            {
                bool bit= (arr[j]>>k) &1;
                if(!node->containsKey(bit))
                    node->put(bit,new Node());
                node=node->get(bit);
            }
            j++;
        }
        if(root->isEmpty())
        {
            ans[query[i].second]=-1;
            continue;
        }
        int num=0;
        Node* node=root;
        for(int k=31;k>=0;k--)
        {
            bool numberBit=(query[i].first.second>>k)&1;
            bool targetBit= !numberBit;
            bool partnerBit;

            if(node->containsKey(targetBit))
            {
                partnerBit=targetBit;
                node=node->get(targetBit);
            }
            else
            {
                partnerBit=numberBit;
                node=node->get(partnerBit);
            }

            if(partnerBit)
            {
                num = num | (1<<k);
            }
        }
        ans[query[i].second]=query[i].first.second ^ num;
    }
    return ans;
}

int main()
{

}