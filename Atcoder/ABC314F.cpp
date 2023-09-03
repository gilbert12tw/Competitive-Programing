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
#define mod 998244353
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

inline int fp(int a, int b, int p) {
    int res = 1;
    while(b) {
        if(b&1) res = (res * a) % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
 
inline int inv(int x) {return fp(x, mod - 2, mod);}

struct DSU {
	vector<int> dsu, sz;
	DSU(int n) {
		dsu.resize(n + 1);
		sz.resize(n + 1, 1);
		for (int i = 0; i <= n; i++) dsu[i] = i;
	}
	int get(int x) {
		return (dsu[x] == x ? x : dsu[x] = get(dsu[x]));
	}
    int get_size(int x) {
        return sz[get(x)];
    }
	void oni(int a, int b) {
		a = get(a), b = get(b);
		if(a == b) return; 
		dsu[a] = b;
		sz[b] += sz[a];
	}
};

const int mxN = 4e5 + 5;
int tsz[mxN];
int ans[mxN];
vector<int> tr[mxN];

void dfs(int u, int prob) {

    if (SZ(tr[u]) == 0) {
        ans[u] = prob;
        return;
    }

    for (int v : tr[u]) {
        dfs(v, (prob + (tsz[v] * inv(tsz[tr[u][0]] + tsz[tr[u][1]]) % mod) % mod) % mod);
    }
}

inline void solve() {
    int n;
    cin >> n;
    DSU dsu(2 * n);
    
    int cnt = n;
    for (int i = 1; i <= n; i++) tsz[i] = 1;
    for (int i = 0; i < n - 1; i++) {
        int p, q;
        ++cnt;
        cin >> p >> q;
        tsz[cnt] = tsz[dsu.get(p)] + tsz[dsu.get(q)];
        tr[cnt].eb(dsu.get(p));
        tr[cnt].eb(dsu.get(q));
        dsu.oni(p, cnt);
        dsu.oni(q, cnt);
    }
    
    dfs(2 * n - 1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}

signed main() {
	IO;	
	solve();	
}
