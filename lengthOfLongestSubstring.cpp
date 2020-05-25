#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/longest-substring-without-repeating-characters/

int lengthOfLongestSubstringSlow(const string &s) {
    array<int, 256> lastSeenIdx{};
    array<bool, 256> seen{};
    int sol = 0;
    int l = 0, r = 0;
    for (; r < s.length(); ++r) {
        if (seen[s[r]]) {
            for (; l <= lastSeenIdx[s[r]]; l++) {
                seen[s[l]] = false; //move left up to last location where it was spotted
            }
        }
        seen[s[r]] = true;
        lastSeenIdx[s[r]] = r;
        sol = max(sol, r - l + 1);
    }
    return sol;
}

int lengthOfLongestSubstring(const string &s) {
    array<int, 256> nextValidLocation{};
    int sol = 0;
    for (int l = 0, r = 0; r < s.length(); ++r) {
        l = max(l, nextValidLocation[s[r]]);
        nextValidLocation[s[r]] = r + 1;
        sol = max(sol, r - l + 1);
    }
    return sol;
}

int main() {
//    assert(lengthOfLongestSubstring("a") == 1);
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbb") == 1);
    assert(lengthOfLongestSubstring("pwwkew") == 3);
    assert(lengthOfLongestSubstring(
            "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    )); //FIXME
}

