#include<bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n)
{
    //given a number n , print all prime number till n
    vector<int> prime(n+1);
    //TC-O(n) + O(n*log(log n)) + O(N)
             //prime harmonic series
    for(int i=2;i<=n;i++)
        prime[i]=1;
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i]==1)
        {
            for(int j=i*i;j<=n;j+=i)//as previus i could have made prime[i]=0
            {
                prime[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==1)
            cout << i;
    }
}

int main()
{

}