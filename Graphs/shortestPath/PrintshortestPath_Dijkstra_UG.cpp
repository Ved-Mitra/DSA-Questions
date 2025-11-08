#include <bits/stdc++.h>
using namespace std;

vector<int> PrintShortestPath(vector<vector<pair<int,int>>> &adjList,int u,int v)
{
    //remember where i am coming from
    int n=adjList.size();
    set<pair<int,int>> st; // {dist,node}
    vector<int> parentTrack(n);
    for(int i=0;i<n;i++)
        parentTrack[i]=-1;
    vector<int> dist(n,INT_MAX);
    dist[u]=0;
    st.insert({0,u});
    while(!st.empty())
    {
        int node=st.begin()->second;
        int dNode=st.begin()->first;
        st.erase(st.begin());
        for(auto &[x,d]:adjList[node])
        {
            if(dist[x]>dNode+d)
            {
                if(dist[x]!=INT_MAX)
                {
                    auto it=st.find({dist[x],x});
                    st.erase(it);
                }
                dist[x]=d+dNode;
                st.insert({dist[x],x});
                parentTrack[x]=node;
            }
        }
    }
    int i=v;
    vector<int> path;
    if(dist[v]==INT_MAX)
        return path;
    while(i!=-1)
    {
        path.push_back(i);
        i=parentTrack[i];
    }
    reverse(path.begin(),path.end());
    return path;
}

int main()
{
    
}