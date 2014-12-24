/*
ID: dcdexte1
LANG: C++
PROG: dualpal
*/

#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void decToBase(int n, int base, char* buffer)
{
    int i;
    for(i = 0; n > 0; ++i) {
        int r = n % base;
        char c = '0' + r;
        buffer[i] = c;
        n /= base;
    }
    buffer[i] = '\0';

    reverse(buffer, buffer + strlen(buffer));
}

bool isPalindrome(char* buffer) {
    int len = strlen(buffer);
    for (int i = 0; i < len / 2; ++i) {
        if (buffer[i] != buffer[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    FILE* in = fopen("dualpal.in", "r");
    FILE* out = fopen("dualpal.out", "w");

    int n, s;

    fscanf(in, "%d %d", &n, &s);
    fclose(in);

    for (int i = s + 1; n > 0; ++i) {
        int nPalindromicBases = 0;
        for (int j = 2; j <= 10; ++j) {
            char buffer[33];
            decToBase(i, j, buffer);
            if (isPalindrome(buffer)) {
                ++nPalindromicBases;
                if (nPalindromicBases == 2) {
                    break;
                }
            }
        }

        if (nPalindromicBases == 2) {
            fprintf(out, "%d\n", i);
            --n;
        }
    }

    fclose(out);

    return 0;
}
