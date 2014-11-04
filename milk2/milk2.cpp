/*
ID: dcdexte1
LANG: C++
PROG: milk2
*/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

int main() {
    FILE *in = fopen("milk2.in", "r");
    FILE *out = fopen("milk2.out", "w");

    int n;
    fscanf(in, "%d", &n);
    vector< pair<int,int> > seqs;
    seqs.reserve(n);
    for (int i = 0; i < n; ++i) {
        int s, e;
        fscanf(in, "%d %d", &s, &e);
        seqs.push_back(make_pair(s, e));
    }
    fclose(in);

    sort(seqs.begin(), seqs.end());

    // Combine milking sequences
    vector< pair<int,int> > coalesced;
    coalesced.reserve(n);
    int a = 0;
    int b = 0;
    bool first_found = true;
    for (int i = 0; i < seqs.size(); ++i) {
        if (seqs[i].first <= b) {
            b = seqs[i].second > b ? seqs[i].second : b;
        }
        else {
            if (first_found) { 
                first_found = false;
            }
            else {
                coalesced.push_back(make_pair(a, b));
            }
            a = seqs[i].first;
            b = seqs[i].second;
        }
    }
    coalesced.push_back(make_pair(a, b));

    // Find longest milking and non-milking time periods
    int max_off = 0;
    int max_on = 0;
    for (int i = 0; i < coalesced.size(); ++i) {
        if (coalesced[i].second - coalesced[i].first > max_on) {
            max_on = coalesced[i].second - coalesced[i].first;
        }
        if (i != 0 && coalesced[i].first - coalesced[i-1].second > max_off) {
            max_off = coalesced[i].first - coalesced[i-1].second;
        }
    }

    fprintf(out, "%d %d\n", max_on, max_off);
    fclose(out);

    return 0;
}
