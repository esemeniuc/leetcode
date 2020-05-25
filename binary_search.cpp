#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

int search(const vector<int> &a, int t) {
    int n = a.size();
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (t < a[m]) {
            r = m - 1;
        } else if (t > a[m]) {
            l = m + 1;
        } else { //must be equal
            return m;
        }
    }
    return -1;
}

int lsearch(const vector<int> &a, int t) {
    int n = a.size();
    int l = 0;
    int r = n - 1;
    while (l < r) {
        int m = (l + r) / 2; //floor
        if (t > a[m]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (a[l] == t) {
        return l;
    }
    return -1;
}

int rsearch(const vector<int> &a, int t) {
    int n = a.size();
    int l = 0;
    int r = n - 1;
    while (l < r) {
        int m = (l + r + 1) / 2; //+1 for ceiling
        if (t < a[m]) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    if (a[r] == t) {
        return r;
    }
    return -1;
}


vector<int> searchRange(const vector<int> &a, int t) {
    int l = lsearch(a, t), r = rsearch(a, t);
    return {l, r};
}

int search2(const vector<int> &a, int t) {
    auto out = lower_bound(a.begin(), a.end(), t);
    if (out == a.end() || *out != t) {
        return -1;
    }
    return out - a.begin();
}

int main() {
//    assert(search2({-1, 0, 3, 5, 9, 12}, 9) == 4);
//    assert(search2({-1, 0, 4, 5, 9, 12}, 2) == -1);
    int res = lsearch({-1, 0, 2, 2, 2, 2, 2, 4, 5, 9, 12}, 2);
    assert(res == 2);
    assert(lsearch({-1, 0, 2, 2, 2, 2, 2, 2, 24, 5, 9, 12}, 2) == 2);
    assert(lsearch({-1, 0, 2, 2, 2, 2, 2, 2, 2, 24, 5, 9, 12}, 2) == 2);
    assert(lsearch({2, 2, 2, 2, 2, 2, 2, 24, 5, 9, 12}, 2) == 0);
//
    assert(rsearch({-1, 0, 2, 2, 2, 2, 2, 4, 5, 9, 12}, 2) == 6);
    assert(rsearch({-1, 0, 2, 2, 2, 2, 2, 2, 24, 5, 9, 12}, 2) == 7);
    return 0;
}

