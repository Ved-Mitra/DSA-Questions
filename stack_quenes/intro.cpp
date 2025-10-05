#include<bits/stdc++.h>
using namespace std;

//stack (last int first out) (LIFO)
//queue (first in first out) (FIFO)

//static memory
class stack_implementation_array
{
    //TC-O(1)
    //SC-O(n)

    int top=-1;
    static const int n=10;
    int st[n];
    //disadvantage -- static
    void push(int x)
    {
        if(top>=n)
        {
            cout << "Size exceeded";
            return ;
        }
        top++;
        st[top]=x;
    }
    int top()
    {
        if(top==-1)
        {
            cout << "Stack is empty";
            return ;
        }
        return st[top];
    }
    void pop()
    {
        if(top==-1)
        {
            cout << "Stack is empty";
            return ;
        }
        top--;
    }
    int size()
    {
        return top+1;
    }
    bool empty()
    {
        return top==-1;
    }
};
class queue_implementation_array
{
    //TC-O(1)
    //SC-O(n)

    int n=10;
    int queue[10];

    int currSize=0;
    int start=-1,end=-1;

    int size()
    {
        return currSize;
    }
    void push(int x)
    {
        if(currSize==n)
        {
            cout << "Size exceeded";
            return;
        }
        if(currSize==0)
        {
            start=0;
            end=0;
        }
        else
            end=(end+1)%n;
        queue[end]=x;
        currSize++;
    }
    int top()
    {
        if(currSize==0)
        {
            cout << "Queue is empty";
            return;
        }
        return queue[start];
    }
    int pop()
    {
        if(currSize==0)
        {
            cout << "Queue is empty";
            return;
        }
        int element=queue[start];
        if(currSize==1)
        {
            start=-1;
            end=-1;
        }
        else
            start=(start+1)%n;
        currSize--;
        return element;
    }
    int size()
    {
        return currSize;
    }
    bool empty()
    {
        return currSize==0;
    }
};


//dyanamic memory
class Node
{
    public:
    int val;
    Node* next;

    public:
    Node(int data)
    {
        val=data;
        next=nullptr;
    }

    public:
    Node(int data,Node* next1)
    {
        val=data;
        next=next1;
    }
};
class stack_implementation_LL
{
    Node* top=nullptr;
    int size=0;

    void push(int x)
    {
        Node* temp=new Node(x);
        temp->next=top;
        top=temp;
        size++;
    }
    void pop()
    {
        Node* temp=top;
        top=top->next;
        delete temp;
        size--;
    }
    int size()
    {
        return size;
    }
    int top()
    {
        return top->val;
    }
    bool empty()
    {
        return size==0;
    }
};
class queue_implementation_LL
{
    Node* start=nullptr,*end=nullptr;
    int size=0;

    void push(int x)
    {
        Node* temp=new Node(x);
        if(start==nullptr && end==nullptr)
        {
            start=temp;
        }
        else
        {
            end->next=temp;
        }
        end=temp;
        size++;
    }
    int size()
    {
        return size;
    }
    int pop()
    {
        if(size==0)
        {
            cout << "Queue is Empty";
            return;
        }
        int data=start->val;
        Node* delNode=start;
        start=start->next;
        delete delNode;
        size--;
        if(start==nullptr)
        {
            end=nullptr;
        }
        return data;
    }
    bool empty()
    {
        return size==0;
    }
    int top()
    {
        if(start==nullptr)
        {
            cout << "Queue is empty";
            return;
        }
        return start->val;
    }
};


//Interesting
class Stack_implementation_queue
{
    queue<int> q;
    void push(int x)
    {
        int n=q.size();
        q.push(x);
        for(int i=1;i<=n;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    int pop()
    {
        int val=q.front();
        q.pop();
        return val;
    }
    int size()
    {
        return q.size();
    }
    bool empty()
    {
        return q.empty();
    }
    int top()
    {
        return q.front();
    }
};
class Queue_implementation_stack
{
    stack<int> st;
    void push(int x)
    {
        int n=st.size();
        stack<int> st2;
        for(int i=1;i<=n;i++)
        {
            st2.push(st.top());
            st.pop();
        }
        st.push(x);
        for(int i=1;i<=n;i++)
        {
            st.push(st2.top());
            st2.pop();
        }
    }
    int pop()
    {
        int val=st.top();
        st.pop();
        return val;
    }
    int peek()
    {
        return st.top();
    }
    bool empty()
    {
        return st.empty();
    }
};



int main()
{

}