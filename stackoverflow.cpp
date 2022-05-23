#include <iostream>
#include <set>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + INF;

int n, m;
ll k;
vector<vi> g;
vi a;

vi color;
vector<ll> length;

// returns max length
ll dfs(int u, ll max_weight) {
    color[u] = 1;
    for (auto &v: g[u]) {
        if (color[v] == 2) {
            length[u] = min(INFLL, max(length[u], length[v] + 1));
        } else if (color[v] == 1) {
            length[u] = INFLL;
        } else if (color[v] == 0 && a[v] <= max_weight) {
            dfs(v, max_weight);
            length[u] = min(INFLL, max(length[u], length[v] + 1));
        }
    }
    color[u] = 2;
    return length[u];
}

ll get_max_length(ll max_weight) {
    color.assign(n, 0);
    length.assign(n, 1);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0 && a[i] <= max_weight) {
            ans = max(ans, dfs(i, max_weight));
        }
    }
    return ans;
}

void solve() {

    cin >> n >> m >> k;
    g.assign(n, vi());
    a.assign(n, 0);
    for (auto &ai : a)
        cin >> ai;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }

    ll low = 0;
    ll high = INF;
    if (get_max_length(high) < k) {
        cout << -1 << "\n";
        return;
    }
    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        ll ans = get_max_length(mid);
        if (ans < k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << high << "\n";
}

int rec(int a) {
    return rec(a+1);
}

int main() {
    freopen("codeforces1679D-6.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    int t;
//    cin >> t;
//    while (t--) solve();
    rec(1);
    return 0;
}