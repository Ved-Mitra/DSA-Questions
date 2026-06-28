#include<bits/stdc++.h>
using namespace std;

//find celebrity
/*
in this problem you are given a n*n matrix with 0 or 1, 0 means the person row will not know person column whereas 1 means the person row will know person column

__|_0_|_1_|_2_|_3_|
0 | 0   1   1   0
1 | 0   0   0   0 
2 | 0   1   0   0
3 | 1   1   0   0

here matrix[0][2]=1 means person zero knows person 2

CELEBRITY---> everyone knows him, he knows no-one
*/

int celebrity(vector<vector<int>> person)
{
    int n=person.size();

    //BRUTE
    //TC-O(n^2)
    //SC-O(1)
    for(int i=0;i<n;i++)
    {
        int sum=accumulate(person[i].begin(),person[i].end(),0);
        if(sum==0)
        {
            for(int j=0;j<n;j++)
                sum+=person[j][i];
            if(sum==n-1)
                return i;
        }
    }
    return -1;


    //BRUTE
    vector<int> knowMe(n,0);
    vector<int> IKnow(n,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(person[i][j])
            {
                IKnow[i]++;
                knowMe[j]++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(knowMe[i]==n-1 && IKnow[i]==0)
            return i;
    }
    return -1;



    //OPTIMAL
    //min celebrity=0
    //max celebrity=1
    //TC-O(2n)
    //SC-O(1)
    int top=0,down=n-1;
    while(top<down)
    {
        if(person[top][down]==1)
            top++;
        else if(person[down][top]==1)
            down--;
        else
        {
            top++;
            down--;
        }
    }
    if(top>down)
        return -1;
    if(top==down)
    {
        for(int i=0;i<n;i++)
        {
            if(i==top)
                continue;
            if(person[top][i]==0 && person[i][top]==1){}
            else
                return -1;
        }
    }
    return top;
}


int main()
{

}
