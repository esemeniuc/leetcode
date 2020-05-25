#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/longest-consecutive-sequence/

//struct UF {
//    unordered_map<int, int> parent;
//    unordered_map<int, int> size;
//
//    UF(vector<int> a) : parent(unordered_map<int, int>(a.size())),
//                        size(unordered_map<int, int>(a.size())) {
//        for (int i = 0; i < a.size(); ++i) {
//            parent[a[i]] = a[i];
//            size[a[i]] = 1;
//        }
//    }
//
//    int find(int x) {
//        while (x != parent[x]) { //path halving
//            parent[x] = parent[parent[x]];
//            x = parent[x];
//        }
//        return x;
//    }
//
//    void union2(int x, int y) {
//        int xRoot = find(x);
//        int yRoot = find(y);
//
//        if (xRoot == yRoot) {
//            return;
//        }
//        if (size[xRoot] > size[yRoot]) {
//            parent[yRoot] = xRoot;
//            size[xRoot] += size[yRoot];
//        } else { //make x join under y
//            parent[xRoot] = yRoot;
//            size[yRoot] += size[xRoot];
//        }
//    }
//
//    int getLargestSetSize() {
//        if (parent.size() == 0) {
//            return 0;
//        }
//        int rMax = 0;
//        for (auto &p : size) {
//            rMax = max(rMax, p.second);
//        }
//        return rMax;
//    }
//
//    bool hasNode(int x) {
//        return parent.count(x) > 0;
//    }
//};
//
//
//int longestConsecutive(const vector<int> &nums) {
//    int n = nums.size();
//    UF uf(nums);
//    for (int i = 0; i < n; ++i) {
//        int left = nums[i] - 1, right = nums[i] + 1;
//        if (uf.hasNode(left)) {
//            uf.union2(left, nums[i]);
//        }
//        if (uf.hasNode(right)) {
//            uf.union2(right, nums[i]);
//        }
//    }
//
//    int largest = uf.getLargestSetSize();
//    return largest;
//}

//int dfs(unordered_map<int, bool> &visited, int x) {
//    if (visited.count(x) == 0 || visited[x]) {
//        return 0;
//    }
//
//    visited[x] = true;
//    int left = x - 1, right = x + 1;
//    return dfs(visited, left) + dfs(visited, right) + 1;
//}
//
//int longestConsecutive(const vector<int> &nums) {
//    int n = nums.size();
//    unordered_map<int, bool> visited(nums.size());
//    for (int num : nums) {
//        visited[num] = false;
//    }
//
//    int rMax = 0;
//    for (int num : nums) {
//        int val = dfs(visited, num);
//        rMax = max(rMax, val);
//    }
//
//    return rMax;
//}

int longestConsecutive(const vector<int> &nums) {
    int n = nums.size();
    unordered_set<int> s(nums.begin(), nums.end());

    int rMax = 0;
    for (int num : nums) {
        if (s.count(num) == 0) {
            continue;
        }

        int left = num - 1, right = num + 1;
        while (s.erase(left) > 0) {
            left--;
        }
        while (s.erase(right) > 0) {
            right++;
        }
        rMax = max(rMax, right - left - 1);
    }

    return rMax;
}


int main() {
    assert(longestConsecutive({1, 2, 0, 1}) == 3);
    assert(longestConsecutive({}) == 0);
    assert(longestConsecutive({0}) == 1);
    assert(longestConsecutive({0, -1}) == 2);
    assert(longestConsecutive({100, 4, 200, 1, 3, 2}) == 4);
}