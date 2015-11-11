/*
ID: dcdexte1
LANG: C++
PROG: sort3
*/

#include<algorithm>
#include<cstdio>
#include<cstdlib>

using namespace std;

int counts[4]; // Counts of each number
int pos[4][2]; // Start/End position of each number
int zoneCounts[4][4]; // Count of each number per "zone" {1,2,3} [Medal][Zone]
int nums[1001];

int findZone(int x) {
    for (int i = 1; i < 4; ++i) {
        if (pos[i][0] <= x && pos[i][1] >= x) {
            return i;
        }
    }

    return -1; // Should never reach here
}

int main() {
    FILE *in = fopen("sort3.in", "r");
    FILE *out = fopen("sort3.out", "w");

    pos[0][0] = -1;
    pos[0][1] = -1;

    int n, tmp;
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; ++i) {
        fscanf(in, "%d", &tmp);
        nums[i] = tmp;
        ++counts[tmp];
    }

    for (int i = 1; i < 4; ++i) {
        pos[i][0] = pos[i-1][1] + 1;
        pos[i][1] = pos[i][0] + counts[i] - 1;
    }

    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        int zone = findZone(i);
        ++zoneCounts[x][zone];
    }

    int total = 0;

    // Swap 1:2
    tmp = min(zoneCounts[1][2], zoneCounts[2][1]);
    zoneCounts[1][2] -= tmp;
    zoneCounts[2][1] -= tmp;
    total += tmp;

    // Swap 1:3
    tmp = min(zoneCounts[1][3], zoneCounts[3][1]);
    zoneCounts[1][3] -= tmp;
    zoneCounts[3][1] -= tmp;
    total += tmp;

    // Swap 2:3
    tmp = min(zoneCounts[2][3], zoneCounts[3][2]);
    zoneCounts[2][3] -= tmp;
    zoneCounts[3][2] -= tmp;
    total += tmp;

    // All remaining require 2 moves to put 3 cycles into place
    total += zoneCounts[1][2] * 2;
    total += zoneCounts[1][3] * 2;

    fprintf(out, "%d\n", total);
    fclose(out);

    return 0;
}

