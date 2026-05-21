#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    private:
        vector<int> parent;
        vector<int> size;
    public:
        DisjointSet(int n){
            size.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
                parent[i]=i;
        }
        int parentOf(int node){
            if(parent[node]==node)
                return node;
            return parent[node]=parentOf(parent[node]);
        }
        void add(int u,int v){
            int ult_parent_u=parentOf(u);
            int ult_parent_v=parentOf(v);
            if(size[ult_parent_u]>=size[ult_parent_v]){
                parent[ult_parent_v]=ult_parent_u;
                size[ult_parent_u]+=size[ult_parent_v];
            }
            else{
                parent[ult_parent_u]=ult_parent_v;
                size[ult_parent_v]+=size[ult_parent_u];
            }
        }
};

int removeStones(vector<vector<int>> &stones){
    int n=stones.size();
    DisjointSet st(n);
    unordered_map<int,vector<int>> hashx,hashy;
    for(int i=0;i<n;i++)
    {
        int x=stones[i][0];
        int y=stones[i][1];
        for(auto j:hashx[x])
            st.add(i,j);
        for(auto j:hashy[y])
            st.add(i,j);
        hashx[x].push_back(i);
        hashy[y].push_back(i);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        if(st.parentOf(i)!=i)
            cnt++;
    return cnt;
}




int main()
{
    
}