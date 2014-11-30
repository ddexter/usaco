/*
ID: dcdexte1
LANG: C++
PROG: transform
*/
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

const int NMAX = 10;

vector<vector<char> > rotate(vector<vector<char> >  pattern) {
    int n = pattern.size();
    vector<vector<char> > tmp(n, vector<char>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int r = (i + (n - 1)) % (n - 1);
            tmp[j][n - 1 - i] = pattern[i][j];
        }
    
    return tmp;
}

vector<vector<char> > reflect_vertically(vector<vector<char> > pattern) {
    int n = pattern.size();
    int k = n / 2;
    vector<vector<char> > tmp(n, vector<char>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j) {
            char store = tmp[i][j];
            tmp[i][j] = tmp[i][n-j];
            tmp[i][n-j] = store;
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
    FILE* in = fopen("transform.in", "r");
    FILE* out = fopen("transform.out", "w");
    int ret = 7; // Assume no match
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

    // Test and master equal by default
    if (equal(test, master)) {
        ret = 6;
    }

    // Test for equality during inital rotations
    for (int i = 1; i < 4; ++i) {
        test = rotate(test);
        if (equal(test, master)) {
            ret = i;
            break;
        }
    }

    if (ret > 5) {
        // Test for equality with reflections
        test = reflect_vertically(rotate(test));
        if (equal(test, master)) {
            ret = 5;
        }
        else {
            for (int i = 0; i < 3; ++i) {
                test = rotate(test);

                if (equal(test, master)) {
                    ret = 6;
                    break;
                }
            }
        }
    }

    fprintf(out, "%d\n", ret);
    fclose(out);
}
