//hashing- prestore and fetching
#include<bits/stdc++.h>
using namespace std;


/*
IMPORTANT INFORMATION
LIMIT OF ARRAY SIZE:

INT
1. INSIDE MAIN FUNCTION -----> 10^6 + 1
2. GLOBAL VARIABLE ----------> 10^7 +1

BOLLEAN
1. INSIDE MAIN FUNCTION -----> 10^7 + 1
2. GLOBAL VARIABLE ----------> 10^8 +1
*/



//SINCE YOU CANNOT HASH 10^12 OR ECT ARRAY IN C++, SO WE USE
// C++ -----> STC (MAPS)
//JAVA -----> COLLECTION



//Example-1 (NUMBER HASHING)
int main_int()
{
    int n;
    cin >> n; //size of arr
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    //pre-compute
    int hash[13]={0}; //already stated in question that the array has numbers from 0 to 12
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]+=1;
    }

    int q;
    cin >> q; //number of queries
    while(q--)
    {
        int number;
        cin >> number; //number to be checked
        //fetch
        cout << hash[number] << endl;
    }
}
int map_int()//stores in sorted order
{
    int n;
    cin >> n; //size of arr
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    //pre-compute
    map <int,int> mpp; //by default all value with no key have value 0
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]+=1;
    }

    int q;
    cin >> q; //number of queries
    while(q--)
    {
        int number;
        cin >> number; //number to be checked
        //fetch
        cout << mpp[number] << endl;
    }
}

//EXAMPLE-2: (CHARACTER HASHING)
int main_char()
{
    
    int n=26;
    //cin >> n; //size of arr
    char arr[n];
    for(int i=0;i<n;i++)//arr has only lowercase letters
        cin >> arr[i];
    
    //pre-compute
    int hash[13]={0}; //already stated in question that the array has numbers from 0 to 12
    for(int i=0;i<n;i++)
    {
        hash[arr[i]-97]+=1;
    }

    int q;
    cin >> q; //number of queries
    while(q--)
    {
        char letter;
        cin >> letter; //number to be checked
        //fetch
        cout << hash[letter] << endl;
    }
    //if including lowercase and uppercase letters
    //use array of arr[256]
}


int main()
{
    return 0;
}
//THEORY:
/*
HASHING :
1. DIVISION METHOD
2. FOLDING METHOD
3. MID SQUARE METHOD
*/