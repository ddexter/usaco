/*
ID: dcdexte1
PROG: pprime
LANG: C++
*/

#include <cstdio>
#include <cstdlib>

#define MAX_WITNESS 100000

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

int makePalindrome(int half, int middle) {
    int offset = 1;
    int tmp = half;
    int reverse = 0;
    while (tmp > 0) {
        int digit = tmp % 10;
        tmp /= 10;
        reverse = reverse * 10 + digit;
        offset *= 10;
    }

    return half * offset * 10 + middle * offset + reverse;
}

int main() {
    FILE *in = fopen("pprime.in", "r");
    FILE *out = fopen("pprime.out", "w");

    int a, b;
    fscanf(in, "%d%d", &a, &b);
    fclose(in);

    for (int i = 3; i <= 11; ++i)
        if (i >= a && i <= b && isPrime(i))
            fprintf(out, "%d\n", i);

    bool end = false;
    for (int i = 1; i < 1000; ++i) {
        if (end) {
            break;
        }

        for (int j = 0; j < 10; ++j) {
            int p = makePalindrome(i, j);
            if (p > b) {
                end = true;
                break;
            }

            if (p >= a && p <= b && isPrime(p))
                fprintf(out, "%d\n", p);
        }
    }
    fclose(out);

    return 0;
}
