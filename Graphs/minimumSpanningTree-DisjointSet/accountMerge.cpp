#include <bits/stdc++.h>
using namespace std;

class DisjointSet//union by size
{
    private:
    vector<int> size,parent;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }

    int findParent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ultimateParent_u=findParent(u);
        int ultimateParent_v=findParent(v);
        if(ultimateParent_u=ultimateParent_v)
            return;
        if(ultimateParent_u==ultimateParent_v)
            return;
        if(size[ultimateParent_u]<size[ultimateParent_v])
        {
            parent[ultimateParent_u]=ultimateParent_v;
            size[ultimateParent_v]+=size[ultimateParent_u];
        }
        else
        {
            //if same then attach v-->u
            parent[ultimateParent_v]=ultimateParent_u;
            size[ultimateParent_u]+=size[ultimateParent_v];
        }
    }
};


vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
    int n=0; // number of nodes==number of unique emails
    unordered_map<string,int> mpp; //email-->node idx
    unordered_map<int,string> name; //node idx --> name
    int node=0;
    vector<string> email; // node idx --> email
    for(int i=0;i<accounts.size();i++)
    {
        for(int j=1;j<accounts[i].size();j++)
        {
            if(mpp.find(accounts[i][j])==mpp.end())
            {
                mpp[accounts[i][j]]=node;
                name[node]=accounts[i][0];
                email.push_back(accounts[i][j]);
                node++;
            }
        }
    }
    n=mpp.size();
    DisjointSet st(n);
    for(int i=0;i<accounts.size();i++)
    {
        for(int j=2;j<accounts[i].size();j++)
        {
            st.unionBySize(mpp[accounts[i][j-1]],mpp[accounts[i][j]]);
        }
    }
    
    vector<vector<string>> ans;
    unordered_map<int,int> hash; // parent node idx --> ans idx
    int idx=0;
    for(int i=0;i<n;i++)
    {
        int parent=st.findParent(i);
        if(hash.find(parent)==hash.end())
        {
            ans.push_back({email[i]});
            hash[parent]=idx++;
        }
        else
        {
            ans[hash[parent]].push_back(email[i]);
        }
    }

    //sorting emails
    for(int i=0;i<ans.size();i++)
    {
        sort(ans[i].begin(),ans[i].end());
        ans[i].insert(ans[i].begin(),name[mpp[ans[i][0]]]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}



int main()
{

}