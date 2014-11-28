/*
ID: dcdexte1
LANG: C++
PROG: transformations
*/
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

const int NMAX = 10;

vector<vector<char> > rotation(vector<vector<char> >  pattern) {
    int n = pattern.size();
    vector<vector<char> > tmp(n, vector<char>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int r = (i + (n - 1)) % (n - 1);
            tmp[j][n - 1 - i] = pattern[i][j];
        }
    
    return tmp;
}

bool equal(vector<vector<char> > a, vector<vector<char> > b) {
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a.size(); ++j)
            if (a[i][j] != b[i][j])
                return false;

    return true;
}

int main() {
    FILE* in = fopen("transformations.in", "r");
    FILE* out = fopen("trasnformations.out", "w");
    int n;

    fscanf(in, "%d", &n);

    vector<vector<char> > test(n, vector<char>(n));
    vector<vector<char> > master(n, vector<char>(n));

    char tmp[NMAX];
    for (int i = 0; i < n; ++i) {
        fscanf(in, "%s\n", tmp);
        for (int j = 0; j < n; ++j)
            test[i][j] = tmp[j];
    }
    for (int i = 0; i < n; ++i) {
        fscanf(in, "%s\n", tmp);
        for (int j = 0; j < n; ++j)
            master[i][j] = tmp[j];
    }
    fclose(in);

    test = rotation(master);
    fclose(out);
}
