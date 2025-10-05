#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return false;
    return true;
}
void primeFactors(int n)
{
    //BRUTE
    vector<int> ans;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(isPrime(i))
                ans.push_back(i);
            if((n/i)!=i)
                if(isPrime(n/i))
                    ans.push_back(n/i);
        }
    }



    //BETTER
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            ans.push_back(i);
            while(n%i==0)
                n/=i;
        }
    }

    //OPTIMAL
    //TC-O(sqrt(n)* log n)
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            ans.push_back(i);
            while(n%i==0)
                n/=i;
        }
    }
    if(n!=1)
        ans.push_back(n);
}

int main()
{

}