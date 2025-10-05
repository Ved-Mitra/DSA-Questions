#include<bits/stdc++.h>
using namespace std;

/*Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.*/

bool comp(vector<int> &v1,vector<int> &v2)
{
    return v1[1]<v2[1];
}
int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    int n=intervals.size();
    sort(intervals.begin(),intervals.end(),comp);
    int lastEndTime=intervals[0][1];
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        if(intervals[i][0]>=lastEndTime)
        {
            cnt++;
            lastEndTime=intervals[i][1];
        }
    }
    return n-cnt;
}

int main()
{

}