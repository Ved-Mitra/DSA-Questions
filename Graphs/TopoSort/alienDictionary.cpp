#include <bits/stdc++.h>
using namespace std;

/*Given a sorted dictionary of an alien language having N words and K starting alphabets of a standard dictionary. Find the order of characters in the alien language.

There may be multiple valid orders for a particular test case, thus you may return any valid order as a string. The output will be True if the order returned by the function is correct, else False denoting an incorrect order. If the given arrangement of words is inconsistent with any possible letter ordering, return an empty string "".*/

string findOrder(string dict[], int N, int K)
{
	vector<pair<char,char>> edges;
    for(int i=0;i<N-1;i++)
    {
        int n=dict[i].size();
        int m=dict[i+1].size();
        int found=0;
        for(int j=0;j<min(m,n);j++)
        {
            if(dict[i][j]!=dict[i+1][j])
            {
                edges.push_back({dict[i][j],dict[i+1][j]});
                found=1;
                break;
            }
        }
        if(!found && n>m)
            return ""; // not valid Prefix case
    }
    unordered_map<char,vector<char>> adjList;
    unordered_map<char,int> inDegree;
    for(int i=0;i<K;i++)
        inDegree[i+'a']=0;
    for(int i=0;i<edges.size();i++)
    {
        inDegree[edges[i].second]++;
        adjList[edges[i].first].push_back(edges[i].second);
    }
    queue<char> q;
    string ans="";
    for(int i=0;i<K;i++)
        if(inDegree['a'+i]==0)
            q.push('a'+i);
    while(!q.empty())
    {
        char ch=q.front();
        q.pop();
        ans+=ch;
        for(auto &x:adjList[ch])
        {
            inDegree[x]--;
            if(inDegree[x]==0)
                q.push(x);
        }
    }
    if(ans.size()==K)
        return ans;
    return "";
}



int main()
{

}