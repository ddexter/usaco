/*
ID: dcdexte1
PROG: test
LANG: C++
*/

#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    FILE *fin = fopen("test.in", "r");
    FILE *fout = fopen("test.out", "w");

    int a, b;
    fscanf(fin, "%d %d", &a, &b);
    fclose(fin);

    fprintf(fout, "%d\n", a + b);
    fclose(fout);

    return 0;
}
