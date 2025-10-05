#include<bits/stdc++.h>
using namespace std;

/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.*/

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> ans;
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<n;i++)
    {
        if(ans.empty() || intervals[i][0]>ans.back()[1])
        {
            ans.push_back({intervals[i][0],intervals[i][1]});
        }
        else
        {
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
    }
    return ans;
}

int main()
{

}