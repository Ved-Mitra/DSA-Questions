#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st,int element)
{
    if(st.empty())
    {
        st.push(element);
        return;
    }
    int topElement=st.top();
    st.pop();
    insertAtBottom(st,topElement);
    st.push(topElement);
}
void reverseStack(stack<int> &st)
{
    if(st.empty())
        return;
    int topElement=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,topElement);
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
