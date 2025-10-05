#include<bits/stdc++.h>
using namespace std;



int minBitFlipsConvertAToB(int start,int goal)
{
    int ans=start^goal; //ans contains the exct number of bits that need to be fipped
    int cnt=0;
    for(int i=0;i<31;i++)
    {
        //checking for ith bit is set or not
        if(ans & (1<<i))
            cnt++;
    }
    return cnt;
}


int main()
{

}