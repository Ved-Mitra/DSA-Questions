#include <bits/stdc++.h>
using namespace std;


//M-1
int nBST(int n, int *results)
{ // results inited to -1s
    //using DP
    if (n == 0 || n == 1)
        return 1;
    int count = 0;
    for(int i = 1;i <= n;i++)
    { 
        if (results[i - 1] == -1) 
            results[i - 1] = nBST(i - 1,results);
        if (results[n - i] == -1)
            results[n - i] = nBST(n - i,results);
        count += results[i - 1] * results[n - i]; // product rule
    }
    return count;
}

//M-2
int nBST(int n,int* results) 
{
    results[0] = results[1] = 1;
    for (int i=2; i<=n; i++)
    {
        results[i] = 0;
        for (int j=0; j<i; j++)
            results[i] += results[j] * results[i-j-1];//prdct rule
    }
    return results[n];
}
//r[5] = r[0]*r[4] + r[1]*r[3] + r[2]*r[2] + r[3]*r[1] + r[4]*r[0] = 42



//M-3
int nBST(int n) 
{
    if (n == 0 || n == 1) return 1;
    int count = 0;
    for (int i=1; i<=n; i++)
        count += nBST(i-1) * nBST(n-i); //product rule
    return count; 
}


int main()
{

}