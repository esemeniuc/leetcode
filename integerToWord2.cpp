#include <bits/stdc++.h>

using namespace std;

vector<string> to19{"Zero",
                    "One",
                    "Two",
                    "Three",
                    "Four",
                    "Five",
                    "Six",
                    "Seven",
                    "Eight",
                    "Nine",
                    "Ten",
                    "Eleven",
                    "Twelve",
                    "Thirteen",
                    "Fourteen",
                    "Fifteen",
                    "Sixteen",
                    "Seventeen",
                    "Eighteen",
                    "Nineteen",
};

vector<string> tens{"Zero",
                    "Ten",
                    "Twenty",
                    "Thirty",
                    "Forty",
                    "Fifty",
                    "Sixty",
                    "Seventy",
                    "Eighty",
                    "Ninety",
};
vector<pair<int64_t, string>> divisors{{100,        "Hundred"},
                                   {1000,       "Thousand"},
                                   {1000000,    "Million"},
                                   {1000000000, "Billion"},
                                   {INT64_MAX,    "ERROR"},
};

void numberToWords(vector<string *> &sol, int x) {
    if (x == 0) {
        return;
    }
    if (x < 20) {
        sol.push_back(&to19[x]);
        return;
    } else if (x < 100) {
        sol.push_back(&tens[x / 10]);
        numberToWords(sol, x % 10);
        return;
    } else if (x < 1000) {
        sol.push_back(&to19[x / 100]);
        sol.push_back(&divisors[0].second);
        numberToWords(sol, x % 100);
        return;
    }

    for (int i = 1; i + 1 < divisors.size(); i++) { //skip 100, skip trillion
        if (x < divisors[i + 1].first) {
            numberToWords(sol, x / divisors[i].first);//get coeff by dividing
            sol.push_back(&divisors[i].second); //unit
            numberToWords(sol, x % divisors[i].first);//remainder
            return;
        }
    }
}

//https://leetcode.com/problems/container-with-most-water/
string numberToWords(int num) {
    if (num == 0) {
        return "Zero";
    }
    vector<string *> sol;
    sol.reserve(12);
    numberToWords(sol, num);

    string final;
    final.reserve(128);
    for (int i = 0; i + 1 < sol.size(); i++) {
        final.append(*sol[i]).append(" ");
    }
    final.append(*sol.back());
    return final;
}

int main() {
    assert(numberToWords(2147483647) == "Twenty");
    assert(numberToWords(20) == "Twenty");
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