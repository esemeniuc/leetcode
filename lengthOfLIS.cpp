#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/longest-increasing-subsequence/

int lengthOfLIS(const vector<int> &a) {
    int n = a.size();
    if (n == 0) {
        return 0;
    }
    vector<int> dp{a.front()};
    dp.reserve(n);
    for (int i = 1; i < n; ++i) {
        if (a[i] > dp.back()) {
            dp.push_back(a[i]);
        } else {
            auto it = lower_bound(dp.begin(), dp.end(), a[i]);
            *it = a[i];
        }
    }
    return dp.size();
}

int main() {
    assert(lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    return 0;
}

