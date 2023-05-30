#include<bits/stdc++.h>
#define loli
using namespace std;
typedef long long ll;
#define int ll
#define pii pair<int, int>
#define X first
#define Y second
#define F first
#define S second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define push emplace
#define lb(x, v) lower_bound(ALL(x), v)
#define ub(x, v) upper_bound(ALL(x), v)
#define re(x) reverse(ALL(x))
#define uni(x) x.resize(unique(ALL(x)) - x.begin())
#define inf 1000000000
#define INF 1000000000000000000
#define mod 1000000007
#define get_bit(x, y) ((x>>y)&1)
#define mkp make_pair
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
#ifdef loli
#define test(args...) abc("[" + string(#args) + "]", args)
#else
#define test(args...) void(0)
#endif

const int mxN = 2e6 + 5;

int n, m, p, L[mxN], R[mxN];
vector<int> g[mxN];
int dis[mxN * 2];

inline void solve() {
    cin >> n >> m >> p;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v); 
        g[v].eb(u);
    }

    for (int i = 0; i < p; i++) {
        int c; cin >> c;
        cin >> L[c] >> R[c];
    }

    // dijkstra
    memset(dis, 0x3f, sizeof dis);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(0, 1);   
    dis[1] = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dis[u] < d) continue;
        if (u > n) u -= n;

        for (int v : g[u]) {
            if (R[v] == 0 || L[v] > d + 1) { // first case
                if (dis[v] > d + 1) {
                    dis[v] = d + 1;
                    pq.push(d + 1, v);
                }
            }

            if (R[v] < d + 1) {
                if (dis[v+n] > d + 1) {
                    dis[v+n] = d + 1;
                    pq.push(d + 1, v+n);
                }
            } else if (R[v] + 1 < L[u] || R[v] + 1 > R[u]) {
                if (dis[v+n] > R[v] + 1) {
                    dis[v+n] = R[v] + 1;
                    pq.push(R[v] + 1, v+n);
                }
            }
        }
    }


    int ans = min(dis[n], dis[n + n]);
    if (ans == dis[0]) cout << "can't reach\n";
    else cout << ans << '\n';
}

signed main() {
	IO;	
	solve();	
}

/*
11 12 1
1 2
1 3
1 5
2 4 
3 6 
4 7 
5 8 
5 10 
6 9 
7 8 
8 11 
9 10 
5 1 1
*/