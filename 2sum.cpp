#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/2sum/

/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
vector<int> twoSum(const vector<int> &nums, int target) {
    unordered_map<int, int> m(nums.size()); //map the value to idx
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (m.count(complement) > 0 && m[complement] != i) {
            return {m[complement],i};
        }
        m[nums[i]] = i; //uses latest idx
    }

    return {-1, -1};
}

int main() {
    vector<int> v{1, 2};
    assert(twoSum({0, 1, 3}, 4) == v);
    vector<int> v2{-1, -1};
    assert(twoSum({0, 1, 3}, 0) == v2);
    vector<int> v3{0,1};
    assert(twoSum({3,3}, 6) == v3);
}