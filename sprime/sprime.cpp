/*
ID: dcdexte1
LANG: C++
PROG: sprime
*/

#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
FILE* out = fopen("sprime.out", "w");

bool isPrime(int x) {
    if (x <= 1) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

void rec(int num, int it) {
    if (it > 0 && !isPrime(num))
        return;

    if (it == n && isPrime(num))
        fprintf(out, "%d\n", num);
    if (it == n)
        return;

    for (int i = 0; i < 10; ++i)
        rec(num * 10 + i, it + 1);
}

int main() {
    FILE* in = fopen("sprime.in", "r");

    fscanf(in, "%d", &n);
    fclose(in);

    rec(0, 0);

    fclose(out);

    return 0;
}
