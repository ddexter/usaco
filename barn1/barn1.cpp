/*
ID: dcdexte1
LANG: C++
PROG: barn1
*/

#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    FILE* in = fopen("barn1.in", "r");
    FILE* out = fopen("barn1.out", "w");

    int m, s, c;
    fscanf(in, "%d %d %d", &m, &s, &c);
    int nBlockedStalls = c; // Start off blocking each stall individually
    int nBoards = c;

    vector<int> occupiedStalls;
    occupiedStalls.reserve(c);
    for (int i = 0; i < c; ++i) {
        int tmp;
        fscanf(in, "%d", &tmp);
        occupiedStalls.push_back(tmp);
        printf("%d\n", occupiedStalls[i]);
    }
    fclose(in);

    sort(occupiedStalls.begin(), occupiedStalls.end());

    vector<int> stallGaps;
    stallGaps.reserve(c - 1);
    for (int i = 0; i < c - 1; ++i) {
        stallGaps.push_back(occupiedStalls[i + 1] - occupiedStalls[i] - 1);
    }
    sort(stallGaps.begin(), stallGaps.end());

    for (int i = 0; i < stallGaps.size() && m < nBoards; ++i) {
        --nBoards;
        nBlockedStalls += stallGaps[i];
    }

    fprintf(out, "%d\n", nBlockedStalls);

    fclose(out);

    return 0;
}
