#include<bits/stdc++.h>
using namespace std;

/*Given array start and end containing start_i and end_i the endtime and startime of the meetings
maximise the meetings in the room*/

bool comparator(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2)
{
    if(p1.first.second<p2.first.second)//smallest end
        return true;
    else if(p1.first.first<p2.first.first)//smallest start
        return true;
    else if(p1.second<p2.second)//smallest index
        return true;
    return false;
}

int meeting(vector<int> &start,vector<int> &end)
{
    //TC-O(2n + nlog n)
    //SC-O(4n)
    //sort start and end
    int n=start.size();
    vector<pair<pair<int,int>,int>> meet;
    for(int i=0;i<n;i++)
    {
        meet.push_back({{start[i],end[i]},i});//storing index if we wanted to return the index of meeting be will be helding
    }
    //sort according to endtime , then start , then index
    sort(meet.begin(),meet.end(),comparator);
    int cnt=1;
    int freeTime=meet[0].first.second;
    for(int i=1;i<n;i++)
    {
        if(freeTime<meet[i].first.first)
        {
            freeTime=meet[i].first.second;
            cnt++;
        }
    }
    return cnt;
}

int main()
{

}