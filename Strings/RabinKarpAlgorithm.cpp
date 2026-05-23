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


int main()
{
    
}