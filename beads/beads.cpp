/*
ID: dcdexte1
LANG: C++
PROG: beads
*/
#include <cstdlib>
#include <cstdio>

using namespace std;

/**
 * start: position to start count at
 * n: size of necklace
 * beads: necklace
 * direction: forward -> 1, backward -> -1
 */
int count(int start, int n, char beads[], int direction) {
    int ret = 0;
    bool b = false;
    bool r = false;
    for (int i = 0; i < n; ++i) {
        int p = (start + direction * i) % n;
        if (p < 0) {
            p = n + p;
        }

        if (beads[p] == 'r') {
            r = true;
        }
        if (beads[p] == 'b') {
            b = true;
        }
        if (r && b) {
            break;
        }
        
        ++ret;
    }

    return ret;
}

int main() {
    FILE *in = fopen("beads.in", "r");
    FILE *out = fopen("beads.out", "w");

    int n;
    char beads[360];
    fscanf(in, "%d\n%s", &n, beads);
    fclose(in);

    int max = 0;
    for (int i = 0; i < n; ++i) {
        // forward
        int start = i;
        int val = count(start, n, beads, 1);

        // backward
        start = i - 1 < 0 ? n - 1 : i - 1;
        val += count(start, n, beads, -1);

        if (val >= max) {
            max = val > n ? n : val;
        }
    }

    fprintf(out, "%d\n", max);
    fclose(out);

    return 0;
}
