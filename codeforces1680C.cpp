#include <iostream>
#include <set>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + INF;

pii get_score(vi & zeros, vi & ones, string & s, int cut_from, int zeros_left, int ones_removed) {
    zeros_left -= zeros[cut_from];
    ones_removed += ones[cut_from];
    return pii(zeros_left, ones_removed);
}

void solve() {
    string s;
    cin >> s;
    vi zeros(s.size() + 1);
    vi ones(s.size() + 1);
    for (int i = 0; i < s.size(); ++i) {
        zeros[i + 1] = zeros[i];
        ones[i + 1] = ones[i];
        if (s[i] == '0') {
            zeros[i + 1] += 1;
        } else {
            ones[i + 1] += 1;
        }
    }
    int global_ans = zeros.back();
    for (int cut_till = s.size(); cut_till >= 0; cut_till--) {
        int zeros_left = zeros[cut_till];
        int ones_removed = ones[s.size()] - ones[cut_till];

        int l = 0;
        int r = cut_till;
        while (r - l > 1) {
            int m = (r + l) / 2;
            pii score = get_score(zeros, ones, s, m, zeros_left, ones_removed);
            if (score.first > score.second) {
                l = m;
            } else {
                r = m;
            }
        }
        pii score = get_score(zeros, ones, s, l, zeros_left, ones_removed);
        global_ans = min(global_ans, max(score.first, score.second));
        pii score = get_score(zeros, ones, s, r, zeros_left, ones_removed);
        global_ans = min(global_ans, max(score.first, score.second));
    }
    cout << global_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    int t;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}