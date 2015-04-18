/*
PROG: numtri
LANG: C++
ID: dcdexte1
*/

#include <cstdio>
#include <cstdlib>

#define R_MAX  1000

using namespace std;

int triangle[R_MAX][R_MAX];

int main() {
    FILE* in = fopen("numtri.in", "r");
    FILE* out = fopen("numtri.out", "w");

    int n;
    fscanf(in, "%d", &n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i + 1; ++j)
            fscanf(in, "%d", &triangle[i][j]);
    fclose(in);

    for (int i = n - 2; i >= 0; --i)
        for (int j = 0; j < i + 1; ++j)
            triangle[i][j] += triangle[i+1][j] > triangle[i+1][j+1] ? triangle[i+1][j] : triangle[i+1][j+1];

    fprintf(out, "%d\n", triangle[0][0]);
    fclose(out);

    return 0;
}
