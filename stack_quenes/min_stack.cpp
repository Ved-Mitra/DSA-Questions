#include<bits/stdc++.h>
using namespace std;

/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.*/


//BETTER
//TC-O(1)
//SC-O(2*n)
class MinStack {
    stack<pair<int,int>>st; //val,min
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minn;
        if(st.empty())
        {
            minn=val;
        }
        else
        {
            minn=st.top().second;
            minn=min(minn,val);
        }
        st.push({val,minn});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
       return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};


//OPTIMAL
//TC-O(1)
//SC-O(n)

/*
DERIVATION OF FORMULA
10<12
val < min
val - min < 0
val + val - min < val
2*val - min < val
newValue < val

    Here,           newValue= 2*val - min
*/

// newValue = 2*val - prev_minimum

//we apply this formula to the value only that modifyies aour minimum
class MinStack {
    stack<int> st;
    int mini;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty())
        {
            mini=val;
            st.push(val);
        }
        else
        {
            if(val>mini)
                st.push(val);
            else
            {
                st.push(2*val - mini);
                mini=val;
            }
        }
    }
    void pop() {
        if(!st.empty())
        {
            int x=st.top();
            st.pop();
            if(x<mini)//modified value
            {
                mini=2*mini-x;
            }
        }
    }
    int top() {
        if(!st.empty())
        {
            int x=st.top();
            if(mini<x)
                return x;
            return mini;
        }
    }
    int getMin() {
        return mini;
    }
};

int main()
{

}