#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<bitset>
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

int check(vector<int> &a, vector<int> &b, int del, int x) {
    for (int i = SZ(a) - 1, j = del; j < SZ(a); j++, i--) 
        if (a[i] + b[j] < x) return 0;
    return 1;
}

inline void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(ALL(a));
    sort(ALL(b));

    // max rank
    /*
    int mx = 0, mx2 = 0;
    for (int i = n - 1, j = 0; i >= 0; i--) {
        while (j + 1 < n && a[i] + b[j] < x) j++;
        if (a[i] + b[j] >= x) {
            j++;
            mx++;
        }
    }

    swap(a, b);
    for (int i = n - 1, j = 0; i >= 0; i--) {
        while (j + 1 < n && a[i] + b[j] < x) j++;
        if (a[i] + b[j] >= x) {
            j++;
            mx2++;
        }
    }
    */

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(a, b, mid, x)) r = mid;
        else l = mid + 1;
    }

    cout << 1 << ' ' << n - l << '\n';
}

signed main() {
    IO;	
    solve();	
}
