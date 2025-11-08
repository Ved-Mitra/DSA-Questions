#include <bits/stdc++.h>
using namespace std;

//disktra not valid for negative weight and negative cycle
//as in negative weight it falls in infinite loop
//TC - O(E * log V)

vector<int> dijsktraPQ(vector<vector<pair<int,int>>> &adjList,int src)
{
    int n=adjList.size();
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()) // TC - o(V)
    {
        int dNode=pq.top().first;//TC - O(log( heap size))
        int node=pq.top().second;
        pq.pop();
        for(auto &[x,d]:adjList[node])//TC - O(number of edges (ne = V-1))
        {
            if(dist[x]>d+dNode)
            {
                dist[x]=d+dNode;
                pq.push({dist[x],x});// TC - O(log (heap size))
            }
        }
    }
    return dist;
}

//TC derivation
/*
O ( V * ((pop in min heap)) + (number of egdes)*(push in PQ)))
O ( V * (log(heap size) + ne*log(heap size)))
O ( V * (log(heap size) + (V-1)*log(heap size)))

heap size ~~ V^2

O ( V * V * log(V^2))
O (2 * V^2 * log(V))

ne = E = V^2

O(E * log (V))

*/


int main()
{
    
}