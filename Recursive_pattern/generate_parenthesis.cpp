#include<bits/stdc++.h>
using namespace std;

void generate(vector<string> &ans,string current,int cnt1,int cnt2,int n)
{
    if(current.size()==2*n)
    {
        ans.push_back(current);
        return;
    }
    if(cnt1<n)
        generate(ans,current+"(",cnt1+1,cnt2,n);
    if(cnt2<cnt1)
        generate(ans,current+")",cnt1,cnt2+1,n);

}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    generate(ans,"",0,0,n);
    return ans;
}
int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    return 0;
}