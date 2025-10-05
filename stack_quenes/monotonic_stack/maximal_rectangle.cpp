#include<bits/stdc++.h>
using namespace std;

/*Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.*/


int largestRectangleArea(vector<int> &graph)
{
    int n=graph.size();
    stack<int> st;
    int maxarea=0;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && graph[i]<graph[st.top()])
        {
            int element=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            int nse=i;
            maxarea=max(maxarea,(nse-pse-1)*graph[element]);
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int element=st.top();
        st.pop();
        int nse=n;
        int pse=st.empty()?-1:st.top();
        maxarea=max(maxarea,(nse-pse-1)*graph[element]);
    }
    return maxarea;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    //TC-O(m*n + n*2m)
    //SC-O(m+n)
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> graph(m,0);
    int maxarea=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]=='1')
                graph[j]++;
            else
                graph[j]=0;
        }
        int area=largestRectangleArea(graph);
        maxarea=max(maxarea,area);
    }
    return maxarea;
}

int main()
{

}