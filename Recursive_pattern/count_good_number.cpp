#include<bits/stdc++.h>
using namespace std;

//A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
// return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
//A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

long long myPow(int x ,long long n)
{
    int mod=1e9 + 7;
    long long res=1;
    while(n>0)
    {
        if(n%2==0)
        {
            x=(long long)x*x%mod;
            n/=2;
        }
        else
        {
            res=(res*x)%mod;
            n--;
        }
    }
    return res;
}
int countGoodNumbers(long long n)
{
    int mod=1e+9 + 7;
    long long even=(n+1)/2;
    long long odd =n-even;
    return (myPow(5,even)*myPow(4,odd))%mod;
}
int main()
{
    long long n;
    cout << "Enter the length of good digits string : ";
    cin >> n;

}
