#include<bits/stdc++.h>
using namespace std;

int main() {

    // Write your program logic here. This line is a comment, you can leave it in code if you wish.
    int rows,columns;
    cin >> rows >> columns;
    int arr[rows][columns];
    
    int i=0,j=0,num=1;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<columns;j++)
        {
            arr[i][j]=num++;
        }
    }

    //TC-O(N^2)
    //SC-O(N)
    int top=0,bottom=rows-1,left=0,right=columns-1;
    vector<int>ans;
    while(top<=bottom && left<=right)
    {
        //right
        for(int i=left;i<=right;i++)
            ans.push_back(arr[top][i]);
        top++;
        //bottom
        for(int i=top;i<=bottom;i++)
            ans.push_back(arr[i][right]);
        right--;
        if(top<=bottom)
        {
            //left
            for(int i=right;i>=left;i--)
                ans.push_back(arr[bottom][i]);
            bottom--;
        }
        if(left<=right)
        {
            //top
            for(int i=bottom;i>=top;i--)
                ans.push_back(arr[i][left]);
            left++;
        }
    }

    //MY-METHOD
    /*
    int times;
    if(rows%2==0) //To check for odd number of rows or columns
        times=rows/2;
    else
        times=(rows/2)+1;
    
    i=j=0;
    if (rows==1)
    {
        for(i=0;j<columns;j++)
            cout << arr[i][j];
    }
    else if(columns==1)
    {
        for(j=0;i<rows;i++)
            cout << arr[i][j];
    }
    else
    {
        for(num=0;num<times;num++) //To keep track that all numbers are printed
        {
            int count1=0,count2=0,count3=0;
            for(i=num,j=num;j<=(columns-1-num);j++) // going right
            {
                cout << arr[i][j] << "right" << endl;
                count1=0;
            }
            for(j=(columns-1-num),i=num+1;i<=(rows-1-num) && count1;i++) // going down
            {
                cout << arr[i][j] << "down" << endl;
                count2=0;
            }
            for(i=(rows-1-num),j=(columns-num-2);j>=num && count2;j--) // going left
            {
                cout << arr[i][j] << "left" << endl;
                count3=0;
            }
            for(j=num,i=(rows-num-2);i>num && count3;i--) // going up
            {
                cout << arr[i][j] << "up" << endl;
            }
        }
    }*/
    
    return 0;
}
