#include <bits/stdc++.h>
using namespace std;

//this function part is based on the leetcode format of expr
char parse_and(vector<char> &expr)
{
    int n=expr.size();
    if(n==0)
        return 'f';
    bool res=expr.back()=='t'?true:false;
    while(!expr.empty() && expr.back()!='(')
    {
        if(expr.back()=='f')    res=false;
        expr.pop_back();
    }
    expr.pop_back(); // removing '('
    return res?'t':'f';
}
char parse_or(vector<char> &expr)
{
    int n=expr.size();
    if(n==0)
        return 'f';
    bool res=expr.back()=='t'?true:false;
    while(!expr.empty() && expr.back()!='(')
    {
        if(expr.back()=='t')    res=true;
        expr.pop_back();
    }
    expr.pop_back(); // removing '('
    return res?'t':'f';
}
char parse_not(vector<char> &expr)
{
    int n=expr.size();
    char res= expr.back()=='t'?'f':'t';
    expr.pop_back();
    expr.pop_back();
    return res;
}
bool parseBoolExpr(string expression)
{
    int n= expression.size();
    stack<char> op;
    vector<char> expr;
    for(int i=0;i<n;i++)
    {
        if(expression[i]=='!' || expression[i]=='&' || expression[i]=='|')   
            op.push(expression[i]);
        else if(expression[i]=='(')
        {
            expr.push_back('(');
        }
        else if(expression[i]==')')
        {
            char res;
            if(op.top()=='&')
                res=parse_and(expr);
            else if(op.top()=='!')
                res=parse_not(expr);
            else
                res=parse_or(expr);
            op.pop();
            expr.push_back(res);
        }
        else if(expression[i]==',') {}
        else
            expr.push_back(expression[i]);
    }
    return expr.back()=='t'?true:false;
}


//this function is based on the striver format of expr i.e. T|T&F
// tell the number of ways to make this expression true

//ways in
//AND (multiply the ways and plus the)
//example:
// T T : T
// T F : F
// F T : F
// F F : F
// so in AND we only multiply when left & right partition true cases -- > when we find number of true cases
// so in AND we only multiply when left & right partition false cases -- > when we find number of false cases

//similarly for OR and XOR
long long recursiveHelper(string &expression,int i,int j,vector<vector<vector<long long>>> &dp,int isTrue)
{
    if(i>j)
        return 0;
    if(i==j)
    {
        if(isTrue==1)   
            return expression[i]=='T';
        return expression[i]=='F';
    }

    if(dp[i][j][isTrue]!=-1)
        return dp[i][j][isTrue];

    long long ways=0;
    for(int index=i+1;index<=j-1;index+=2)
    {
        long long leftPartitionTrue=recursiveHelper(expression,i,index-1,dp,1);
        long long leftPartitionFalse=recursiveHelper(expression,i,index-1,dp,0);
        long long rightPartitionTrue=recursiveHelper(expression,index+1,j,dp,1);
        long long rightPartitionFalse=recursiveHelper(expression,index+1,j,dp,0);
        if(expression[index]=='&')
        {
            if(isTrue==1)
                ways+=leftPartitionTrue*rightPartitionTrue;
            else    
                ways+=leftPartitionFalse*rightPartitionFalse + leftPartitionFalse*rightPartitionTrue + leftPartitionTrue*rightPartitionFalse;
        }
        else if(expression[index]=='|')
        {
            if(isTrue==1)
                ways+=leftPartitionTrue*rightPartitionTrue + leftPartitionFalse*rightPartitionTrue + leftPartitionTrue*rightPartitionFalse;
            else
                ways+=leftPartitionFalse*rightPartitionFalse;
        }
        else
        {
            if(isTrue==1)
                ways+=leftPartitionFalse*rightPartitionTrue + leftPartitionTrue*rightPartitionFalse;
            else
                ways+=leftPartitionFalse*rightPartitionFalse + leftPartitionTrue*rightPartitionTrue;
        }   
    }
    return dp[i][j][isTrue]=ways;
}
bool parseBoolExpr_Memoization(string expression)
{
    int n=expression.size();
    vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
    return recursiveHelper(expression,0,n-1,dp,1);
}


bool parseBoolExpr_Tabulation(string expression)
{
    int n=expression.size();
    vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(2,0)));
    for(int i=0;i<n;i++)
    {
        dp[i][i][1]= expression[i]=='T';
        dp[i][i][0]= expression[i]=='F';
    }
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(i>j)
                continue;
            for(int isTrue=0;isTrue<=1;isTrue++)
            {
                long long ways=0;
                for(int index=i+1;index<=j-1;index+=2)
                {
                    long long leftPartitionTrue=dp[i][index-1][1];
                    long long leftPartitionFalse=dp[i][index-1][0];
                    long long rightPartitionTrue=dp[index+1][j][1];
                    long long rightPartitionFalse=dp[index+1][j][0];
                    if(expression[index]=='&')
                    {
                        if(isTrue==1)
                            ways+=leftPartitionTrue*rightPartitionTrue;
                        else    
                            ways+=leftPartitionFalse*rightPartitionFalse + leftPartitionFalse*rightPartitionTrue + leftPartitionTrue*rightPartitionFalse;
                    }
                    else if(expression[index]=='|')
                    {
                        if(isTrue==1)
                            ways+=leftPartitionTrue*rightPartitionTrue + leftPartitionFalse*rightPartitionTrue + leftPartitionTrue*rightPartitionFalse;
                        else
                            ways+=leftPartitionFalse*rightPartitionFalse;
                    }
                    else
                    {
                        if(isTrue==1)
                            ways+=leftPartitionFalse*rightPartitionTrue + leftPartitionTrue*rightPartitionFalse;
                        else
                            ways+=leftPartitionFalse*rightPartitionFalse + leftPartitionTrue*rightPartitionTrue;
                    }   
                }
                dp[i][j][isTrue]=ways;
            }
        }
    }
    return dp[0][n-1][1];
}


int main()
{
    
}