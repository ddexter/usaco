/*
ID: dcdexte1
LANG: C++
PROG: palsquare
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
        char c = r < 10 ? '0' + r : 'A' + (r - 10);
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
    FILE* in = fopen("palsquare.in", "r");
    FILE* out = fopen("palsquare.out", "w");

    int base;

    fscanf(in, "%d", &base);
    fclose(in);

    for (int i = 1; i < 300; ++i) {
        int square = i * i;
        char bufferSquare[18];
        decToBase(square, base, bufferSquare);

        if (isPalindrome(bufferSquare)) {
            char buffer[18];
            decToBase(i, base, buffer);
            fprintf(out, "%s %s\n", buffer, bufferSquare);
        }
    }

    fclose(out);

    return 0;
}
