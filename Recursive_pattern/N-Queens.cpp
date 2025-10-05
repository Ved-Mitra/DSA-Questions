#include<bits/stdc++.h>
using namespace std;

//BETTER
bool isSafe(int row, int col,vector<string> &board,int n)
{
    int duprow=row;
    int dupcol=col;

    //check upper diagonal
    while(row>=0 && col>=0)
    {
        if(board[row][col]=='Q')
            return false;
        row--;
        col--;
    }

    //check row
    col=dupcol;
    row=duprow;
    while(col>=0)
    {
        if(board[row][col]=='Q')
            return false;
        col--;
    }

    //check lower diagonal
    row=duprow;
    col=dupcol;
    while(row<n && col>=0)
    {
        if(board[row][col]=='Q')
            return false;
        row++;
        col--;
    }

    return true;
}
void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}


//OPTIMIZED
void solve1(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal, int n)
{
    /*
    board is like this: (Lower Diagonal)

    __|_0_|_1_|_2_|_3_|
     0| 0 | 1 | 2 | 3 |
     -------------------
     1| 1 | 2 | 3 | 4 |
     -------------------
     2| 2 | 3 | 4 | 5 |
     -------------------
     3| 3 | 4 | 5 | 6 |

    Notice that the value along diagonal is same:
    i.e. value of (col + row) remains same throughout the lower diagonal.

     here n=3

     lowerDiagonal[row + col]=1
     here row + col give the diagonal (example: row+col=2+1=3)




    board be like: (Upper Diagonal)
    __|_0_|_1_|_2_|_3_|
     0| 3 | 4 | 5 | 6 |
     -------------------
     1| 2 | 3 | 4 | 5 |
     -------------------
     2| 1 | 2 | 3 | 4 |
     -------------------
     3| 0 | 1 | 2 | 3 |

    Notice that the value along diagonal is same: 
    i.e. value of (n-1 + col - row) remains same throughout the upper diagonal

    here n=3

    upperDiagonal[n-1 +col -row]=1



     */


    //TC-O(n!)
    //SC-O(N^2)


    if(col==n)
    {
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++)
    {
        if(leftRow[row]==0 && lowerDiagonal[row + col]==0 && upperDiagonal[n-1 + col - row]==0)
        {
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiagonal[row + col]=1;
            upperDiagonal[n-1 + col - row]=1;
            solve1(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
            board[row][col]='.';
            leftRow[row]=0;
            lowerDiagonal[row + col]=0;
            upperDiagonal[n-1 + col - row]=0;
        }
    }
}



int main()
{
    int n;
    cout << "Enter the number of Queens";
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
    {
        board[i]=s;
    }
    solve(0,board,ans,n);


    //optimized
    vector<vector<string>> ans1;
    vector<string> board1(n);
    string s1(n,'.');
    for(int i=0;i<n;i++)
    {
        board1[i]=s1;
    }
    vector<int> leftRow(n,0), upperDiagonal(2*n - 1,0), lowerDiagonal(2*n - 1,0);
    solve1(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);



    return 0;
}