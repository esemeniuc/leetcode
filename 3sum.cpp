#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/3sum/
/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
*/
//vector<vector<int>> threeSum(const vector<int> &nums) {
//    int n = nums.size();
//    vector<int> a(nums);
//    sort(a.begin(), a.end());
//    vector<vector<int>> sol;
//    for (int i = 0; i < n-2; ++i) {
//        if (i > 0 && a[i] == a[i - 1]) { //always try the first idx, but dont exec if current a[i] is the same as before
//            //avoid looking ahead because the lookahead can be part of our solution
//            continue;
//        }
//        for (int l = i + 1, r = n - 1; l < r;) {
//            int sum = a[i] + a[l] + a[r];
//            if (sum < 0 || (l > i + 1 && a[l] == a[l - 1])) { //avoid lookahead since it can be part of solution
//                l++;
//            } else if (sum > 0 || (r + 1 < n && a[r] == a[r + 1])) {
//                r--;
//            } else {
//                sol.emplace_back(vector<int>{a[i], a[l], a[r]});
//                l++;
//                r--;
////                do{l++;}while{}
//            }
//        }
//
//    }
//    return sol;
//}

vector<vector<int>> threeSum(const vector<int> &nums) {
    int n = nums.size();
    vector<int> a(nums);
    sort(a.begin(), a.end());
    vector<vector<int>> sol;
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && a[i] == a[i - 1]) { //always try the first idx, but dont exec if current a[i] is the same as before
            //avoid looking ahead because the lookahead can be part of our solution
            continue;
        }
        for (int l = i + 1, r = n - 1; l < r;) {
            int sum = a[i] + a[l] + a[r];
            if (sum < 0) l++;
            else if (sum > 0) r--;
            else {
                sol.emplace_back(vector<int>{a[i], a[l], a[r]});
                do { l++; } while (l < r && a[l] == a[l - 1]); //ignore duplicates
                do { r--; } while (l < r && a[r] == a[r + 1]);
            }
        }

    }
    return sol;
}

int main() {
//    vector<vector<int>> v{{2, 3, 4}};
    vector<int> nums{-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
    assert(threeSum(nums).size() == 6);

    vector<vector<int>> v2{{-1, -1, 2},
                           {-1, 0,  1},};
    vector<int> nums2{-1, 0, 1, 2, -1, -4};
    assert(threeSum(nums2) == v2);

}