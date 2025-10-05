#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &num)
{
    //the num has two numbers in one times return them rest are in even number
    
    //concept of buckets
    //TC-O(2n)
    //SC-O(1)
    int n=num.size();
    long XOR=0;
    for(int i=0;i<n;i++)
    {
        XOR^=num[i];
    }
    int rightmost=(XOR & (XOR-1)) & XOR; //rightmost first set bit
    int b1=0,b2=0;
    for(int i=0;i<n;i++)
    {
        if(num[i] & rightmost)
            b1=b1^num[i];
        else
            b2=b2^num[i];
    }
    return {b1,b2};
}


int main()
{

}