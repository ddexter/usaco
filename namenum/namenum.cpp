/*
ID: dcdexte1
LANG: C++
PROG: namenum
*/

#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

unsigned long long t9ToNum(char* name) {
    unsigned long long ret = 0;
    for (int i = 0; name[i] != '\0'; ++i) {
        // Account for lack of 'Q' on problem's T9 keyboard
        if (name[i] - 'Q' > 0) {
            ret = (ret * 10) + (((name[i] - 'A' - 1) / 3) + 2);
        }
        else {
            ret = (ret * 10) + (((name[i] - 'A') / 3) + 2);
        }
    }

    return ret;
}

int main() {
    FILE* dict = fopen("dict.txt", "r");
    FILE* in = fopen("namenum.in", "r");
    FILE* out = fopen("namenum.out", "w");

    bool found = false;
    unsigned long long cow;
    char buffer[15];

    fscanf(in, "%llu", &cow);
    fclose(in);

    // # digits in cow id
    int nCowDigits = 0;
    for (unsigned long long i = cow; i != 0; i /= 10, ++nCowDigits);

    while(!feof(dict)) {
        fscanf(dict, "%s", buffer);
        if (strlen(buffer) == nCowDigits && t9ToNum(buffer) == cow) {
            found = true;
            fprintf(out, "%s\n", buffer);
        }
    }

    if(!found) {
        fprintf(out, "NONE\n");
    }

    fclose(dict);
    fclose(out);

    return 0;
}
