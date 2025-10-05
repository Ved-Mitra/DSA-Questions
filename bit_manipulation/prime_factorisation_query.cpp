#include<bits/stdc++.h>
using namespace std;


vector<int> primeFactors(int n)
{
    vector<int> ans;
    //OPTIMAL
    //TC-O(sqrt(n)* log n)
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                ans.push_back(i);
                n/=i;
            }
        }
    }
    if(n!=1)
        ans.push_back(n);
    return ans;
}
void function(vector<int> queries,vector<vector<int>> &ans)
{
    //BETTER
    //TC-O(Q)*O(sqrt(n))
    for(int i=0;i<queries.size();i++)
    {
        vector<int> ans_i=primeFactors(queries[i]);
        ans.push_back(ans_i);
    }

    //OPTIMAL
    //TC-O(n* log(log n)) + O(q* log2 n)
    //SC-O(n)
    //considering max number is 10^5
    vector<int> spf(1e5 + 1); // spf --> smallest prime factor
    for(int i=1;i<1e5;i++)
        spf[i]=i;
    for(int i=2;i*i<=1e5;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<=1e5;j++)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }
    for(int i=0;i<queries.size();i++)
    {
        int n=queries[i];
        vector<int> ans_i;
        while(n!=1)
        {
            ans_i.push_back(spf[n]);
            n/=spf[n];
        }
        ans.push_back(ans_i);
    }
}

int main()
{

}