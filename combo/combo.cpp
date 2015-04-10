/*
ID: dcdexte1
LANG: C++
PROG: combo
*/

#include <cstdlib>
#include <cstdio>
#include <set>

using namespace std;

int countUnique(int *combo, set<int> &counted, int n) {
    int ret = 0;

    for (int i = -2; i < 3; ++i) {
        for (int j = -2; j < 3; ++j) {
            for (int k = -2; k < 3; ++k) {
                int translated[3];
                translated[0] = combo[0] + i < 0 ? (n + (combo[0] + i)) % n : (combo[0] + i) % n;
                translated[1] = combo[1] + j < 0 ? (n + (combo[1] + j)) % n : (combo[1] + j) % n;
                translated[2] = combo[2] + k < 0 ? (n + (combo[2] + k)) % n : (combo[2] + k) % n;
                int encrypt = 1000000 * translated[0] + 1000 * translated[1] + translated[2];

                if (counted.find(encrypt) == counted.end()) {
                    ++ret;
                    counted.insert(encrypt);
                }
            }
        }
    }

    return ret;
}

int main() {
    FILE* in = fopen("combo.in", "r");
    FILE* out = fopen("combo.out", "w");

    int n;
    int ret = 0;
    int user[3];
    int master[3];
    set<int> counted;

    fscanf(in, "%d", &n);
    fscanf(in, "%d %d %d", &user[0], &user[1], &user[2]);
    fscanf(in, "%d %d %d", &master[0], &master[1], &master[2]);
    fclose(in);

    // Make 0 based for easier circular lock
    for (int i = 0; i < 3; ++i) {
        --user[i];
        --master[i];
    }

    ret += countUnique(user, counted, n);
    ret += countUnique(master, counted, n);

    fprintf(out, "%d\n", ret);
    fclose(out);

    return 0;
}
