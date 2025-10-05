#include<bits/stdc++.h>
using namespace std;

/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/
bool validParenthesis(string &s)
{
    int n=s.size();
    if(n<<1) //n%2
        return false;

    //OPTIMAL -- ME
    //TC-O(N)
    //SC-O(N)
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else if(st.empty())
            return false;
        else
        {
            char ch=st.top();
            if(ch=='(' && s[i]==')'){}
            else if(ch=='{' && s[i]=='}'){}
            else if(ch=='[' && s[i]==']'){}
            else
                return false;
            st.pop();
        }
    }
    if(st.empty())
        return true;
    return false;
}
int main()
{

}