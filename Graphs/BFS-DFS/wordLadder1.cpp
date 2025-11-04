#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord,vector<string> &wordList)
{
    queue<pair<string,int>> q;
    unordered_map<string,int> visitedMap;
    for(int i=0;i<wordList.size();i++)
        visitedMap[wordList[i]]=-1;
    q.push({beginWord,1});
    if(visitedMap[endWord]!=-1)
        return 0;
    while(!q.empty())
    {
        string str=q.front().first;
        int d=q.front().second;
        q.pop();
        for(int i=0;i<str.size();i++)
        {
            char original=str[i];
            for(char ch='a';ch<='z';ch++)
            {
                str[i]=ch;
                if(visitedMap[str]==-1)
                {
                    q.push({str,d+1});
                    visitedMap[str]=1;
                }
                if(str==endWord)
                    return d+1;
            }
            str[i]= original;
        }
    }
    return 0;
}

int main()
{

}