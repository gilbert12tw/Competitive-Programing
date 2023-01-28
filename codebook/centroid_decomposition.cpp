int pa[mxN], sz[mxN];
bitset<mxN> del;

void get_sz(int u, int p) {
	sz[u] = 1;
	for (int v : g[u]) {
		if (v == p or del[v]) continue;
		get_sz(v, u);
		sz[u] += sz[v];	
	}
}

int get_centroid(int u, int n, int p) {
	for (int v : g[u]) {
		if (v != p and !del[v] and sz[v] * 2 > n) 
			return get_centroid(v, n, u);
	}
	return u;
}

int build(int u) {
	get_sz(u, -1);	
	int centroid = get_centroid(u, sz[u], -1);
	del[centroid] = 1;
	for (int v : g[centroid]) {
		if (del[v]) continue;
		pa[build(v)] = centroid;
	}
	return centroid;
}

