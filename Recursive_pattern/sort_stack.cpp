#include<bits/stdc++.h>
using namespace std;

void insertStack(stack<int> &st,int element)
{
    if(st.empty() || st.top()<=element)
    {
        st.push(element);
        return;
    }
    int topElement=st.top();
    st.pop();
    insertStack(st,element);
    st.push(topElement);
}
void sortStack(stack<int> &st)
{
    if(st.empty())
        return ;
    int topElement=st.top();
    st.pop();
    sortStack(st);
    insertStack(st,topElement);
}
int main()
{
    stack<int> st;
    int n;
    cout << "Enter the number of elements in stack: ";
    cin >> n;
    for (int  i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        st.push(num);
    }
    
    return 0;
}
