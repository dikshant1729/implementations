#include<bits/stdc++.h>
using namespace std;
int main(){

    auto  LongestPalindromicPrefix = [&](string str) ->int{
    string temp = str + '?';
    reverse(str.begin(), str.end());
    temp += str;
    int n = temp.length();
    int lps[n];
    fill(lps, lps + n, 0);
    for (int i = 1; i < n; i++) {
        int len = lps[i - 1];
        while (len>0 && temp[len]!=temp[i]){
            len = lps[len - 1];
        }
        if (temp[i] == temp[len]) {
            len++;
        }
        lps[i] = len;
    }
    return lps[n-1];
    // string is s.subsr(0, lps[n-1]);
    };

    // there is also a manacher's algorithm to find longest palindromic susbstring
    
}