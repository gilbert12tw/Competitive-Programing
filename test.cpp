#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0, r;
  cin >> r;
  for (int x = 0; x < r; x++) {
    cin >> n;
    vector<int> g[n + 1];
    int cost[n + 1] = {0}, cost2[n + 1] = {0};
    int in[n + 1] = {0};

    for (int i = 1; i <= n; i++) {
      cin >> cost[i];
      cost2[i] = cost[i];
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int temp;
        cin >> temp;
        g[i].emplace_back(temp);
        in[temp] += 1;
      }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (in[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int now = q.front();
      for (int i : g[now]) {
        in[i] -= 1;
        if (in[i] == 0)
          q.push(i);
        cost2[i] = max(cost2[i], cost2[now] + cost[i]);
      }
      q.pop();
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
      if (ans < cost2[i])
        ans = cost2[i];
    }
    cout << ans << '\n';
  }
}
