#include <bits/stdc++.h>
using namespace std;

vector<int> smallestRangeIn_K_List(vector<vector<int>> &nums)
{
    //give me smallest range in which the range must contain atleast one element from each list
    //list are soretd
    /*
    EXAMPLE:
    [[1,10,11],
     [3,3,20],
     [5,6,12]]

    answer: [1,5] range [x,y]
    */

    int k=nums.size();
        
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> small;
    int maxx=nums[0][0];
    for(int i=0;i<k;i++)
    {
        small.push({nums[i][0],{i,0}});
        maxx=max(maxx,nums[i][0]);
    }
    vector<int> ans={small.top().first,maxx};
    while(small.top().second.second<nums[small.top().second.first].size()-1)
    {
        pair<int,pair<int,int>> n=small.top();
        int y=n.second.second;
        int x=n.second.first;
        small.pop();
        small.push({nums[x][y+1],{x,y+1}});
        maxx=max(maxx,nums[x][y+1]);
        if(maxx-small.top().first<ans[1]-ans[0])
        {
            ans[0]=small.top().first;
            ans[1]=maxx;
        }
    }
    
    return ans;

}



int main()
{

}