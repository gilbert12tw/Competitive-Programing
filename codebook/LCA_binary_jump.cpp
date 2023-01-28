// LCA binary jump
int up[mxN][25], dep[mxN];
const int mxL = 20;

void dfs(int u, int p = -1) {
	if (p != -1) up[u][0] = p;

	for (int i = 1; (1<<i) <= dep[u]; i++) {
		up[u][i] = up[up[u][i-1]][i-1];
	}

	for (int v : g[u]) {
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}

inline int lca(int u, int v) {
	if (u == v) return u;
	if (dep[u] < dep[v]) swap(u, v);

	for (int i = mxL; i >= 0; i--) {
		if (up[u][i] and dep[up[u][i]] >= dep[v]) {
			u = up[u][i];
		}
	}

	if (u == v) return u;

	for (int i = mxL; i >= 0; i--) {
		if (up[u][i] and up[v][i] and up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}

	return up[u][0];
}

