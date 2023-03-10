struct DSU {
	vector<int> dsu, sz;
	DSU() {}
	DSU(int n) {
		dsu.resize(n + 1);
		sz.resize(n + 1, 1);
		for (int i = 0; i <= n; i++) dsu[i] = i;
	}
	int get(int x) {
		return dsu[x] == x ? x : dsu[x] = get(dsu[x]);
	}
	void oni(int a, int b) {
		a = get(a), b = get(b);
		if(a == b) return; 
		if(sz[a] > sz[b]) swap(a, b);
		dsu[a] = b;
		sz[b] += sz[a];
	}
};


