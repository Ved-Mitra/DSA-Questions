#include<bits/stdc++.h>
using namespace std;


int XORRangeN(int n)
{
    //return xor till range of n
    //SEE PATTERN
    /*
    N=1         1
    N=2  1^2    3
    N=3  1^2^3  0
    N=4         4
    N=5         1 
    N=6         7  
    N=7         0
    N=8         8
    N=9         1
    N=10        11
    N=11        0
    
    the pattern is:
    N%4==1        1
    N%4==2        N+1
    N%4==3        0
    N%4==0        N   
    */

    if(n%4==1)
        return 1;
    else if(n%4==2)
        return n+1;
    else if(n%4==3)
        return 0;
    return n;
}
int XORLtoR(int l,int r)
{
    int XOR_l=XORRangeN(l-1);
    int XOR_r=XORRangeN(r);
    return XOR_l^XOR_r;
}

int main()
{

}