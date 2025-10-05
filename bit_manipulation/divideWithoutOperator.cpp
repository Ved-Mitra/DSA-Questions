#include<bits/stdc++.h>
using namespace std;


int divide(int dividend,int divisor)
{
    //TC-O(log2 n)^2
    //SC-O(1)
    if(dividend==divisor)
        return 1;
    if(dividend==INT_MIN && divisor==-1)
        return INT_MAX;
    if(divisor==1)
        return dividend;
    bool sign =true; //+ve
    if(dividend>=0 && divisor <0)
        sign =false;
    if(dividend<0 && divisor>0)
        sign =false;
    
    long n=abs(dividend);
    long d=abs(divisor);
    long ans=0;
    while(n>=d) //O(log2 n)
    {
        int cnt=0;
        while(n>= (d<<(cnt+1))) //could also be written as   n >= (d<<(cnt+1))
        { //O(log2 n)
            cnt++;
        }
        ans+= (1<<cnt); //also 2^cnt
        n = n - (d*(1<<cnt)); 
    }
    if(ans==(1<<31) && sign==true)
        return INT_MAX;
    if(ans==(1<<31) && sign==false)
        return INT_MIN;
    return sign?ans:(-ans);
}


int main()
{

}