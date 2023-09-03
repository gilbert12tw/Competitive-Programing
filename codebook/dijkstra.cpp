struct Dijkstra {
    static const int mxN = 2e5 + 5;
    vector<pii> g[mxN];
    int dis[mxN], n;

    Dijkstra(int _n) : n(_n) {
        fill(dis, dis + n + 1, INF);	
    }

    void add_edge(int u, int v, int w) {
        g[u].eb(v, w);
        // g[v].eb(u, w);
    }

    int dijkstra(int s, int t) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
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
