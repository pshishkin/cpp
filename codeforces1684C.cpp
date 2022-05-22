#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;

const int MAXLEN = 5000;

enum Ans {
    already_good, perm_pair, bad
};

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; ++tt) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vi> v(n);
        pii ans_pair = pii(0, 0); // which means all was sorted already
        int ans_meaning = already_good;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int a;
                scanf("%d", &a);
                v[i].push_back(a);
            }
            vi sorted = v[i];
            sort(sorted.begin(), sorted.end());
            vi diff;
            for (int j = 0; j < m; ++j) {
                if (sorted[j] != v[i][j]) {
                    diff.push_back(j);
                }
            }
            if (ans_meaning == bad) {
                continue;
            }
            if (diff.size() > 2) {
                ans_meaning = bad;
            }
            if (diff.size() == 0) {
                if (ans_meaning == perm_pair) {
                    if (v[i][ans_pair.first] >= v[i][ans_pair.second]) {
                        //ok
                    } else {
                        ans_meaning = bad;
                    }
                }
            }
            if (diff.size() == 2) {
                if (ans_meaning == perm_pair) {
                    if (diff[0] != ans_pair.first || diff[1] != ans_pair.second) {
                        ans_meaning = bad;
                    }
                } else if (ans_meaning == already_good) {
                    ans_meaning = perm_pair;
                    ans_pair.first = diff[0];
                    ans_pair.second = diff[1];
                    for (int k = 0; k < i; ++k) {
                        if (v[k][ans_pair.first] < v[k][ans_pair.second]) {
                            ans_meaning = bad;
                        }
                    }
                }
            }
        }

        if (ans_meaning == bad) {
            printf("-1\n");
        }
        if (ans_meaning == already_good) {
            printf("1 1\n");
        }
        if (ans_meaning == perm_pair) {
            printf("%d %d\n", ans_pair.first + 1, ans_pair.second + 1);
        }

    }
    return 0;
}

