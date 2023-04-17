// BCC
int df, dep[mxN], low[mxN], bcc[mxN], cc;
int eu[mxN], ev[mxN];
vector<int> g[mxN], tr[mxN];
vector<int> stk;

void tarjan(int u, int e = -1){
	dep[u] = low[u] = ++df;
	stk.pb(u);
	for(int i : g[u]){
		int v = eu[i] ^ ev[i] ^ u;
		if (i == e) continue;
		if(!dep[v]){
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], dep[v]);
		}
	}

	if (dep[u] == low[u] and e != -1) {
		while (stk.back() != u) {
			bcc[stk.back()] = cc; stk.pop_back();
		}
		bcc[stk.back()] = cc++;   stk.pop_back();
	}
}

void build_BCT() {
	for (int u = 1; u <= n; u++) for (int v : g[u]) if (bcc[u] != bcc[eu[i] ^ ev[i] ^ u]) {
		tr[bcc[u]].eb(bcc[eu[i] ^ ev[i] ^ u]);
	}
}
