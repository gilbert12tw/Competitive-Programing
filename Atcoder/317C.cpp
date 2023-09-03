
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

int dp[11][1500];
int mat[11][11];

inline void solve() {
  int n, m;
  cin >> n >> m;
  memset(dp, -0x3f, sizeof dp);
  memset(mat, -0x3f, sizeof mat);
  for (int i = 0; i < n; i++) dp[i][(1<<i)] = 0;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    mat[a][b] = max(mat[a][b], c);
    mat[b][a] = max(mat[b][a], c);
  }
  
  int ans = 0;
  for (int i = 0; i < (1<<n); i++) {
    for (int j = 0; j < n; j++) {
      if (get_bit(i, j) == 0)
        continue;
      ans = max(ans, dp[j][i]);
      for (int k = 0; k < n; k++) {
        if (get_bit(i, k)) 
          continue;
        dp[k][i^(1<<k)] = max(dp[k][i^(1<<k)], dp[j][i] + mat[j][k]);
      }
    }
  }
  cout << ans;
}

signed main() {
	IO;	
	solve();	
}
