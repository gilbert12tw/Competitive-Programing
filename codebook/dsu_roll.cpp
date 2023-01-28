struct DSU {
	int pa[mxN], sz[mxN];
	vector<pii> stk;
	DSU() {
		for (int i = 0; i <= n; i++) pa[i] = i, sz[i] = 1; 
	}

	int get(int u) { return pa[u] == u ? u : get(pa[u]); }

	bool merge(int u, int v) {
		u = get(u), v = get(v);
		if (u == v) return 0;
		if (sz[u] > sz[v]) swap(u, v);
		sz[v] += sz[u];
		pa[u] = v;
		stk.eb(u, v);
		return 1;
	}

	int record() { return sz(stk); }

	void roll_back(int keep_point) {
		while (sz(stk) > keep_point) {
			pa[stk.back().F] = stk.back();
			sz[stk.back().S] -= sz[stk.back().F];
			stk.pop_back();
		}
	}
};


