#include<bits/stdc++.h>
using namespace std;

/*
You have k baskets and you can only place one type of fruit in one basket
return max fruits you can pick
*/
int fruitsInBasket(vector<int> &fruits,int k)
{
    int n=fruits.size();
    //max length of subarray with at most k types of numbers
    
    //BRUTE
    //TC-O(N)+O(N)
    //SC-O(N)
    int l=0,r=0,maxlen=0;
    map<int,int> mpp;
    while(r<n)
    {
        mpp[fruits[r]]++;
        if(mpp.size()>k)
        {
            while(mpp.size()>k)
            {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0)
                    mpp.erase(fruits[l]);
                l++;
            }
        }
        if(mpp.size()<=k)
        {
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;


    //OPTIMAL
    //TC-O(N)
    //SC-O(N)
    l=r=maxlen=0;
    while(r<n)
    {
        mpp[fruits[r]]++;
        if(mpp.size()>k)
        {
            mpp[fruits[l]]--;
            if(mpp[fruits[l]]==0)
                mpp.erase(fruits[l]);
            l++;
        }
        if(mpp.size()<=k)
        {
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
    
}
int main()
{

}