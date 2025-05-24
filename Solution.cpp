#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1e9 + 7;
ll check = 0;
vector<ll> visited(1, 0);

void toposort(stack<ll>& st, vector<vector<ll>>& adj, ll n) {
    visited[n] = 1;
    for (auto k : adj[n]) {
        if (visited[k] == 1) continue;
        toposort(st, adj, k);
    }
    st.push(n);
}

void solve() {
    ll n, m;
    cin >> n >> m;
    visited.clear();
    visited.resize(n + 1, 0);
    stack<ll> st;
    vector<vector<ll>> v(n, vector<ll>(4, 0));
    vector<vector<ll>> adj(n + 1);
    vector<vector<ll>> rev(n + 1);

    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        char s, c;
        int x, y;
        cin >> s >> x >> c >> y;
        v[i][1] = x;
        v[i][3] = y;
        v[i][0] = (s == '+' ? 1 : 2);
        v[i][2] = (c == '+' ? 1 : 2);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) toposort(st, adj, i);
    }

    vector<ll> ans(n + 1, 0);
    while (!st.empty()) {
        ll idx = st.top();
        st.pop();
        ll y = 0;
        for (auto l : rev[idx]) {
            y = max(y, ans[l]);
        }
        for (int i = 0; i < 3; i += 2) {
            if (v[idx - 1][i] == 1) {
                ans[idx] = max(ans[idx], y + v[idx - 1][i + 1]);
            }
            if (v[idx - 1][i] == 2) {
                ans[idx] = max(ans[idx], y * v[idx - 1][i + 1]);
            }
        }
    }

    ll maxx = 0;
    for (int i = 1; i <= n; i++) {
        maxx = max(maxx, ans[i]);
    }
    cout << maxx << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
