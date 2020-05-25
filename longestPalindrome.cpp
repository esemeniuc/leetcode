#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/longest-palindromic-substring/

struct answer {
    int startPos;
    int len;
};
answer isPalindrome(const string &s, int l, int r) {
    for (; l >= 0 && r < s.length() && s[l] == s[r]; l--, r++) {}

    return {l + 1, (r - 1) - (l + 1) + 1}; //cant use l since we didnt match, need to offset by 1
    //cant use r, since again no match
    //add 1 to convert from distance to things counted
}

string longestPalindrome(const string &s) {
    int len = 0, idx = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j <= 1; ++j) {
            answer a = isPalindrome(s, i, i + j);
            if (a.len > len) {
                len = a.len;
                idx = a.startPos;
            }
        }
    }
    return s.substr(idx, len);
}

int main() {
    assert(longestPalindrome("") == "");
    assert(longestPalindrome("babad") == "bab");
    assert(longestPalindrome("cbbd") == "bb");
}