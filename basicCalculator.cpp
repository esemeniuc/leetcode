#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/basic-calculator/

int calculate(const string &s) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    vector<pair<int, int>> stack;
    stack.reserve(s.size());
    int64_t solution = 0, currNum = 0;
    int currSign = 1; //positive by default
    for (char c : s) {
        if (isdigit(c)) {
            currNum = currNum * 10 + c - '0';
            continue; //no more work necessary
        }

        //end of number reached, add it to solution, reset number
        solution += currSign * currNum;
        currNum = 0;
        if (c == '(') {
            stack.emplace_back(currSign, solution); //back up the solution since we need to reuse
            solution = 0, currSign = 1;
        } else if (c == ')') {
            solution += currSign * currNum;
            int parenthesesSign = stack.back().first, lhsSolution = stack.back().second;
            stack.pop_back();
            solution = lhsSolution + parenthesesSign * solution;
        } else if (c == '+') {
            currSign = 1;
        } else if (c == '-') {
            currSign = -1;
        }
    }

    if (currNum) {
        solution += currSign * currNum; //handle case where we end without bracket
    }
    return solution;
}

int main() {
//    assert(getLimit("5") == 0);
//    assert(getLimit("(5") == 1);
//    assert(getLimit("(55666") == 1);
//    assert(getLimit("5 + (55666") == 5);
    assert(calculate("1+(5)") == 6);
    assert(calculate("1+((5)+5)") == 11);
    assert(calculate("1+((123)+5)") == 129);
    assert(calculate("1+((5)+5+5)") == 16);
    assert(calculate("1 + 1") == 2);
    assert(calculate(" 2-1 + 2 ") == 3);
    assert(calculate("(1+(4+5+2)-3)+(6+8)") == 23);
    assert(calculate("1-11") == -10);
    assert(calculate("4-5+2") == 1);
}

