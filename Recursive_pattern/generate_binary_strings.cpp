#include<bits/stdc++.h>
using namespace std;



void binaryStrings(vector<string> &ans,string current,int n)
{
    if(current.size()==n)
    {
        ans.push_back(current);
        return;
    }
    binaryStrings(ans,current+'0',n);
    if(current.empty() || current.back()!='1')
    {
        binaryStrings(ans,current+'1',n);
        return;
    }
}
vector<string> generateBinaryStrings(int n) {
    // Your code goes here
    vector<string> ans;
    binaryStrings(ans,"",n);
    return ans;
}
int main()
{
    int n;
    cout << "Enter the length of binary strings: ";
    cin >> n;

    return 0;
}