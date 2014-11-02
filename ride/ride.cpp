/*
ID: dcdexte1
LANG: C++
PROG: ride
*/

#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

string STAY = "STAY";
string GO = "GO";

int main() {
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");

    char comet[7];
    char group[7];
    fscanf(fin, "%s", comet);
    fscanf(fin, "%s", group);
    fclose(fin);

    int comet_id = 1;
    for (int i = 0; comet[i] != '\0'; ++i) {
        comet_id *= comet[i] - 'A' + 1;
    }

    int group_id = 1;
    for (int i = 0; group[i] != '\0'; ++i) {
        group_id *= group[i] - 'A' + 1;
    }

    comet_id % 47 == group_id % 47 ?
        fprintf(fout, "GO\n") : fprintf(fout, "STAY\n");
    fclose(fout);

    return 0;
}
