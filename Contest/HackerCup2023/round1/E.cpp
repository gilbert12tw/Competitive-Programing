#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma loop-opt(on)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")
//#define loli
using namespace std;
typedef long long ll;
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

int BSZ = 800;
struct Query {
  int l, r;
};

bool cmp(Query a, Query b) {
  if (a.l / BSZ == b.l / BSZ) return (((a.l / BSZ) & 1) ? a.r > b.r : a.r < b.r);
  return a.l < b.l;
}

const int mxL = 3e6 + 5;
struct Trie {
  signed tot = 0;
  vector<pii> tr[mxL];

  vector<int> insert(string &s) {
    signed cur = 0;
    vector<int> res;
    for (char c : s) {
      signed idc = c - 'a';
      int nxt = 0;
      for (auto [v, al] : tr[cur]) if (al == idc) {
        nxt = v;
        break;
      }
      if (!nxt) { 
        nxt = ++tot;
        tr[cur].eb(nxt, idc);
      }
      cur = nxt;
      res.eb(cur);
    }
    return res;
  }
};

inline void solve(int cas) {
  int n; cin >> n;

  int mx_L = 0;
  vector<string> hw(n);
  for (auto &i: hw) {
    cin >> i;
    mx_L = max(mx_L, SZ(i));
  }
  vector<vector<pii>> hsh(mx_L + 1, vector<pii>());

  for (int i = 1; i <= mx_L; i++) hsh[i].eb(-10, -1), hsh[i].eb(-10, -1);
  Trie trie;
  for (int i = 0; i < n; i++) {
    reverse(ALL(hw[i]));
    vector<int> tmp = trie.insert(hw[i]);
    for (int j = 0; j < SZ(tmp); j++) hsh[j + 1].eb(i, tmp[j]);
  }
  for (int i = 1; i <= mx_L; i++) hsh[i].eb(n + 10, -1), hsh[i].eb(n + 10, -1);

  int q; cin >> q;
  map<int, vector<Query>> mp;
  for (int i = 0; i < q; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    mp[k].eb((Query){l-1, r-1});
  }

  ll ans = 0;
  int mx_ans = sqrt(n) + 1;
  for (auto [k, qry] : mp) {
    if (k > mx_L) break;

    sort(ALL(qry), cmp);

    unordered_map<int, int> cnt;
    cnt.reserve(n);
    vector<int> rcnt(mx_ans + 1, 0);

    vector<pii> now = hsh[k];

    auto add = [&](int x, int k) {
      int hsh = now[x].S;
      if (hsh < 0) return;
      rcnt[min(mx_ans, cnt[hsh])]--;
      rcnt[min(mx_ans, ++cnt[hsh])]++;
    };

    auto del = [&](int x, int k) {
      int hsh = now[x].S;
      if (hsh < 0) return;
      rcnt[min(mx_ans, cnt[hsh])]--;
      rcnt[min(mx_ans, --cnt[hsh])]++;
    };

    int l = 1, r = 0;
    for (auto [ql, qr] : qry) {
      while (l > 0 && now[l - 1].F >= ql) add(--l, k);
      while (r < SZ(now) && now[r + 1].F <= qr) add(++r, k);
      while (now[l].F < ql) del(l++, k);
      while (now[r].F > qr) del(r--, k);
      
      int res = 0, reser = 1;
      for (int i = 1; i <= mx_ans; i++) {
        int mn = min(reser, rcnt[i]);
        res += mn;
        reser -= mn;
        reser += 1;
      }
      ans += (res);
    }
  }

  cout << "Case #" << cas << ": " << ans << '\n';
}

signed main() {
	IO;	
  int T; cin >> T;
  for (int i = 1; i <= T; i++) solve(i);	
}
