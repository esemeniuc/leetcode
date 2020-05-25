#include <bits/stdc++.h>

using namespace std;

struct VectorHash {
    size_t operator()(const array<int, 4> &v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

//https://leetcode.com/problems/3sum/
//vector<vector<int>> fourSum(vector<int> &arr, int target) {
//    int n = arr.size();
//    unordered_map<int, vector<pair<int, int>>> m(n * n); //first idx < second idx
//    unordered_set<array<int, 4>, VectorHash> solTemp;
//
//    sort(arr.begin(), arr.end());
//    for (int i = 0; i < n; ++i) {
//        if (i > 0 && arr[i] == arr[i - 1]) continue;
//        for (int j = i + 1; j < n; ++j) {
//            int sum = arr[i] + arr[j];
//            int complement = target - sum;
//            if (m.count(complement) > 0) {
//                for (auto[k, l] : m[complement]) {
//                    if (i == j || i == k || i == l || j == k || j == l || k == l) {
//                        continue;
//                    }
//                    array<int, 4> compareArr{arr[i], arr[j], arr[k], arr[l]};
//                    sort(compareArr.begin(), compareArr.end());
//                    solTemp.insert(compareArr); //use as part of solution if match
//                }
//            }
//            m[sum].emplace_back(i, j);
//        }
//    }
//
//
//    vector<vector<int>> sol;
//    sol.reserve(solTemp.size());
//    for (const auto &array : solTemp) {
//        sol.emplace_back(array.begin(), array.end());
//    }
//
//    return sol;
//}


//https://leetcode.com/problems/3sum/
//vector<vector<int>> fourSum(vector<int> &arr, int target) {
//    int n = arr.size();
//    unordered_map<int, vector<pair<int, int>>> m(n * n); //first idx < second idx
//    set<vector<int>> solTemp;
//
////    array<int, 4> compareArr;
//    for (int i = 0; i < n; ++i) {
//        for (int j = i + 1; j < n; ++j) {
//            int sum = arr[i] + arr[j];
//            int complement = target - sum;
//            if (m.count(complement) > 0) {
//                //make sure that the indexes are unique, then insert
//                for (pair<int, int> p : m[complement]) {
//                    int a = i, b = j, c = p.first, d = p.second;
//                    if (a == b || a == c || a == d || b == c || b == d || c == d) {
//                        continue;
//                    }
//                    vector<int> compareArr{i, j, p.first, p.second};
//                    sort(compareArr.begin(), compareArr.end());
//                    solTemp.insert(compareArr); //use as part of solution if match
//                }
//            }
//            m[sum].emplace_back(pair<int, int>{i, j});
//        }
//    }
//
//
//    set<vector<int>> solTempData;
//    for (auto &vec : solTemp) {
//        vector<int> dataVec(vec.size());
//        for (int i = 0; i < vec.size(); i++) {
//            dataVec[i] = arr[vec[i]];
//        }
//        sort(dataVec.begin(), dataVec.end());
//        solTempData.insert(dataVec);
//    }
//
//    vector<vector<int>> sol(solTempData.begin(), solTempData.end());
//
//    return sol;
//}

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> a(nums);
    sort(a.begin(), a.end());
    vector<vector<int>> sol;
    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && a[i] == a[i - 1]) { //always try the first idx, but dont exec if current a[i] is the same as before
            //avoid looking ahead because the lookahead can be part of our solution
            continue;
        }
        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && a[j] == a[j - 1]) {
                continue;
            }
            for (int l = j + 1, r = n - 1; l < r;) {
                int sum = a[i] + a[j] + a[l] + a[r];
                if (sum < target) l++;
                else if (sum > target) r--;
                else {
                    sol.emplace_back(vector<int>{a[i], a[j], a[l], a[r]});
                    do { l++; } while (l < r && a[l] == a[l - 1]); //ignore duplicates
                    do { r--; } while (l < r && a[r] == a[r + 1]);
                }
            }
        }
    }
    return sol;
}


int main() {
    vector<int> nums{1, 0, -1, 0, -2, 2};
    assert(fourSum(nums, 0).size() == 3);

    vector<int> nums2{-3,
                      -2,
                      -1,
                      0,
                      0,
                      1,
                      2,
                      3};
    assert(fourSum(nums2, 0).size() == 8);

    vector<int> nums3{-5, 5, 4, -3, 0, 0, 4, -2};
    assert(fourSum(nums3, 4).size() == 2);

    vector<int> nums4{2, -4, -5, -2, -3, -5, 0, 4, -2};
    assert(fourSum(nums4, -14).size() == 3);

}