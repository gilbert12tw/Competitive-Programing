#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<queue>
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

struct Dijkstra {
    vector<pii> g[mxN];

    int dijkstra(int s, int t, int n) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dis(n + 1);
        fill(ALL(dis), INF);	
        dis[s] = 0; pq.push(0, s);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dis[u]) continue;
            for (auto [v, w] : g[u]) {
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    pq.push(dis[v], v);
                } 
            }
        }
        if (dis[t] == dis[0]) return -1;
        return dis[t] - 1;
    }
} dijkstra;

inline void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, s;
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> s;
            dijkstra.g[s].eb(m + i + 1, 1);
            dijkstra.g[m + i + 1].eb(s, 0);
        }
    }
    cout << dijkstra.dijkstra(1, m, n + m + 5);
}

signed main() {
	IO;	
	solve();	
}