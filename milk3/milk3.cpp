/*
ID: dcdexte1
PROG: milk3
LANG: C++
*/

#include <algorithm>
#include <cstdio>
#include <cstdlib>

#define MAX_MILK 20

using namespace std;

bool sol[MAX_MILK + 1];
bool visited[MAX_MILK + 1][MAX_MILK + 1][MAX_MILK + 1];

int maxA, maxB, maxC;

void rec(int a, int b, int c) {
    if (visited[a][b][c])
        return;

    visited[a][b][c] = true;

    if (a == 0)
        sol[c] = true;

    rec(a - min(maxB - b, a), b + min(maxB - b, a), c); // a -> b
    rec(a - min(maxC - c, a), b, c + min(maxC - c, a)); // a -> c
    rec(a + min(maxA - a, b), b - min(maxA - a, b), c); // b -> a
    rec(a, b - min(maxC - c, b), c + min(maxC - c, b)); // b -> c
    rec(a + min(maxA - a, c), b, c - min(maxA - a, c)); // c -> a
    rec(a, b + min(maxB - b, c), c - min(maxB - b, c)); // c -> b
}

int main() {
    FILE* in = fopen("milk3.in", "r");
    FILE* out = fopen("milk3.out", "w");

    fscanf(in, "%d%d%d", &maxA, &maxB, &maxC);
    fclose(in);

    rec(0, 0, maxC);

    bool isFirst = true;
    for (int i = 0; i <= MAX_MILK; ++i) {
        if (sol[i])  {
            if (isFirst) {
                fprintf(out, "%d", i);
                isFirst = false;
            }
            else
                fprintf(out, " %d", i);
        }
    }
    fprintf(out, "\n");
    fclose(out);
    
    return 0;
}

