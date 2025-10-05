#include<bits/stdc++.h>
using namespace std;


//return the path taken by the rat in lexographical order (D L R V)
//return all paths

void ratInMaze(vector<string> &ans,vector<vector<int>> &path,string s,int row, int col,vector<vector<bool>> &visited)
{
    //TC-O(4^(m*n))
    //SC-O(m*n)
    int n=path.size();
    int m=path[0].size();
    if(row<0 || col<0 || row>=n || col>=m)
        return;
    if(path[row][col]==0 || visited[row][col])
        return;

    if(row==n-1 && col==m-1)
    {
        ans.push_back(s);
        return;
    }

    visited[row][col]=true;
    s+='D';
    ratInMaze(ans,path,s,row+1,col,visited);//go down
    s.pop_back();

    s+='L';
    ratInMaze(ans,path,s,row,col-1,visited);//go left
    s.pop_back();

    s+='R';
    ratInMaze(ans,path,s,row,col+1,visited);//go right
    s.pop_back();

    s+='V';
    ratInMaze(ans,path,s,row-1,col,visited);//go up
    s.pop_back();

    visited[row][col]=false;

    return;
}


int main()
{
    vector<string> ans;
    int row,col;
    cout << "Enter the row and column: ";
    cin >> row >> col;
    vector<vector<int>> path(row,vector<int>(col));

    cout << "Enter the path: "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin >> path[i][j];
        }
    }

    vector<vector<bool>> visited(row,vector<bool>(col,false));
    ratInMaze(ans,path,"",0,0,visited);

    cout << ans.size();
    for(auto it:ans)
        cout << it << endl;
    
    return 0;
}