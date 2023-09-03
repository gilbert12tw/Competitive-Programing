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

int n, m;
vector<pii> bad[20];

inline void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        bad[s[1]-'a'].eb(mkp(s[0]-'a',  s[2]-'a'));
    }

    vector<int> dp((1<<n)+1, 0);
    dp[0] = 1;
    for (int i = 0; i < (1<<n); i++) {
        if (dp[i] == 0) continue;
        for (int j = 0; j < n; j++) {
            if (get_bit(i, j)) continue;
            int check = 1;
            for (auto [x, y] : bad[j]) {
                if (get_bit(i, x) && !get_bit(i, y)) {
                    check = 0;
                    break;
                }
            }
            if (check) 
                dp[i | (1<<j)] += dp[i];
        }
    }
    int res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    cout << res - dp[(1<<n)-1];
}

signed main() {
	IO;	
	solve();	
}
