#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> SquareRootDecompose(string &s,vector<int> &blockIdx)
{
    int n=s.size();
    int blockSize=sqrt(n);
    vector<vector<int>> hashArrays;
    int i=0,blockCnt=0;
    while(i<n)
    {
        vector<int> hashArray(26,0);
        for(int j=0;j<blockSize && i<n;j++)
        {
            blockIdx[i]=blockCnt;
            hashArray[s[i]-'a']++;
            i++;
        }
        hashArrays.push_back(hashArray);
        blockCnt++;
    }
    return hashArrays;
}

vector<int> StringQuery(string &s,vector<vector<string>> &queries)
{
    int n=s.size();
    vector<int> blockIdx(n);
    vector<vector<int>> hashArrays=SquareRootDecompose(s,blockIdx);
    vector<int> ans;
    for(int i=0;i<queries.size();i++)
    {
        if(queries[i][0]=="1")
        {
            char new_ch=queries[i][2][0];
            int idx=stoi(queries[i][1])-1;
            char old_ch=s[idx];
            hashArrays[blockIdx[idx]][old_ch-'a']--;
            hashArrays[blockIdx[idx]][queries[i][2][0]-'a']++;
            s[idx]=new_ch;
        }
        else
        {
            int l=stoi(queries[i][1])-1,r=stoi(queries[i][2])-1; //to handle the 1-based indexing in the queries
            char ch=queries[i][3][0];
            int blockIdx_l=blockIdx[l],blockIdx_r=blockIdx[r];
            int freq=0;
            for(int j=l;blockIdx[j]==blockIdx_l && j<=r;j++)//head block
            {
                if(s[j]==ch)
                    freq++;
            }
            for(int j=blockIdx_l+1;j<blockIdx_r;j++)//body blocks
            {
                freq+=hashArrays[j][ch-'a'];
            }
            for(int j=r;blockIdx_l!=blockIdx_r && blockIdx[j]==blockIdx_r;j--)//tail block
            {
                if(s[j]==ch)
                    freq++;
            }
            ans.push_back(freq);
        }
    }
    return ans;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    string str="";
    cout << "Enter the String :" ;
    cin >> str;

    vector<vector<string>> queries;
    int n;
    cout << "Enter the number of Queries: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string type;
        cin >>type;
        if(type=="1")
        {
            int i;
            string c;
            cin >> i >> c;
            queries.push_back({type,to_string(i),c});
        }
        else
        {
            int l,r;
            string c;
            cin >> l >> r >> c;
            queries.push_back({type,to_string(l),to_string(r),c});
        }
    }

    vector<int> res=StringQuery(str,queries);
    for(int i=0;i<res.size();i++)
        cout << res[i] << '\n';
    return 0;
}