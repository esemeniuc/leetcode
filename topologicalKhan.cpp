#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/course-schedule/


bool canFinish(int numCourses, const vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses);

    for (const vector<int> &e : prerequisites) {
        int u = e[1], v = e[0];
        adj[u].emplace_back(v);
        inDegree[v]++;
    }

    //do topo
    vector<int> sol;
    sol.reserve(numCourses);
    vector<int> q;
    q.reserve(numCourses);

    for (int i = 0; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            q.push_back(i);
        }
    }
    while (!q.empty()) {
        int u = q.back();
        q.pop_back();
        sol.emplace_back(u);

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) { //if no incoming edges
                q.emplace_back(v);
            }
        }
    }

    //check for cycle
    return sol.size() == numCourses;
}

int main() {
//    assert(canFinish(2, {{1, 0}}));
    assert(!canFinish(4, {{1, 0},
                          {2, 1},
                          {3, 2},
                          {1, 3}}));
//    assert(canFinish(2, {{1, 0},
//                         {0, 1}}) == false);
//    assert(canFinish(1, {}) == true);
//    return 0;
}

