
vector<int> ans;
struct MCMF {
	static const int mxE = 1e5 + 5, mxN = 305;
	int eu[mxE], ev[mxE], w[mxE], cap[mxE], tot;
	vector<int> g[mxN];
	inline void addEdge(int x, int y, int ew, int c) {
		g[x].eb(tot);
		eu[tot] = x; ev[tot] = y; w[tot] = ew; cap[tot++] = c;
		g[y].eb(tot);
		ev[tot] = x; eu[tot] = y; w[tot] = -ew; cap[tot++] = 0;
	}
	inline int SPFA(int s, int t) {
		vector<int> dis(mxN, -INF), from(mxN, 0), in(mxN, 0);
		dis[s] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			in[u] = 0;
			for (int i : g[u]) {
				int v = ev[i];
				if (cap[i] > 0 and dis[v] < dis[u] + w[i]) {
					dis[v] = dis[u] + w[i];
					from[v] = i;
					if (!in[v]) q.push(v);
					in[v] = 1;
				}
			}
		}
		if (ans.back() + dis[t] <= 0) return 0;
		ans.eb(dis[t] + ans.back());
		while (t != s) {
			int e = from[t];	
			swap(cap[e], cap[e^1]);
			t = eu[e];
		}
		return 1;
	}
	void run(int s, int t) {
		while (SPFA(s, t));
		// ans = ans.back()
	}
} flow;


