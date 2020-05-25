#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/valid-sudoku/
bool isValidSudoku(const vector<vector<char>> &a) {
    vector<char> s(10);

    //do all rows
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int idx = a[i][j] - '0';
            if (a[i][j] == '.') {
                continue;
            }
            if (s[idx] > 0) {
                return false;
            }
            s[idx] = 1;
        }
        fill(s.begin(), s.end(), 0);
    }

    //do all cols
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 9; i++) {
            int idx = a[i][j] - '0';
            if (a[i][j] == '.') {
                continue;
            }
            if (s[idx] > 0) {
                return false;
            }
            s[idx] = 1;
        }
        fill(s.begin(), s.end(), 0);
    }

    const auto box = [&a, &s](int r, int c) {
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int idx = a[i][j] - '0';
                if (a[i][j] == '.') {
                    continue;
                }
                if (s[idx] > 0) {
                    return false;
                }
                s[idx] = 1;
            }
        }
        fill(s.begin(), s.end(), 0);
        return true;
    };
    //do all sub boxes
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            //do a box
            if (!box(i, j)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    assert(!isValidSudoku({{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
                           {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
                           {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
                           {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
                           {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
                           {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
                           {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
                           {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
                           {'.', '.', '4', '.', '.', '.', '.', '.', '.'}}));
}

