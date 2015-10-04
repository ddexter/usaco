/*
ID: dcdexte1
LANG: C++
PROG: frac1
*/

#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<utility>
#include<vector>
using namespace std;

int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

int main() {
    FILE *in = fopen("frac1.in", "r");
    FILE *out = fopen("frac1.out", "w");

    int n;
    fscanf(in, "%d", &n);
    fclose(in);

    vector<pair<double, string> > v;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int div = gcd(i, j);
            if (div == 1) {
                int num = j / div;
                int den = i / div;

                char buffer[10];
                sprintf(buffer, "%d/%d", j, i);

                v.push_back(make_pair((double)j / (double)i, string(buffer)));
            }
        }
    }

    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); ++i) {
        fprintf(out, "%s\n", v[i].second.c_str());
    }
    fclose(out);

    return 0;
}


