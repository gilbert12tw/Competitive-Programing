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

const int mxN = 2e5 + 5;

int n, k, a[mxN];
vector<int> ans;

int check(int thres) {
    ans.clear();
    ans.eb(1);
    int mn = a[1], mx = a[1];
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        if (mx - mn > thres) {
            mx = mn = a[i];
            ans.eb(i);
        }
    }
    return SZ(ans) <= k;
}

inline void solve() {
    cin >> n >> k;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }

    r += 10;
    while (l < r) {
        int mid = (l+r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    check(l);
    cout << l << '\n';
    vector<int> v(n + 1);
    int add = k - SZ(ans);
    add = 0;
    for (int i : ans) v[i] = 1;
    for (int i = n; i >= 1; i--) {
        if (add > 0 && v[i] == 0) {
            add--;
            v[i] = 1;
        }
    }
    
    int lst = -1;
    for (int i = 1; i <= n; i++) {
        if (v[i] && lst != -1) {
            cout << lst << ' ' << i - 1 << '\n';
        }
        if (v[i]) lst = i;
    }
    cout << lst << ' ' << n << '\n';
}

signed main() {
	IO;	
	solve();	
}
