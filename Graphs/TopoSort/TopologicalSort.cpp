#include <bits/stdc++.h>
using namespace std;
//only exists on DAG directed acyclic graph
//linear ordering of vertices such that if ther is an edge between u & V appears before V in that ordereing


void DFS(vector<vector<int>> &adjList,stack<int> &st,int node,vector<bool> &visited)
{
    visited[node]=true;
    for(int &x:adjList[node])
        if(!visited[x])
            DFS(adjList,st,x,visited);
    st.push(node);
}
vector<int> TopoSort(vector<vector<int>> &adjList)
{
    //by this we obtain one of the linear ordering
    int n=adjList.size();
    vector<bool>visited(n,false);
    stack<int>st;
    for(int i=0;i<n;i++)
        if(!visited[i])
            DFS(adjList,st,i,visited);
    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


int main()
{

}