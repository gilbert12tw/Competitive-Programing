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

const int mxN = 1e3 + 5;

int n, k, mat[4][mxN][mxN];

inline void solve() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y; 
        cin >> x >> y;
        mat[0][x][y] = mat[1][x][y] = mat[2][x][y] = mat[3][x][y] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mat[0][i][j] |= mat[0][i-1][j];
            mat[1][i][j] |= mat[1][i][j-1];
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            mat[2][i][j] |= mat[2][i+1][j];
            mat[3][i][j] |= mat[3][i][j+1];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int res = 0;
            for (int k = 0; k < 4; k++) {
                res |= mat[k][i][j];
            }
            if (!res) ans++;
        }
    }
    cout << ans << '\n';
}

signed main() {
	IO;	
	solve();	
}
