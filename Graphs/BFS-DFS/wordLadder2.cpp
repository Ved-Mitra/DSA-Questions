#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    //STRIVER
    vector<vector<string>> ans;
    unordered_map<string,bool> visitedMap;
    for(int i=0;i<wordList.size();i++)
        visitedMap[wordList[i]]=false;
    queue<vector<string>> q;
    q.push({beginWord});
    if(visitedMap.find(beginWord)!=visitedMap.end())
        visitedMap[beginWord]=true;
    if(visitedMap.find(endWord)==visitedMap.end())
        return ans;
    vector<string> UsedOnLevel;
    while(!q.empty())
    {
        int n=q.size();
        int flag=0;
        
        for(int j=0;j<n;j++)
        {
            auto strVec=q.front();
            q.pop();
            string s=strVec[strVec.size()-1];
            for(int i=0;i<s.size();i++)
            {
                char original=s[i];
                for(char ch='a';ch<='z';ch++)
                {
                    s[i]=ch;
                    if(visitedMap.find(s)!=visitedMap.end() && !visitedMap[s])
                    {
                        auto newStrVec=strVec;
                        newStrVec.push_back(s);
                        q.push(newStrVec);
                        UsedOnLevel.push_back(s);
                        if(s==endWord)
                            flag=1;
                    }
                }
                s[i]=original;
            }
        }
        for(int i=0;i<UsedOnLevel.size();i++)
        {
            visitedMap[UsedOnLevel[i]]=true;
            UsedOnLevel.clear();
        }
        if(flag)
            break;
    }
    while(!q.empty())
    {
        if(q.front().back()==endWord)
            ans.push_back(q.front());
        q.pop();
    }
    return ans;
}



//Leetcode acceptable solution
void BFSHelper(unordered_map<string,int> &distMap,string &beginWord,string &endWord)
{
    queue<pair<string,int>> q;
    q.push({beginWord,0});
    distMap[beginWord]=0;
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
                if(distMap.find(str)!=distMap.end() && distMap[str]==-1)
                {
                    distMap[str]=d+1;
                    q.push({str,d+1});
                }
            }
            str[i]=original;
        }
    }
}
void DFSHelper(unordered_map<string,int> &distMap,string str,vector<vector<string>> &ans,vector<string> &strVec,string &endWord)
{
    if(str==endWord)
    {
        ans.push_back(strVec);
        return;
    }
    int d=distMap[str];
    for(int i=0;i<str.size();i++)
    {
        char original=str[i];
        for(char ch='a';ch<='z';ch++)
        {
            str[i]=ch;
            if(distMap.find(str)!=distMap.end() && distMap[str]==d+1)
            {
                strVec.push_back(str);
                DFSHelper(distMap,str,ans,strVec,endWord);
                strVec.pop_back();
            }
        }
        str[i]=original;
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    vector<vector<string>> ans;
    unordered_map<string,int> distMap;
    for(int i=0;i<wordList.size();i++)
        distMap[wordList[i]]=-1;
    if(distMap.find(endWord)==distMap.end())
        return ans;
    BFSHelper(distMap,beginWord,endWord);
    vector<string>strVec;
    strVec.push_back(beginWord);
    DFSHelper(distMap,beginWord,ans,strVec,endWord);
    return ans;
}



int main()
{

}