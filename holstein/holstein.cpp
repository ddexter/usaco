/*
PROG: holstein
LANG: C++
USER: dcdexte1
*/
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int best[26];
int currentBest = INT_MAX;
int tmpBest[26];
int req[26];
int feeds[16][26];
int m, n;

bool reqMet() {
    for (int i = 0; i < m; ++i) {
        if (req[i] > 0) {
            return false;
        }
    }
    return true;
}

void copyBest() {
    for (int i = 0; i < m; ++i) {
        best[i] = tmpBest[i];
    }
}

void addSubFeed(int feed, bool sub) {
    for (int i = 0; i < m; ++i) {
        if (sub) {
            req[i] -= feeds[feed][i];
        }
        else {
            req[i] += feeds[feed][i];
        }
    }
}

void rec(int feed, int depth) {
    // Prune
    if (depth >= currentBest) {
        return;
    }

    // Base case
    if (reqMet()) {
        copyBest();
        currentBest = depth; 
        return;
    }

    for(int i = feed + 1; i < n; ++i) {
        addSubFeed(i, true);
        tmpBest[depth] = i;
        rec(i, depth + 1);
        addSubFeed(i, false);
    }
}

int main() {
    FILE* in = fopen("holstein.in", "r");
    FILE* out = fopen("holstein.out", "w");

    int tmp;
    fscanf(in, "%d", &m);
    for (int i = 0; i < m; ++i) {
        fscanf(in, "%d", &req[i]);
    }

    fscanf(in, "%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fscanf(in, "%d", &feeds[i][j]);
        }
    }
    fclose(in);

    rec(-1, 0);

    fprintf(out, "%d", currentBest);
    for (int i = 0; i < currentBest; ++i) {
        fprintf(out, " %d", best[i] + 1);
    }
    fprintf(out, "\n");
    fclose(out);

    return 0;
}
