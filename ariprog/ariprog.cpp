/*
ID: dcdexte1
PROG: ariprog
LANG: C++
*/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define M_MAX 250
#define BI_MAX 125001

using namespace std;

int m, n, size;
bool valid[BI_MAX];
bool found = false;
vector<int> v;
FILE* out = fopen("ariprog.out", "w");

using namespace std;

void search() {
    int max = v[size - 1] / (n - 1) + 1;
    for (int i = 1; i < max; ++i)
        for (int j = 0; j < size; ++j)
            if (v[j] + (n - 1) * i <= v[size - 1]) {
                bool full = true;
                for (int k = n - 1; k > 0; --k)
                    if (!valid[v[j] + k * i]) {
                        full = false;
                        break;
                    }
                if (full) {
                    fprintf(out, "%d %d\n", v[j], i);
                    found = true;
                }
            }
}

int main() {
    FILE* in = fopen("ariprog.in", "r");

    fscanf(in, "%d%d", &n, &m);
    fclose(in);

    for (int i = 0; i <= m; ++i)
        for (int j = i; j <= m; ++j) {
            int bisquare = i * i + j * j;
            if (!valid[bisquare])
                v.push_back(bisquare);
            valid[bisquare] = true;
        }

    sort(v.begin(), v.end());
    size = v.size();

    search();

    if (!found)
        fprintf(out, "NONE\n");
    fclose(out);

    return 0;
}
