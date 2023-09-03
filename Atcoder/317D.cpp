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

int n;

inline void solve() {
  cin >> n;
  vector<pii> item;
  vector<int> dp(100001, INF);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    sum += z;
    if (x > y) item.eb(0, z);
    else item.eb((y - x + 1) / 2, z);
  }
  dp[0] = 0;
  for (auto [c, sz] : item) {
    for (int i = sum; i >= sz; i--) {
      dp[i] = min(dp[i], dp[i-sz] + c);
    }
  }
  int ans = INF;
  for (int i = (sum + 1) / 2; i <= sum; i++) ans = min(ans, dp[i]);
  cout << ans;
}

signed main() {
	IO;	
	solve();	
}
