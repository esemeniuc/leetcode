#include <bits/stdc++.h>

using namespace std;

unordered_map<int, string> numberLabels{
        {1,          "One"},
        {2,          "Two"},
        {3,          "Three"},
        {4,          "Four"},
        {5,          "Five"},
        {6,          "Six"},
        {7,          "Seven"},
        {8,          "Eight"},
        {9,          "Nine"},
        {10,         "Ten"},
        {11,         "Eleven"},
        {12,         "Twelve"},
        {13,         "Thirteen"},
        {14,         "Fourteen"},
        {15,         "Fifteen"},
        {16,         "Sixteen"},
        {17,         "Seventeen"},
        {18,         "Eighteen"},
        {19,         "Nineteen"},
        {20,         "Twenty"},
        {30,         "Thirty"},
        {40,         "Forty"},
        {50,         "Fifty"},
        {60,         "Sixty"},
        {70,         "Seventy"},
        {80,         "Eighty"},
        {90,         "Ninety"},
        {100,        "Hundred"},
        {1000,       "Thousand"},
        {1000000,    "Million"},
        {1000000000, "Billion"},
};

vector<int> divisors{1,
                     2,
                     3,
                     4,
                     5,
                     6,
                     7,
                     8,
                     9,
                     10,
                     11,
                     12,
                     13,
                     14,
                     15,
                     16,
                     17,
                     18,
                     19,
                     20,
                     30,
                     40,
                     50,
                     60,
                     70,
                     80,
                     90,
                     100,
                     1000,
                     1000000,
                     1000000000};

unordered_set<int> units = {100,
                            1000,
                            1000000,
                            1000000000};
struct split_t {
    int coeff, divisor, rem;
};

//x > 0
split_t split(int x) {
    int coeff, divisor, rem;
    for (int i = 0; i < divisors.size() && x / divisors[i] > 0; i++) {
        //things under 100 dont need to be labelled like "One Hundred". 20 =! "One Twenty"
//        coeff = x / divisors[i];
        coeff = (divisors[i] >= 100) ? x / divisors[i] : 0;
        divisor = divisors[i];
        rem = x % divisors[i];
    }
    return {coeff, divisor, rem};
}

void numberToWords(vector<string*> &sol, int x) {
    if (x == 0) { return; }

    split_t components = split(x);

    //always put on leading coeff and unit
    if (units.count(x) > 0) {
        sol.push_back(&numberLabels[components.coeff]);
        sol.push_back(&numberLabels[components.divisor]);
        return;
    }
    //check this after so we have a chance to get the coeff
    if (numberLabels.count(x) > 0) {
        sol.push_back(&numberLabels[x]);
        return;
    }

    words(sol, components.coeff);
    if (units.count(components.divisor) == 0) { //fixes the always show onehundred bug
        words(sol, components.divisor);
    } else {
        sol.push_back(&numberLabels[components.divisor]);
    }
    words(sol, components.rem);
}

//https://leetcode.com/problems/container-with-most-water/
string numberToWords(int num) {
    if (num == 0) {
        return "Zero";
    }
    vector<string*> sol;
    sol.reserve(12);
    words(sol, num);

    string final;
    final.reserve(128);
    for (int i = 0; i + 1 < sol.size(); i++) {
        final.append(*sol[i]).append(" ");
    }
    final.append(*sol.back());
    return final;
}

int main() {
    assert(numberToWords(123) == "One Hundred Twenty Three");
    assert(numberToWords(51) == "Fifty One");
    assert(numberToWords(1100) == "One Thousand One Hundred");
    assert(numberToWords(1000) == "One Thousand");
    assert(numberToWords(234) == "Two Hundred Thirty Four");
    assert(numberToWords(51234) == "Fifty One Thousand Two Hundred Thirty Four");
    assert(numberToWords(12345) == "Twelve Thousand Three Hundred Forty Five");
    assert(numberToWords(1234567891) ==
           "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One");
}