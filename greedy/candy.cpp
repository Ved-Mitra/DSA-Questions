#include<bits/stdc++.h>
using namespace std;

/*There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.*/

int minCandy(vector<int> &ratings)
{
    int n=ratings.size();
    //BRUTE
    //TC-O(3n)
    //SC-O(2n)
    vector<int> left(n),right(n);
    left[0]=1;
    right[n-1]=1;
    for(int i=0;i<n;i++)
    {
        if(ratings[i]>ratings[i-1])
            left[i]=left[i-1]+1;
        else
            left[i]=1;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(ratings[i]>ratings[i+1])
            right[i]=right[i+1]+1;
        else
            right[i]=1;
    }
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=max(left[i],right[i]);
    return sum;


    //BETTER
    vector<int> left2(n);
    left2[0]=1;
    for(int i=0;i<n;i++)
    {
        if(ratings[i]>ratings[i-1])
            left2[i]=left2[i-1]+1;
        else
            left2[i]=1;
    }
    int curr=0,r=0;
    sum=0;
    for(int i=n-2;i>=0;i--)
    {
        if(ratings[i]>ratings[i+1])
        {
            curr=r+1;
            r=curr;
        }
        else
            curr=1;
        sum+=max(left2[i],curr);
    }    
    sum+=max(left2[n-1],1);
    return sum;


    //OPTIMAL
    //TC-O(n)
    //SC-O(1)
    sum=1;
    int i=1;
    while(i<n)
    {
        if(ratings[i]==ratings[i-1])
        {
            sum++;
            i++;
            continue;
        }
        int peak=1;
        while(i<n && ratings[i]>ratings[i-1])
        {
            peak++;
            sum+=peak;
            i++;
        }
        int down=1;
        while(i<n && ratings[i]<ratings[i-1])
        {
            sum+=down;
            down++;
            i++;
        }
        if(peak<down)
        {
            sum+=(down-peak);
        }
    }
    return sum;
}


int main()
{
    
}