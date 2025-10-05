#include<bits/stdc++.h>
using namespace std;

//PRIORITY ORDER
// ^    -- 3  (highest priority)
// *,/  -- 2
// +,-  -- 1
// other operators -- -1

int priority(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    return -1;
}



//INFIX ---  (p+q)*(m-n)
//PREFIX --  *- pq - mn    (LISP, pre data structure)
//POSTFIX -  pq - mn -*



/*INFIX TO POSTFIX

a + b *(c^d-e)

i=0 |  value | stack (operators) | ans(operands)
i=1 |   a    |                   |  a
i=2 |   +    |         +         |  a
i=3 |   b    |         +         |  ab
i=4 |   *    |         +*        |  ab
i=5 |   (    |         +*(       |  ab
i=6 |   c    |         +*(       |  abc
i=7 |   ^    |         +*(^      |  abc
i=8 |   d    |         +*(^      |  abcd
i=9 |   -    |         +*(-      |  abcd^             //as the pririty of ^ is more than - so we pop out ^ and place it in ans and push - in the stack
i=10|   e    |         +*        |  abcd^e
i=11|   )    |         +*        |  abcd^e-

FINAL:
postfix ---  abcd^e-*+
*/
string InfixToPostfix(string &s)
{
    //TC-O(n)+O(n)
    //SC-O(n)+O(n)
    int i=0,n=s.size();
    stack<char> st;
    string ans="";
    while(i<n)//O(N)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) //operand
            ans+=s[i];
        else if(s[i]=='(')
            st.push(s[i]);
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')//O(N)
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) //poping opening bracket
                st.pop();
        }
        else //operator
        {
            while(!st.empty() && priority(s[i])<=priority(st.top()))//O(N)
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}


/*INFIX TO PREFIX

1. reverse the infix
2. infix to postfix conversion
3. reverse the postfix obtained

1.
(A+B)*C-D+F
      |
      |
F+D-C*(A+B) 

i=0 |  value | stack (operators) | ans(operands)
i=1 |   F    |                   |  F
i=2 |   +    |         +         |  F
i=3 |   D    |         +         |  FD
i=4 |   -    |         +-        |  FD //we don't change the stack order on basis of priority order
i=5 |   C    |         +-        |  FDC
i=6 |   *    |         +-*       |  FDC
i=7 |   (    |         +-*(      |  FDC
i=8 |   A    |         +-*(      |  FDC
i=9 |   +    |         +-*(+     |  FDCA
i=10|   B    |         +-*(+     |  FDCA
i=11|   )    |         +-*(+     |  FDCAB

FINAL:
postfix ---  FDCAB+*-+
PREFIX  ---  +-*+ABCDF
*/
string InfixToPrefix(string s)
{
    //TC-O(n/2)+O(n/2)+O(2n)
    //SC-O(2n)
    int i=0,n=s.size();
    stack<char> st;
    string ans="";
    reverse(s.begin(),s.end());
    while(i<n)//O(N)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) //operand
            ans+=s[i];
        else if(s[i]==')')
            st.push(s[i]);
        else if(s[i]=='(')
        {
            while(!st.empty() && st.top()!=')')//O(N)
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) //poping opening bracket
                st.pop();
        }
        else //operator
        {//conditional
            if(s[i]=='^') //two ^ canot be together
            {
                while(!st.empty() && priority(s[i])<=priority(st.top()))
                {
                    ans+=st.top();
                    st.pop();
                }
            }
            else
            {
                while(!st.empty() && priority(s[i])<priority(st.top()))
                {
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


/*POSTFIX TO INFIX

AB-DE+F * /


i |    stack
A |     A
B |     AB
- |     (A-B),          //whenever we incounter the operator we take the last 2 operand and and the operator between the 2 operands
// HERE WE DO SECOND TOP OPERAND + OPERATOR + FIRST TOP OPERAND
D |     (A-B),D
E |     (A-B),D,E
+ |     (A-B),(D+E)
F |     (A-B),(D-E),F
* |     (A-B),(D-E)*F
/ |     (A-B)/((D-E)*F)

FINAL
INFIX --- (A-B)/((D-E)*F)
*/
string PostfixToInfix(string &s)
{
    //TC-O(N)
    //SC-O(N)
    int i=0;
    int n=s.size();
    stack<string>st;
    while(i<n)//O(N)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) //operand
            st.push(s[i]+"");
        else
        {
            string s1=st.top();//n1=s1.size()
            st.pop();
            string s2=st.top();//n2=s2.size()
            st.pop();
            st.push("("+s2+s[i]+s1+")");//O(n1+n2) 
            // HERE WE DO SECOND LAST OPERAND + OPERATOR + LAST OPERAND
        }
        i++;
    }
    return st.top();
}


/*PREFIX TO INFIX

*+PQ-MN

HERE WE ITERATE FROM THE BACK

i |     stack
N |     N
M |     N,M
- |     (M-N)           //HERE WE DO FIRST TOP + OPERATOR + SECOND TOP
Q |     (M-N),Q
P |     (M-N),Q,P
+ |     (M-N),(P+Q)
* |     ((P+Q)*(M-N))

FINAL
Infix --- ((P+Q)*(M-N))
*/
string PrefixToInfix(string &s)
{
    //TC-O(n)+O(n)
    //SC-O(n)
    int n=s.size();
    int i=n-1;
    stack<string> st;
    while(i>=0)//O(n)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) //operand
            st.push(s[i]+"");
        else
        {
            string s1=st.top();//n1=s1.size()
            st.pop();
            string s2=st.top();//n2=s2.size()
            st.pop();
            st.push("(" + s1 + s[i] + s2 + ")");//O(n1+n2)
            //HERE WE DO FIRST TOP + OPERATOR + SECOND TOP
        }
        i--;
    }
    return st.top();
}


/*POSTFIX TO PREFIX

AB-DE+F * /

i |     stack
A |     A
B |     A,B
- |     -AB              //HERE WE TAKE THE LAST TWO OPERANDS AND INSERT THE OPERATOR BEFORE THE OPERANDS
//OPERATOR + TOP2 + TOP1
D |     -AB,D
E |     -AB,D,E
+ |     -AB,+DE
F |     -AB,+DE,F
* |     -AB,*+DEF
/ |     /-AB*+DEF

FINAL
Prefix ---  /-AB*+DEF
*/
string PostfixToPrefix(string &s)
{
    //TC-O(n)
    //SC-O(n)
    int i=0;
    int n=s.size();
    stack<string> st;
    while(i<n)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) //operand
            st.push(s[i]+"");
        else
        {
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            st.push(s[i] + s2 + s1);//OPERATOR + TOP2 + TOP1
        }
        i++;
    }
    return st.top();
}


/*PREFIX TO POSTFIX

/-AB*+DEF

HERE WE START FROM LAST

i |     stack
F |     F
E |     F,E
D |     F,E,D
+ |     F,DE+        //FIRST TOP + SECOND TOP + OPERATOR
* |     DE+F*
B |     DE+F*,B
A |     DE+F*,B,A
- |     DE+F*,AB-
/ |     AB-DE+F* /


FINAL
Postfix ---  AB-DE+F* /
*/
string PrefixToPostfix(string &s)
{
    //TC-O(2n)
    //SC-O(n)
    int n=s.size();
    int i=n-1;
    stack<string> st;
    while(i>=0)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) //operand
            st.push(s[i]+"");
        else
        {
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            st.push(s1 + s2 + s[i]);
            //FIRST TOP + SECOND TOP + OPERATOR
        }
        i--;
    }
    return st.top();
}




int main()
{
    
}