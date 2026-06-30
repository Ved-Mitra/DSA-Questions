#include <bits/stdc++.h>
using namespace std;

//Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.
//Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

//RABIN-KARP ALGORITHM
/*
For a string s of length m, the simple hash is 

hash(s) = (s[0] × d(m−1) + s[1] × d(m−2) + ... + s[m−1] × d0) % q

Here,

s[i] represents the ASCII value of the character ('a' = 97, 'b' = 98, ..., 'z' = 122)
d is the size of the input alphabet (commonly 256 for ASCII characters)
q is a prime number used as modulus (commonly 101, 1000000007, etc.)

Using modulo helps prevent integer overflow and reduces hash collisions.


Updation:
hash(i, j) = (d * (hash(i−1, j−1) − s[i−1] * d(m−1) )+ s[j]) mod q

*/

int BASE= 10000000;
int repeatedStringMatch(string a, string b) {
    int n=a.size(),m=b.size();
    int hash=0,p=1e9 + 7;
    string s=a;
    int cnt=1;
    while(s.size()<b.size()){
        cnt++;
        s+=a;
    }
    if(s==b) return cnt;
    if(Rabin_Karp(s,b)!=-1) return cnt;
    if(Rabin_Karp(s+a,b)!=-1) return cnt+1;
    return -1;
}
int Rabin_Karp(string source,string target){
    int m=target.size();
    if(source=="" || target=="") return -1;
    int power=1;
    for(int i=0;i<m;i++){
        power=(power*31)%BASE;
    }
    int targetCode=0;
    for(int i=0;i<m;i++){
        targetCode=(targetCode*31 + target[i])%BASE;
    }
    int hashCode=0;
    int n=source.size();
    for(int i=0;i<n;i++){
        hashCode=(hashCode*31 + source[i])%BASE;
        if(i<m-1)
            continue;
        if(i>=m){
            hashCode = (hashCode - source[i-m]*power)%BASE;
        }
        if(hashCode<0){
            hashCode+=BASE;
        }
        if(hashCode==targetCode){
            if(source.substr(i-m+1,m)==target){
                return i-m+1;
            }
        }
    }
    return -1;
}

int main()
{
    
}
