#include <bits/stdc++.h>
using namespace std;

/*Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. {Running, Fighting Practice or Learning New Moves}. Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.*/

int meritPoints_Memoization(vector<vector<int>> &points,int day,vector<vector<int>> &dp,int last)
{
    //task can be 0,1,2,3
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++)
        {
            if(task!=last)
                maxi=max(maxi,points[0][task]);
        }
        dp[0][last] = maxi; // store base case
        return dp[0][last];
    }

    if(dp[day][last]!=-1)
        return dp[day][last];

    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point=points[day][task]+meritPoints_Memoization(points,day-1,dp,task);
            maxi=max(maxi,point);
        }
    }
    dp[day][last] = maxi; // store computed value
    return dp[day][last];
}

int meritPointsTabulation(vector<vector<int>> &points)
{
    int n=points.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            dp[day][last]=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}

int meritPoints_SC(vector<vector<int>> &points)
{
    int n=points.size();
    vector<int> pt(4,-1);
    pt[0]=max(points[0][1],points[0][2]);
    pt[1]=max(points[0][0],points[0][2]);
    pt[2]=max(points[0][0],points[0][1]);
    pt[3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++)
    {
        vector<int> temp(4,0);
        for(int last=0;last<4;last++)
        {
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int point=points[day][task]+pt[task];
                    // update temp for this 'last'
                    temp[last]=max(temp[last],point);
                }
            }
        }
        pt=temp;
    }
    return pt[3];
}






int main()
{

}