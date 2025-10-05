#include<bits/stdc++.h>
using namespace std;

/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining*/

int trap(vector<int> &height)
{
    //APPROACH-1
    //TC-O(3n)
    //SC-O(2n)
    int n=height.size();
    vector<int> prefixMax(n);
    vector<int> suffixMax(n);
    prefixMax[0]=height[0];
    for(int i=1;i<n;i++)
        prefixMax[i]=max(prefixMax[i-1],height[i]);
    suffixMax[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--)
        suffixMax[i]=max(suffixMax[i+1],height[i]);
    int total=0;
    for(int i=0;i<n;i++)
    {
        int leftMost=prefixMax[i];
        int rightMost=suffixMax[i];
        if(height[i]<leftMost && height[i]<rightMost)
            total+=min(leftMost,rightMost)-height[i];
    }
    return total;



    //APPROACH-2
    //TC-O(n)
    //SC-O(1)
    int lmax=0,rmax=0,total=0,l=0,r=n-1;
    while(l<r)
    {
        if(height[l]<=height[r])
        {
            if(lmax>height[l])
                total+=lmax-height[l];
            else
                lmax=height[l];
            l++;
        }
        else
        {
            if(rmax>height[r])
                total+=rmax-height[r];
            else
                rmax=height[r];
            r--;
        }
    }
    return total;
}

int main()
{

}