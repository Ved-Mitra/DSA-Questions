#include <bits/stdc++.h>
using namespace std;

//MST's weight= sum of all weight in the MST
//intuition--Greedy

vector<vector<int>> PrimAlgorithm(vector<vector<pair<int,int>>> &adjList)
{
    //TC - O(E * log E)
    //SC - O(E)
    int n=adjList.size();
    //min-heap (weight-node-parent)
    vector<vector<int>> mst;
    int sum=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<int> visited(n,false);
    pq.push({0,{0,-1}});
    while(!pq.empty())// O(E)
    {
        int node=pq.top().second.first; // O(log E)
        int wt=pq.top().first;
        int parent=pq.top().second.second;
        pq.pop();
        if(visited[node])
            continue;
        sum+=wt;
        visited[node]=true;
        if(parent!=-1)
            mst.push_back({node,parent});
        for(auto &[x,d]:adjList[node])//O(E)
        {
            if(!visited[x])
                pq.push({d,{x,node}});//O(log E)
        }
    }
    return mst;
}



int main()
{

}