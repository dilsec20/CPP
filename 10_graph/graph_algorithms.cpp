#include <bits/stdc++.h>
using namespace std;

// ===========================================
// GRAPH ALGORITHMS - Comprehensive Guide
// ===========================================

// ========== GRAPH REPRESENTATION ==========

// 1. Adjacency List Representation
class Graph {
public:
    int vertices;
    vector<vector<pair<int, int>>> adj;  // {neighbor, weight}
    
    Graph(int v) : vertices(v), adj(v) {}
    
    void addEdge(int u, int v, int weight = 1) {
        adj[u].push_back({v, weight});
        // adj[v].push_back({u, weight});  // Uncomment for undirected
    }
};

// ========== TRAVERSAL ALGORITHMS ==========

// BFS - Breadth First Search
vector<int> bfs(int start, const vector<vector<int>>& adj) {
    vector<int> result;
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    
    return result;
}

// DFS - Depth First Search (Recursive)
void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    visited[u] = true;
    result.push_back(u);
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, result);
        }
    }
}

vector<int> dfsRecursive(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    vector<int> result;
    dfs(start, adj, visited, result);
    return result;
}

// DFS - Iterative Version
vector<int> dfsIterative(int start, const vector<vector<int>>& adj) {
    vector<int> result;
    vector<bool> visited(adj.size(), false);
    stack<int> s;
    
    s.push(start);
    visited[start] = true;
    
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        result.push_back(u);
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
    
    return result;
}

// ========== SHORTEST PATH ALGORITHMS ==========

// Dijkstra's Algorithm - Single source shortest path
vector<long long> dijkstra(int start, const vector<vector<pair<int, long long>>>& adj) {
    int n = adj.size();
    vector<long long> dist(n, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

// Bellman-Ford Algorithm - Handles negative edges
vector<long long> bellmanFord(int start, int n, const vector<tuple<int, int, long long>>& edges) {
    vector<long long> dist(n, LLONG_MAX);
    dist[start] = 0;
    
    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // Check for negative cycles
    for (auto [u, v, w] : edges) {
        if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
            cerr << "Negative cycle detected!" << endl;
            return {};
        }
    }
    
    return dist;
}

// Floyd-Warshall Algorithm - All pairs shortest path
vector<vector<long long>> floydWarshall(int n, const vector<tuple<int, int, long long>>& edges) {
    vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));
    
    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    
    for (auto [u, v, w] : edges) {
        dist[u][v] = min(dist[u][v], w);
    }
    
    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    return dist;
}

// ========== MINIMUM SPANNING TREE ==========

// Union-Find (Disjoint Set Union) Data Structure
class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x == y) return false;
        
        // Union by rank
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        
        return true;
    }
};

// Kruskal's Algorithm - MST using Union-Find
long long kruskal(int n, vector<tuple<int, int, int>> edges) {
    sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
        return get<2>(a) < get<2>(b);
    });
    
    UnionFind uf(n);
    long long mstWeight = 0;
    int edgeCount = 0;
    
    for (auto [u, v, w] : edges) {
        if (uf.unite(u, v)) {
            mstWeight += w;
            edgeCount++;
            if (edgeCount == n - 1) break;
        }
    }
    
    return mstWeight;
}

// Prim's Algorithm - MST using priority queue
long long prim(int start, const vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    long long mstWeight = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        
        if (inMST[u]) continue;
        
        inMST[u] = true;
        mstWeight += w;
        
        for (auto [v, weight] : adj[u]) {
            if (!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }
    
    return mstWeight;
}

// ========== ADVANCED ALGORITHMS ==========

// Topological Sort - DFS based
void topoDFS(int u, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            topoDFS(v, adj, visited, st);
        }
    }
    
    st.push(u);
}

vector<int> topologicalSort(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoDFS(i, adj, visited, st);
        }
    }
    
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}

// Cycle Detection in Undirected Graph
bool hasCycleDFS(int u, int parent, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycleDFS(v, u, adj, visited)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }
    
    return false;
}

bool hasCycleUndirected(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && hasCycleDFS(i, -1, adj, visited)) {
            return true;
        }
    }
    
    return false;
}

// Cycle Detection in Directed Graph (DFS with colors)
// 0 = white (unvisited), 1 = gray (visiting), 2 = black (visited)
bool hasCycleDirectedDFS(int u, const vector<vector<int>>& adj, vector<int>& color) {
    color[u] = 1;  // Mark as gray
    
    for (int v : adj[u]) {
        if (color[v] == 1) {
            return true;  // Back edge found
        }
        if (color[v] == 0 && hasCycleDirectedDFS(v, adj, color)) {
            return true;
        }
    }
    
    color[u] = 2;  // Mark as black
    return false;
}

bool hasCycleDirected(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && hasCycleDirectedDFS(i, adj, color)) {
            return true;
        }
    }
    
    return false;
}

// Bipartite Graph Check
bool isBipartite(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);
    
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

// Strongly Connected Components - Tarjan's Algorithm
class SCC {
public:
    int n, timer = 0;
    vector<vector<int>> adj;
    vector<int> disc, low, st;
    vector<bool> inStack;
    vector<vector<int>> components;
    
    SCC(int n) : n(n), adj(n), disc(n, -1), low(n, -1), inStack(n, false) {}
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void tarjan(int u) {
        disc[u] = low[u] = timer++;
        st.push_back(u);
        inStack[u] = true;
        
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }
        
        if (disc[u] == low[u]) {
            vector<int> component;
            while (true) {
                int v = st.back();
                st.pop_back();
                inStack[v] = false;
                component.push_back(v);
                if (v == u) break;
            }
            components.push_back(component);
        }
    }
    
    void findSCC() {
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) {
                tarjan(i);
            }
        }
    }
};

// ========== UTILITY FUNCTIONS ==========

void printVector(const vector<int>& vec) {
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

// ========== EXAMPLE USAGE ==========

int main() {
    // Example: BFS and DFS
    cout << "=== Graph Traversal ===" << endl;
    
    vector<vector<int>> adj = {
        {1, 2},      // 0
        {0, 3},      // 1
        {0, 3},      // 2
        {1, 2, 4},   // 3
        {3}          // 4
    };
    
    cout << "BFS from 0: ";
    printVector(bfs(0, adj));
    
    cout << "DFS from 0: ";
    printVector(dfsRecursive(0, adj));
    
    // Example: Shortest Path with Dijkstra
    cout << "\n=== Shortest Path (Dijkstra) ===" << endl;
    
    vector<vector<pair<int, long long>>> weightedAdj = {
        {{1, 1}, {2, 4}},
        {{0, 1}, {3, 2}},
        {{0, 4}, {3, 1}},
        {{1, 2}, {2, 1}, {4, 5}},
        {{3, 5}}
    };
    
    vector<long long> dist = dijkstra(0, weightedAdj);
    cout << "Distances from 0: ";
    for (long long d : dist) {
        cout << (d == LLONG_MAX ? -1 : d) << " ";
    }
    cout << endl;
    
    // Example: Cycle Detection
    cout << "\n=== Cycle Detection ===" << endl;
    cout << "Has cycle: " << (hasCycleUndirected(adj) ? "Yes" : "No") << endl;
    
    // Example: Bipartite Check
    cout << "\n=== Bipartite Check ===" << endl;
    cout << "Is bipartite: " << (isBipartite(adj) ? "Yes" : "No") << endl;
    
    return 0;
}
