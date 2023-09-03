#include<bits/stdc++.h>
#define loli
using namespace std;
typedef long long ll;
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

const int p = 17;
int len[1000001];
vector<vector<int>> hsh;

inline void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) { 
        cin >> len[i];
        string s; cin >> s;
        vector<int> sum;
        sum.eb(0);
        int pp = 1;
        for (int j = 1; j <= len[i]; j++) {
            int res = (sum.back() + (pp * s[j-1]) % mod) % mod;
            sum.eb(res);
            pp = pp * p % mod;
        }
        hsh.eb(sum);
    }

    while (q--) {
        vector<int> abc(4);
        int l = 0, r = inf;
        for (int &i : abc) { 
            cin >> i; i--;
            r = min(r, len[i]);
        }

        while (l < r) {
            int mid = (l + r + 1) >> 1;
            set<int> st;
            for (int i : abc) {
                st.insert(hsh[i][mid]);
            }
            if (SZ(st) > 1) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        
        cout << l << '\n';
    }
}

signed main() {
	IO;	
	solve();	
}
