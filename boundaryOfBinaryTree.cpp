#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/maximum-profit-in-job-scheduling/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//assume we start on left subtree
void ltraverse(vector<int> &sol, const TreeNode *root) {
    if (root->left) {
        sol.push_back(root->val);
        ltraverse(sol, root->left);
    } else if (root->right) {
        sol.push_back(root->val);
        ltraverse(sol, root->right);
    }
}


//stores leaves only
void leaftraverse(vector<int> &sol, const TreeNode *root) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        sol.push_back(root->val);
        return;
    }

    leaftraverse(sol, root->left);
    leaftraverse(sol, root->right);
}


//assume we start on right subtree
void rtraverse(vector<int> &sol, const TreeNode *root) {
    if (root->right) {
        rtraverse(sol, root->right);
        sol.push_back(root->val);
    } else if (root->left) {
        rtraverse(sol, root->left);
        sol.push_back(root->val);
    }
}


vector<int> boundaryOfBinaryTree(const TreeNode *root) {
    if (!root) {
        return {};
    }

    vector<int> sol{root->val};
    if (root->left) {
        ltraverse(sol, root->left);
    }
    if (root->left || root->right) {
        leaftraverse(sol, root);
    }
    if (root->right) {
        rtraverse(sol, root->right);
    }
    return sol;
}

int main() {
    TreeNode *r = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), new TreeNode(4)));
    const vector<int> &sol{1, 3, 4, 2};
    assert(boundaryOfBinaryTree(r) == sol);

//    TreeNode *r = new TreeNode(1);
//    const vector<int> &sol{1};
//    assert(boundaryOfBinaryTree(r) == sol);
    return 0;
}

