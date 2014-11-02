/*
ID: dcdexte1
LANG: C++
PROG: gift1
*/
#include <cstdlib>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> bank;
    FILE *in = fopen("gift1.in", "r");
    FILE *out = fopen("gift1.out", "w");

    int num_names;
    fscanf(in, "%d", &num_names);

    char names[11][15];
    for (int i = 0; i < num_names; ++i) {
        fscanf(in, "%s", names[i]);
        bank[string(names[i])] = 0;
    }

    for (int i = 0; i < num_names; ++i) {
        char name[15];
        fscanf(in, "%s", name);

        int amount, num_friends;
        fscanf(in, "%d %d", &amount, &num_friends);

        if (amount == 0 || num_friends == 0) {
            continue;
        }

        bank[string(name)] -= amount - (amount % num_friends);
        int gift = amount / num_friends;
        for (int j = 0; j < num_friends; ++j) {
            char the_friend[15];
            fscanf(in, "%s", the_friend);

            bank[string(the_friend)] += gift;
        }
    }
    fclose(in);

    for (int i = 0; i < num_names; ++i) {
        fprintf(out, "%s %d\n", names[i], bank[string(names[i])]);
    }
    fclose(out);

    return 0;
}
