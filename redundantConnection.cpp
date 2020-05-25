#include <bits/stdc++.h>

using namespace std;

struct UF {
    vector<int> parent;
    vector<int> rank;

    explicit UF(int n) : parent(n), rank(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
};

int find(UF &uf, int x) {
    int prev = x;
    while (uf.parent[x] != x) {
        x = uf.parent[x];
        uf.parent[prev] = x;
    }
    return x;
}

void union2(UF &uf, int x, int y) {
    int xParent = find(uf, x);
    int yParent = find(uf, y);

    if (xParent == yParent) {
        return;
    }

    //attach to larger tree
    if (uf.rank[xParent] < uf.rank[yParent]) {
        uf.parent[xParent] = yParent;
    } else if (uf.rank[xParent] > uf.rank[yParent]) {
        uf.parent[yParent] = xParent;
    } else { //break tie arbitrarily, x is child of y
        uf.parent[xParent] = yParent;
        uf.rank[yParent]++; //need to increment rank since they are no longer the same height
    }
}

//https://leetcode.com/problems/redundant-connection/
vector<int> findRedundantConnection(const vector<vector<int>> &edges) {
    int n = edges.size();
    UF uf(n);
    for (const vector<int> &edge : edges) {
        int u = edge[0]-1, v = edge[1]-1;
        if (find(uf, u) == find(uf, v)) {
            return edge;
        }
        union2(uf, u, v);
    }

    return {};
}


int main() {
    vector<int> v{2,3};
    assert(findRedundantConnection({{1, 2},
                             {1, 3},
                             {2, 3}}) == v);
}

