#include<bits/stdc++.h>
using namespace std;


// Helper function to convert a digit character to integer
int charToDigit(char ch) {
    return ch - '0';
}

// Recursive atoi implementation
int myAtoiRecursive(const string& str, int index = 0) {
    if (index == str.length())
        return 0;

    int digit = charToDigit(str[index]);

    int result = digit * pow(10, str.length() - index - 1) + myAtoiRecursive(str, index + 1);

    return result;
}

// Handles sign and validates input
int myAtoi(const string& str) {
    int start = 0;
    bool isNegative = false;

    if (str[0] == '-') {
        isNegative = true;
        start = 1;
    } else if (str[0] == '+') {
        start = 1;
    }

    string numericPart = str.substr(start);

    int result = myAtoiRecursive(numericPart);

    return isNegative ? -result : result;
}
int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    return 0;
}
