// LCA euler sequence
int st[mxN * 2][22], pos[mxN], dep[mxN], tp;
vector<int> g[mxN];

inline void build() {
	for(int i = 0; (1<<i) < tp; i++) {
		for(int j = 0; j + (1<<i) - 1 < tp; j++) {
			st[j][i + 1] = min(st[j][i], st[j + (1<<i)][i]);
		}
	}
}

inline int query(int l, int r) {
	int k = __lg(r - l + 1);
	return min(st[l][k], st[r - (1<<k) + 1][k]);
}

inline int dis(int u, int v) {
	if (pos[u] > pos[v]) swap(u, v);
	return dep[u] + dep[v] - 2 * query(pos[u], pos[v]);	
}

void euler_dfs(int u, int p) {
	pos[u] = tp;
	st[tp++][0] = dep[u];	
	for (int v : g[u]) {
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		euler_dfs(v, u);
		st[tp++][0] = dep[u];
	}
}
