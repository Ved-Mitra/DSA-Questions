#include<bits/stdc++.h>
using namespace std;


/*There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.*/

int maxScore(vector<int> &cardPoints,int k)
{
    int n=cardPoints.size();
    int total_pts=0,pts=0;
    for(int i=0;i<n;i++)
    {
        if(i<n-k)
            pts+=cardPoints[i];
        total_pts+=cardPoints[i];
    }
    int r=n-k,l=0,ans=total_pts-pts;
    cout << ans <<endl;
    while(r<n)
    {
        pts+=cardPoints[r];
        pts-=cardPoints[l];
        l++;
        r++;
        ans=max(ans,total_pts-pts);
    }
    return ans;
}

int main()
{

}