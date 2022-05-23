#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; ++tt) {
        int n, k;
        scanf("%d %d", &n, &k); 
        vi v(n);
        vector<pii> scores(n);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
            ans += v[i];
        }
        ans -= ((long long)k) * (k - 1) / 2;
        for (int i = n - 1; i >= 0; --i) {
            scores[i] = pii(v[i] - ((n-1) - i), i);
        }
        sort(scores.begin(), scores.end());
        reverse(scores.begin(), scores.end());
        for (int i = 0; i < k; ++i) {
            ans -= scores[i].first;
        }
        printf("%lld\n", ans);
    }
    return 0;
} 

