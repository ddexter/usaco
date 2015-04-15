/*
ID: dcdexte1
LANG: C++
PROG: skidesign
*/

#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define N_MAX 1000
#define N_MAX_HEIGHT 100
#define N_TAX 17

int n;
int ski[N_MAX];

int getMax() {
    int best = 0;
    for (int i = 0; i < n; ++i)
        if (ski[i] > best)
            best = ski[i];

    return best;
}

int main() {
    FILE* in = fopen("skidesign.in", "r");
    FILE* out = fopen("skidesign.out", "w");

    fscanf(in, "%d", &n);
    for (int i = 0; i < n; ++i)
        fscanf(in, "%d", &ski[i]);
    fclose(in);

    int max = getMax();
    int ret = -1;
    for (int i = 0; i <= max; ++i) {
        int cost = 0;
        for (int j = 0; j < n; ++j) {
            int adjustment = 0;
            if (ski[j] > i + N_TAX) 
                adjustment = ski[j] - (i + N_TAX);
            else if (ski[j] < i) {
                adjustment = i - ski[j];
            }

            cost += adjustment * adjustment;
        }
        
        if (ret < 0 || cost < ret) {
            ret = cost;
        }
    }

    fprintf(out, "%d\n", ret);
    fclose(out);

    return 0;
}
