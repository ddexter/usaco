/*
ID: dcdexte1
LANG: C++
PROG: crypt1
*/

#include <cstdlib>
#include <cstdio>
#include <set> // *Sigh* C++98... O(logn) lookups, ugh.
#include <vector>

using namespace std;

/*
 *      a b c
 *  x     d e
 *  _________
 *      * * *
 *  + * * *
 *  _________
 *   * * * *
 */

bool isCrypto(int num, set<int> nums) {
    for (; num != 0; num /= 10) {
        int r = num % 10;
        if (nums.find(r) == nums.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    FILE* in = fopen("crypt1.in", "r");
    FILE* out = fopen("crypt1.out", "w");

    set<int> nums;
    vector<int> abcs;

    int n;
    int ret = 0;

    fscanf(in, "%d", &n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        fscanf(in, "%d", &tmp);
        nums.insert(tmp);

    }
    fclose(in);

    for (set<int>::iterator i = nums.begin(); i != nums.end(); ++i) {
        for (set<int>::iterator j = nums.begin(); j != nums.end(); ++j) {
            for (set<int>::iterator k = nums.begin(); k != nums.end(); ++k) {
                abcs.push_back(100 * *i + 10 * *j + *k);
            }
        }
    }

    for (set<int>::iterator d = nums.begin(); d != nums.end(); ++d) {
        for (set<int>::iterator e = nums.begin(); e != nums.end(); ++e) {
            for (vector<int>::iterator abc = abcs.begin(); abc != abcs.end(); ++abc) {
                int partial1 = *d * *abc;
                int partial2 = *e * *abc;
                if (partial1 < 1000 &&
                    partial2 < 1000 &&
                    10 * partial1 + partial2 < 10000 &&
                    isCrypto(partial1, nums) &&
                    isCrypto(partial2, nums) &&
                    isCrypto(10 * partial1 + partial2, nums)) {
                    ++ret;
                }
            }
        }
    }

    fprintf(out, "%d\n", ret);
    fclose(out);

    return 0;
}

