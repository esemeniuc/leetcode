#include <bits/stdc++.h>

using namespace std;
//https://leetcode.com/problems/maximum-profit-in-job-scheduling/

struct job_t {
    int start;
    int finish;
    int value;

    bool operator<(const job_t rhs) const {
        return this->finish < rhs.finish;
    }
};

int rsearch(const vector<job_t> &a, int t) {
    int n = a.size();
    int l = 0;
    int r = n - 1;
    while (l < r) {
        int m = (l + r + 1) / 2; //+1 for ceiling
        if (t < a[m].finish) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    return r;
}

int jobScheduling(const vector<int> &s, const vector<int> &f, const vector<int> &v) {
    int n = v.size();
    vector<job_t> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = job_t{s[i], f[i], v[i]};
    }
    sort(a.begin(), a.end());

    //build p(j)
    vector<int> p(n,-1);
    for (int j = n - 1; j > 0; j--) {
        int idx = rsearch(a, a[j].start);
        while (idx >= 0 && a[idx].finish > a[j].start) {
            idx--;
        }
        p[j] = idx;
    }

    //loop for finding opt
    vector<int> opt(n);
    opt[0] = a[0].value;
    for (int i = 1; i < n; ++i) {
        int prevCompatOpt = p[i] < 0 ? 0 : opt[p[i]];
        opt[i] = max(opt[i - 1],
                     prevCompatOpt + a[i].value);
    }
    return opt[n-1];
}

int main() {
    assert(jobScheduling({1, 2, 3, 3}, {3, 4, 5, 6}, {50, 10, 40, 70}) == 120);
//    jobScheduling({1, 3, 0, 4, 3, 5, 6, 8}, {4, 5, 6, 7, 8, 9, 10, 11}, {5, 3, 1, 4, 6, 2, 5, 6});
    return 0;
}