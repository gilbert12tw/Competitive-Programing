#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

// Representation of an edge
struct Edge {
    int to;
    int weight;
};

// Dijkstra's algorithm to find the shortest path from source to all other cities
vector<int> dijkstra(int source, int num_cities, const vector<vector<Edge>>& graph) {
    vector<int> dist(num_cities, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int N1, N2, M;
    cin >> N1 >> N2 >> M;

    int total_cities = N1 + N2;

    // Create an adjacency list to represent the graph
    vector<vector<Edge>> graph(total_cities);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, 1}); // Assuming ships take 1 unit of time
        graph[v].push_back({u, 1}); // Assuming ships take 1 unit of time
    }

    // Find the shortest distances from city 1 to all other cities
    vector<int> distances = dijkstra(1, total_cities, graph);

    // Find the maximum distance to any city on Hua Island (N1 + 1 to N1 + N2)
    int max_distance = 0;
    for (int i = N1 + 1; i <= N1 + N2; ++i) {
        max_distance = max(max_distance, distances[i]);
    }

    cout << max_distance << endl;

    return 0;
}

