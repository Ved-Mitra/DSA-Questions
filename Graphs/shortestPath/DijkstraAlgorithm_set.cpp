#include <bits/stdc++.h>
using namespace std;

//set is fastest as it removes duplication

vector<int> DijktraAlgorithm_Set(vector<vector<pair<int,int>>> &adjList,int src)
{
    int n=adjList.size();
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    set<pair<int,int>> st;
    st.insert({0,src});
    while(!st.empty())
    {
        int dNode=st.begin()->first;
        int node=st.begin()->second;
        st.erase(st.begin());
        for(auto &[x,d]:adjList[node])
        {
            if(dist[x]>d+dNode)
            {
                if(dist[x]!=INT_MAX)
                    auto it=st.find({dist[x],x});
                dist[x]=d+dNode;
                st.insert({dist[x],x});
            }
        }
    }
    return dist;
}



int main()
{
    
}