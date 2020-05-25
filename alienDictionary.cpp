#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/alien-dictionary/

//hashes a character
inline uint8_t enc(char c) {
    return c - 'a';
}

inline char dec(uint8_t x) {
    return x + 'a';
}

string alienOrder(const vector<string> &words) {
    array<vector<uint8_t>, 26> adj{};
    array<int, 26> inDeg{};
    array<bool, 26> seen{};
    for (const auto &word : words) {
        for (char j : word) {
            seen[enc(j)] = true;
        }
    }

    for (int i = 0; i + 1 < words.size(); i++) {
        size_t lim = min(words[i].size(), words[i + 1].size());
        int lastMatchingIdx = 0;
        for (; lastMatchingIdx < lim && words[i][lastMatchingIdx] == words[i + 1][lastMatchingIdx]; ++lastMatchingIdx);
        if (lastMatchingIdx == lim && words[i].size() > words[i + 1].size()) {
            return ""; //invalid ordering
        }

        for (int j = 0; j < lim; ++j) {
            if (words[i][j] != words[i + 1][j]) {
                adj[enc(words[i][j])].emplace_back(enc(words[i + 1][j])); //parent points to child
                inDeg[enc(words[i + 1][j])]++;
                break; //can only have 1 difference
            }
        }
    }

    vector<uint8_t> q;
    q.reserve(26);
    string sol;
    sol.reserve(26);

    //start with all nodes that have no dependencies
    for (int i = 0; i < inDeg.size(); ++i) {
        if (inDeg[i] == 0 && !adj[i].empty()) { //only start with nodes that have children
            q.emplace_back(i); //CHECK THIS
        }
    }

    while (!q.empty()) {
        uint8_t u = q.back();
        sol.push_back(dec(u));
        q.pop_back();

        for (uint8_t v : adj[u]) {
            inDeg[v]--; //delete edge
            if (inDeg[v] == 0) { //if no indeg, put on q
                q.emplace_back(v);
            }
        }
    }

    //cycle detection, all edges should have been deleted
    for (int deg : inDeg) {
        if (deg > 0) {
            return "";
        }
    }

    for (int i = 0; i < seen.size(); ++i) {
        if (seen[i] && sol.find(dec(i)) == string::npos) { //if seen and not in solution set
            sol.push_back(dec(i));
        }
    }

    return sol;
}

int main() {
    assert(alienOrder({"wrt",
                       "wrf",
                       "er",
                       "ett",
                       "rftt"}) == "wertf");
    assert(alienOrder({"z", "x"}) == "zx");
    assert(alienOrder({"z", "z"}) == "z");
    assert(alienOrder({"zy", "zx"}) == "yxz");
    assert(alienOrder({"ab", "adc"}) == "bdac");
    assert(alienOrder({"abc", "ab"}) == "");
}

