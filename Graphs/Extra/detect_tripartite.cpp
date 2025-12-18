#include <bits/stdc++.h>
using namespace std;

bool helper(vector<vector<int>> &adjList,int i,vector<pair<bool,int>> &visited,int group)
{
    //U -- group=0
    //T -- group=1
    //S -- group=2
    
    for(int &x:adjList[i])
    {
        //colouring the node either by 1 or 2
        //checking by backtracking
        
    }

}
bool detectTripartite(vector<vector<int>> &adjList,int n)
{
    int n=adjList.size();
    vector<pair<bool,int>> visited(n,pair<bool,int>(false,-1));
    
    for(int i=0;i<n;i++)
        if(!visited[i].first)
            if(!helper(adjList,i,visited,0))
                return false;
    return true;
}



int main()
{

}