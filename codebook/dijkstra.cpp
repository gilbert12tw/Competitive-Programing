inline void dijkstra(int st) {
	fill(dis, dis + n + 1, INF);	
	dis[st] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(0, st);
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d > dis[u]) continue;
		if (u == t) return;
		for (auto [v, w] : g[u]) {
			if (dis[v] > d + w) {
				dis[v] = d + w;
				pq.push(dis[v], v);
			}
		}
	}
}

