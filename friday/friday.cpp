/*
ID: dcdexte1
LANG: C++
PROG: friday
*/

#include<cstdio>
#include<cstdlib>
#include<string>

using namespace std;

bool is_leap_year(int n) {
    int year = 1900 + n;
    return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
}

int offset[] = {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};
int leap_year_offset[] = {5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

string cal[] = {"Sat", "Sun", "Mon", "Tues", "Wed", "Thurs", "Fri"};

int main() {
    FILE *in = fopen("friday.in", "r");
    FILE* out = fopen("friday.out", "w");
    int dow = 2;

    int n;
    fscanf(in, "%d", &n);
    fclose(in);

    int thirteenths[] = {0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < n; ++i) {
        bool leap_year = is_leap_year(i);
        for (int j = 0; j < 12; ++j) {
            int thirteenth_of_month = (leap_year ? dow + leap_year_offset[j] : dow + offset[j]) % 7;
            thirteenths[thirteenth_of_month]++;
        }
        dow = (leap_year ? dow + 2 : dow + 1) % 7;
    }

    for (int i = 0; i < 7; ++i) {
        fprintf(out, "%d", thirteenths[i]);
        if (i != 6) {
            fprintf(out, " ");
        }
    }
    fprintf(out, "\n");
    fclose(out);

    return 0;
}
