#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef unordered_map<int, int> umii;

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; ++tt) {
        int n, k;
        scanf("%d %d", &n, &k); 
        vi a(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());
        int last_ins = 0;


        while (true) {
            vi::iterator it = lower_bound(a.begin(), a.end(), last_ins);
            if (it == a.end()) {
                break;
            }
            if (*it == last_ins) {
                last_ins += 1;
            } else {
                break;
            }
        }
        for (int i = 0; i < k; ++i) {
            last_ins += 1;
            while (true) {
                vi::iterator it = lower_bound(a.begin(), a.end(), last_ins);
                if (it == a.end()) {
                    break;
                }
                if (*it == last_ins) {
                    last_ins += 1;
                } else {
                    break;
                }
            }
        }

        vi::iterator start = lower_bound(a.begin(), a.end(), last_ins);
        vi numbers_left(start, a.end());
        if (numbers_left.size() <= k) {
            printf("0\n");
            continue;
        }
        vector<pii> vp;
        for (vi::iterator it = numbers_left.begin(); it != numbers_left.end();) {
            vi::iterator it2;
            int sum = 0;
            for (it2 = it; it2 != numbers_left.end() && *it2 == *it; ++it2) {
                sum += 1;
            }
            vp.push_back(pii(sum, *it));
            it = it2;
        }
        sort(vp.begin(), vp.end());
        int vp_pos = 0;
        for (int i = 0; i < k; ++i) {
            vp[vp_pos].first -= 1;
            if (vp[vp_pos].first == 0) {
                vp_pos += 1;
            }
        }
        int diff = vp.size() - vp_pos;
        printf("%d\n", diff);
    }
    return 0;
} 

    