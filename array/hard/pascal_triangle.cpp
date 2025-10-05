#include<bits/stdc++.h>
using namespace std;

/*
Q. Prints pascal's triangle

    1
   1 1
  1 2 1
 1 3 3 1

TYPE-1: given row,column so give the element at that location
TYPE-2: given row, give the entire row
TYPE-3: given row, give entire triangle till that row
*/
long long ncr(int n,int r)
{
    long long res=1;
    for(int i=0;i<r;i++)
    {
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
void type1(int r,int c)
{
    //element is  rCc like nCr
    cout << ncr(r-1,c-1) << endl;
}
void type2(int n)
{
    for(int i=1;i<=n;i++)
    {
        cout << ncr(n-1,i-1) << ", ";
    }
    cout << endl;
}
void type3(int n)
{
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++)
    {
        ans[i].push_back(1);
        int n=0;
        if(i!=0)
            n=ans[i-1].size();
        for(int j=0;j<n-1;j++)
        {
            ans[i].push_back(ans[i-1][j]+ans[i-1][j+1]);
        }
        if(i!=0)
            ans[i].push_back(1);
    }
    for(auto it:ans)
        for(auto it1:it)
            cout <<it1;
}
int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    
    return 0;
}