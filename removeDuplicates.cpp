#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

    string removeDuplicates(const string &a) {
        vector<char> s;
        s.reserve(a.length());

        for(char c : a){
            s.emplace_back(c);
            if(s.size() > 1 && s[s.size()-1] == s[s.size()-2]){
                s.pop_back();
                s.pop_back();
            }
        }

        return string(s.begin(), s.end());
    }

int main() {
    assert(removeDuplicates("abbaca") == "ca");
    return 0;
}

