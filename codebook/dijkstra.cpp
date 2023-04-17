struct Dijkstra {
    vector<pii> g[mxN];
    int dis[mxN];

    int dijkstra(int s, int t) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        fill(dis, dis + n + 1, INF);	
        dis[s] = 0; pq.push(0, s);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dis[u]) continue;
            for (auto [v, w] : g[u]) {
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    pq.push(dis[v], v);
                } 
            }
        }

        return dis[t];
    }
};
