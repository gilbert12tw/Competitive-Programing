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

const int mxN = 3e5 + 5;
int n, q, a[mxN];
pii jump[mxN][22];

inline void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> stk;
    stk.eb(n + 1);
    for (int i = n; i >= 1; i--) {
        while (a[stk.back()] > a[i]) stk.pop_back();
        jump[i][0] = mkp(stk.back(), (stk.back() - i) * a[i]);
        stk.eb(i);
        for (int j = 1; j <= 20; j++) {
            if (jump[i][j-1].F == n + 1) break;
            jump[i][j] = mkp(jump[jump[i][j-1].F][j-1].F, jump[i][j-1].S + jump[jump[i][j-1].F][j-1].S);
        }
    
    }

    while (q--) {
        int l, r; cin >> l >> r;
        int sum = 0;
        for (int i = 20; i >= 0; i--) {
            if (l <= jump[l][i].F && jump[l][i].F <= r) {
                sum += jump[l][i].S;
                l = jump[l][i].F;
            }
        }
        if (l <= r) {
            sum += (r - l + 1) * a[l];
        }
        cout << sum << '\n';
    }
}

signed main() {
	IO;	
	solve();	
}
