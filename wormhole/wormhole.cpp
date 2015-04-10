/*
ID: dcdexte1
LANG: C++
PROG: wormhole
*/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

#define N_MAX 12

int n;
int x[N_MAX], y[N_MAX], pairings[N_MAX], adjacent[N_MAX];

bool isCycle() {
    for (int i = 0; i < n; ++i) {
        int idx = i;
        for (int j = 0; j < n; ++j) {
            idx = adjacent[pairings[idx]];
            if (idx < 0) {
                break;
            }
        }

        if (idx >= 0) {
            return true;
        }
    }

    return false;
}

int countCycles() {
    int ret = 0;

    int i = 0;
    for (; i < n; ++i) {
        if (pairings[i] < 0) {
            break;
        }
    }

    if (i == n) {
        return isCycle() ? 1 : 0;
    }

    for (int j = i + 1; j < n; ++j) {
        if (pairings[j] < 0) {
            pairings[i] = j;
            pairings[j] = i;

            ret += countCycles();

            pairings[i] = -1;
            pairings[j] = -1;
        }
    }

    return ret;
}

int main() {
    FILE *in = fopen("wormhole.in", "r");
    FILE *out = fopen("wormhole.out", "w");

    fscanf(in, "%d", &n);

    for (int i = 0; i < n; ++i) {
        fscanf(in, "%d %d", &x[i], &y[i]);
    }
    fclose(in);

    for (int i = 0; i < n; ++i) {
        pairings[i] = -1;
        adjacent[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (y[i] == y[j] && x[j] > x[i]) {
                if (adjacent[i] == -1 || x[j] < x[adjacent[i]]) {
                    adjacent[i] = j;
                }
            }
        }
    }

    int ret = countCycles();

    fprintf(out, "%d\n", ret);
    fclose(out);
}

