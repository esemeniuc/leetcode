#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/course-schedule/

enum class color_t {
    unvisited,
    temp,
    perm,
};

//returns true if exists a cycle
bool dfs(const vector<vector<int>> &adj, vector<color_t> &visited, int u, vector<int> &sol) {
    if (visited[u] == color_t::perm) {
        return false;
    } else if (visited[u] == color_t::temp) {
        return true;
    }

    visited[u] = color_t::temp;
    for (int v : adj[u]) {
        if (dfs(adj, visited, v, sol)) {
            return true;
        }
    }

    visited[u] = color_t::perm;
    sol.push_back(u);
    return false;
}

bool canFinish(int numCourses, const vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<color_t> visited(numCourses);

    for (const vector<int> &e : prerequisites) {
        int u = e[1], v = e[0];
        adj[u].emplace_back(v);
    }

    vector<int> sol;
    sol.reserve(numCourses);

    for (int u = 0; u < adj.size(); ++u) {
        if (visited[u] == color_t::unvisited) {
            if (dfs(adj, visited, u, sol)) {
                return false; //cycle means we cant finish courses
            }
        }
    }

    //    reverse(sol.begin(), sol.end());
    return true;
}

int main() {
    assert(canFinish(2, {{1, 0}}));
    assert(!canFinish(4, {{1, 0},
                          {2, 1},
                          {3, 2},
                          {1, 3}}));
    assert(canFinish(2, {{1, 0},
                         {0, 1}}) == false);
    assert(canFinish(1, {}) == true);
//    return 0;
}

