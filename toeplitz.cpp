#include <iostream>
#include <bits/stdc++.h>


using namespace std;

bool isToep(const vector<vector<int>> &a, int r, int c, int h, int w) {
    int toCheck = a[r][c];
    r++;
    c++;
    while (r < h && c < w) {
        if (toCheck != a[r][c]) {
            return false;
        }
        r++;
        c++;
    }
    return true;
}

bool isToeplitzMatrix(const vector<vector<int>> &a) {
    int h = a.size();
    int w = a.front().size();

    for (int i = 0; i < h; ++i) {
        if (!isToep(a, i, 0, h, w)) return false;
    }

    for (int i = 0; i < w; ++i) {
        if (!isToep(a, 0, i, h, w)) return false;
    }

    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    assert(isToeplitzMatrix({{1, 2},
                             {2, 2}}) == false);
    assert(isToeplitzMatrix({{1, 2, 3, 4},
                             {5, 1, 2, 3},
                             {9, 5, 1, 2}}) == true);
    assert(isToeplitzMatrix({{36, 59, 71, 15, 26, 82, 87},
                             {56, 36, 59, 71, 15, 26, 82},
                             {15, 0,  36, 59, 71, 15, 26}}) == false);
    return 0;
}
