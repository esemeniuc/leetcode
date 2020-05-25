#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right)
            : val(_val), left(_left), right(_right) {}
};


class Solution {
public:
    Node *connect(Node *root) {
        return r(root, root, true);
    }

    Node *r(Node *parent, Node *curr, bool isRight) {
        if (!curr) {
            return parent;
        }

        if (isRight) {
            if (parent->next == nullptr) { //far right of tree case
                curr->next = nullptr;
            } else {
                curr->next = parent->next->left;
            }
        } else { //left case
            curr->next = parent->right;
        }
        r(curr, curr->left, false);
        r(curr, curr->right, true);
        return curr;
    }

    static void print(Node *root) {
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        int depth = 0;
        while (!q.empty()) {
            auto s = q.front();
            q.pop();

            if(s.second == depth){
                printf("%d,", s.first->val);
                depth++;
            }

            if (s.first->next) {
                printf("%d,", s.first->next->val);
            } else {
                printf("#,");
            }

            if (s.first->left) {
                q.push({s.first->left, s.second + 1});
            }
            if (s.first->right) {
                q.push({s.first->right, s.second + 1});
            }
        }
    }
};

int main() {
    Node *tree = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3, new Node(6), new Node(7)));
    Node *sol = Solution().connect(tree);
    Solution::print(sol);
    return 0;
}

