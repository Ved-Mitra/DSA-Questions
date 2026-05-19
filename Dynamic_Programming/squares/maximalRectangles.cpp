#include <bits/stdc++.h>
using namespace std;

vector<int> NSE(vector<int> &arr)
{
    int m=arr.size();
    stack<int> st;
    vector<int> nse(m);
    for(int i=m-1;i>=0;i--)
    {
        while(!st.empty() && arr[i]<=arr[st.top()])
            st.pop();
        if(st.empty())
            nse[i]=m;
        else
            nse[i]=st.top();
        st.push(i);
    }
    return nse;
}
vector<int> PSE(vector<int> &arr)
{
    int m=arr.size();
    stack<int> st;
    vector<int> pse(m);
    for(int i=0;i<m;i++)
    {
        while(!st.empty() && arr[i]<=arr[st.top()])
            st.pop();
        if(st.empty())
            pse[i]=-1;
        else
            pse[i]=st.top();
        st.push(i);
    }
    return pse;
}
int maxAreaRec(vector<int> &arr)
{
    int m=arr.size();
    vector<int>pse=PSE(arr);
    vector<int>nse=NSE(arr);
    int maxArea=0;
    for(int i=0;i<m;i++)
    {
        int area=(nse[i]-pse[i]-1)*arr[i];
        maxArea=max(maxArea,area);
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> arr(m,0);
    int maxArea=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]=='1')
                arr[j]++;
            else
                arr[j]=0;
        }
        maxArea=max(maxAreaRec(arr),maxArea);
    }
    return maxArea;
}


int main()
{

}