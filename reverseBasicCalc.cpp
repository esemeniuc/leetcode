#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/basic-calculator/

void findAndReplaceAll(string &data, const string &find, const string &replaceStr) {
    // Get the first occurrence
    size_t pos = data.find(find);

    // Repeat till end is reached
    while (pos != std::string::npos) {
        // Replace this occurrence of Sub String
        data.replace(pos, find.size(), replaceStr);
        // Get the next occurrence from the current position
        pos = data.find(find, pos + replaceStr.size());
    }
}

//returns index of start of number, right to left
//do not push empty stack
size_t getLimit(const string &stack) {
    if (stack.empty()) {
        throw runtime_error("STACK SHOULD BE NON EMPTY");
    }

    size_t i = stack.size() - 1;
    for (; isdigit(stack[i]); i--) {
        if (i == 0) {
            return 0;
        }
    }
    return i + 1;
}

int rstoi(string &&str) {
    reverse(str.begin(), str.end());
    return stoi(str);
}

string r_to_string(int num) {
    string str = to_string(num);
    reverse(str.begin(), str.end());
    return str;
}

//gets called on for right bracket
void computeEquation(string &stack) {
    for (int lim = getLimit(stack); lim > 0; lim = getLimit(stack)) {
        int num = rstoi(stack.substr(lim));
        lim--;
        if (stack[lim] == ')') {
            //delete bracket
            stack.resize(lim); //+1 because resize expects length, not index
            stack.append(r_to_string(num));
            return; //finished subexpression with left ending bracket
        } else if (stack[lim] == '+' || stack[lim] == '-') {
            char op = stack[lim];
            stack.resize(lim); //need to resize for next number, removes the operator
            lim = getLimit(stack);
            int rhsNum = rstoi(stack.substr(lim));
            stack.resize(lim);
            int sol = op == '+' ? num + rhsNum : num - rhsNum;
            stack.append(r_to_string(sol));
            if (lim == 0) {
                return;
            }
        } else {
            throw runtime_error("SHOULDN'T HAPPEN");
        }
    }
}

int calculate(const string &in) {
    string s = in;
    findAndReplaceAll(s, " ", "");
    string stack;
    stack.reserve(s.size());
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            computeEquation(stack);
        } else {
            stack.push_back(s[i]);
        }
    }
    computeEquation(stack);
    return rstoi(static_cast<string &&>(stack));
}

int main() {
//    assert(getLimit("5") == 0);
//    assert(getLimit("(5") == 1);
//    assert(getLimit("(55666") == 1);
//    assert(getLimit("5 + (55666") == 5);
//    assert(calculate("1+((5)+5)") == 11);
//    assert(calculate("1+((123)+5)") == 129);
//    assert(calculate("1+((5)+5+5)") == 16);
//    assert(calculate("1 + 1") == 2);
//    assert(calculate(" 2-1 + 2 ") == 3);
//    assert(calculate("(1+(4+5+2)-3)+(6+8)") == 23);
//    assert(calculate("1-11") == -10);
    assert(calculate("4-5+2") == 1);
}

