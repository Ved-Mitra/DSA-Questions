#include <bits/stdc++.h>
using namespace std;

//can be used in negative cycle and negative weight
//only applicable in DG
//just comvert UG into DG
vector<int> BellmanFord(vector<vector<int>> &edges,int n,int src)
{
    //TC - O(V*E)
    //SC - O(V)
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    //relax all the edges n-1 times sequentially
    /*meaning of relax
    if dist[u]+edgeweight<dist[v]
        dict[v]=dist[u]+edgeweight
    */
   //if UG just add v-->u path along with u-->v path with same weight
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<edges.size();j++)
        {
            if(dist[edges[j][0]]!=INT_MAX)
                if(dist[edges[j][0]]+edges[j][2]<dist[edges[j][1]])
                    dist[edges[j][1]]=edges[j][2]+dist[edges[j][0]];
        }
    }
    //Nth relaxation to check cycles
    //as if in this dist changes means that negative cycle is present
    for(int j=0;j<edges.size();j++)
    {
        if(dist[edges[j][0]]!=INT_MAX)
            if(dist[edges[j][0]]+edges[j][2]<dist[edges[j][1]])
                return {-1};
    }
    return dist;
}

int main()
{

}