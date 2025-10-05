#include<bits/stdc++.h>
using namespace std;

void factor(int n)
{
    vector<int> factors;
    //O(sqrt(n)), n:number given
    for (int i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            factors.push_back(i);
            if(i!=(n/i))
                factors.push_back(n/i);
        }
    }
    sort(factors.begin(),factors.end());//O(N*log N) ,N: number of factors
    for(auto it:factors)//O(N)
    {
        cout << it <<", ";
    }
}
void gcd(int n1,int n2)
{
    int i=min(n1,n2);
    for(;i>=1;i--)//O(min(n1,n2))
    {
        if(n1%i==0 && n2%i==0)
        {
            cout << i << endl;
            break;
        }
    }
    //Eucludean algorithm (n1>n2)
    //gcd(n1,n2)=gcd(n1-n2,n2)
    while(n1>0 && n2>0)// O( log phi( min(n1,n2) ) ), phi: the number which is dividing
    {
        if(n1>n2)
            n1%=n2;
        else
            n2%=n1;
    }
    if(n1==0)
        cout << n1 << endl;
    else
        cout << n2 << endl;
}

int main()
{
    return 0;
}