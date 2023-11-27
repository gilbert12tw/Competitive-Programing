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
#define vi vector<int>
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
#define MOD 998244353
#define get_bit(x, y) ((x>>y)&1)
#define mkp make_pair
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
#ifdef loli
#define test(args...) abc("[" + string(#args) + "]", args)
#else
#define test(args...) void(0)
#endif

template<class T> bool ckmin(T& a, const T& b) { return b<a ? a=b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a<b ? a=b, 1 : 0; }

int mat[1001][1001];
inline void solve() {
    int n, m, lim;
    cin >> n >> m >> lim;
    memset(mat, 0x3f, sizeof mat);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mat[a][b] = mat[b][a] = c;
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][k] + mat[k][j] <= lim && mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }

    int ans = 0;
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (mat[i][j] <= lim)
                cnt[i]++;
        }
        if (cnt[i] >= cnt[ans])
            ans = i;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        if (i == ans)
            continue;
        if (mat[ans][i] <= lim) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

signed main() {
	IO;	
	solve();	
}
