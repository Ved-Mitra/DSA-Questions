#include<bits/stdc++.h>
using namespace std;


string convert2Binary(int n)
{
    string res="";
    while(n!=1)
    {
        if(n%2==1)
            res+='1';
        else
            res+='0';
        n/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}
int convert2Decimal(string x)
{
    int n=x.size();
    int power=1;
    int num=0;
    for(int i=n-1;i>=0;i--)
    {
        if(x[i]=='1')
            num+=(power);
        power*=2;
    }
}
string _1sComplement(int n)
{
    string res=convert2Binary(n);
    int len=res.size();
    //just flip the binary conversion
    for(int i=len-1;i>=0;i--)
    {
        if(res[i]=='1')
            res[i]='0';
        else
            res[i]='1';
    }
    return res;
}
string _2sComplement(int n)
{
    string s=_1sComplement(n);
    int len=s.size();
    int carry=1;
    //just add 1 to 1s complement
    for(int i=len-1;i>=0;i--)
    {
        int n1=s[i]-'0' + carry;
        carry=0;
        if(n1==2)
        {
            s[i]='0';
            carry=1;
        }
        if(carry==0)
            break;
    }
    if(carry==1)
        s.insert(0,1,'1');
    return s;
}

//IN XOR
//number of 1s odd --->1
//number of 1s even --->0
/*  0 1 1 0 1
  ^ 0 0 1 1 1
  -------------
  0 0 1 0 1 0
*/


//In binary computer uses the 31st bit to store sign
// if 31st bit  1 ---> negative
//              0 ---> positive


//IN NOT(~)
/*
1. flip the number in binary form
2. checks if -ve --->yes (returns 2s Complement)
                 --->no (stops)
*/

bool powerOf2(int n)
{
    //using shift left
    // 13>>1
    // 1101 >> 1 -----> 0110

    //basically shift right means
    // k >> x = k/(2^x)

    int num = n & (n-1);
    if(num==0)
        return true;
    return false;
}
void swap(int &n1,int &n2)
{
    //using XOR
    n1=n1^n2;
    n2=n1^n2;
    n1=n1^n2;
}
bool check_ith_bit_Set(int n,int bit)
{
    //set means that the bit is 1 or not
    string res=convert2Binary(n);
    return res[bit]=='1'?1:0;


    //M-2
    int num= n & (1<<bit);
    /*
    Example:
    n=13,bit=2
       1 1 0 1
    &  0 1 0 0
       -------
       0 1 0 0    = 4 > 0
    */
    return num>0?1:0;


    //M-3
    int num2= (n >> bit) & 1;
    /*
    Example:
    n=13,bit=2
        1 1 0 1
        
        13 >> 2 = 1101 >> 2 = 11 
                            = 11 & 1  = 01
    */
    return num2>0?1:0;

}
int set_ith_bit(int n,int bit)
{
    int num = n | (1 << bit);
    return num;
}
int clear_ith_bit(int n,int bit)
{
    //make the ith bit zero
    int num = n & (~(1 << bit));
    return num;
}
int toggle_ith_bit(int n,int bit)
{
    int num = n ^ (1<< bit);
    return num;
}
int removeTheLastSet_bit_rightmost(int n)
{
    int num = n &(n-1);
    return num;
}
int count_set_bit(int num)
{
    int cnt=0;
    while(num>0)
    {
        if(num%2!=0) //last bit of odd number os always 1
            cnt++;
        /*
        can be written as

        cnt +=(n&1)
        n=n>>1

        bit calculation are faster
        */
        num/=2;
    }
    return cnt;



    //M-2
    cnt=0;
    while(num!=0)
    {
        num=num&(num-1);
        cnt++;
    }
    return cnt;
}



int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    return 0;
}