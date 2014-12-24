/*
ID: dcdexte1
LANG: C++
PROG: milk
*/

#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

int main() {
    FILE* in = fopen("milk.in", "r");
    FILE* out = fopen("milk.out", "w");

    int demand, nFarmers;
    unsigned long long totalCost = 0;

    fscanf(in, "%d %d", &demand, &nFarmers);
    vector<pair<int, int> > suppliers;
    suppliers.reserve(nFarmers);

    for (int i = 0; i < nFarmers; ++i) {
        int cost, supply;
        fscanf(in, "%d %d", &cost, &supply);
        suppliers.push_back(pair<int,int> (cost, supply));
    }
    fclose(in);

    // Sorts by cost, least first
    sort(suppliers.begin(), suppliers.end());

    for (int i = 0; i < suppliers.size(); ++i) {
        if (demand <= 0) {
            break;
        }

        if (demand - suppliers[i].second > 0) {
            demand -= suppliers[i].second;
            totalCost += (suppliers[i].first * suppliers[i].second);
        }
        else {
            totalCost += (demand * suppliers[i].first);
            demand = 0;
        }
    }

    fprintf(out, "%llu\n", totalCost);
    fclose(out);
}
