# Graph Algorithms in C++ for Competitive Programming

## Table of Contents
1. [Introduction](#introduction)
2. [Graph Representation](#graph-representation)
3. [Graph Traversal](#graph-traversal)
4. [Shortest Path Algorithms](#shortest-path-algorithms)
5. [Minimum Spanning Tree](#minimum-spanning-tree)
6. [Advanced Graph Concepts](#advanced-graph-concepts)
7. [Competitive Programming Problems](#competitive-programming-problems)
8. [Tips and Tricks](#tips-and-tricks)

---

## Introduction

Graph algorithms are crucial for competitive programming. This guide covers essential graph techniques with implementations and practical examples.

### What You'll Learn:
- Different graph representations
- Traversal algorithms (BFS, DFS)
- Shortest path algorithms (Dijkstra, Bellman-Ford, Floyd-Warshall)
- Minimum spanning trees (Kruskal, Prim)
- Advanced concepts (topological sort, cycle detection, bipartite graphs)

---

## Graph Representation

### 1. Adjacency List (Preferred for sparse graphs)
```cpp
vector<vector<int>> adj(n);
adj[u].push_back(v);  // Add edge u -> v
```

### 2. Adjacency Matrix (Preferred for dense graphs)
```cpp
vector<vector<int>> adj(n, vector<int>(n, 0));
adj[u][v] = 1;  // Add edge u -> v
```

### 3. Edge List
```cpp
vector<tuple<int, int, int>> edges;  // {u, v, weight}
```

### Complete Representation Example
```cpp
// Graph class for flexible representation
class Graph {
public:
    int n;
    vector<vector<pair<int, int>>> adj;  // {neighbor, weight}
    
    Graph(int vertices) : n(vertices), adj(vertices) {}
    
    void addEdge(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});  // Uncomment for undirected
    }
};
```

---

## Graph Traversal

### Breadth-First Search (BFS)
**Time Complexity:** O(V + E)  
**Space Complexity:** O(V)

```cpp
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
```

### Depth-First Search (DFS)
**Time Complexity:** O(V + E)  
**Space Complexity:** O(V)

```cpp
void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

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
```

---

## Shortest Path Algorithms

### Dijkstra's Algorithm
**Time Complexity:** O((V + E) log V) with min-heap  
**Constraints:** No negative edges

```cpp
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
```

### Bellman-Ford Algorithm
**Time Complexity:** O(V * E)  
**Constraints:** None (handles negative edges and detects negative cycles)

```cpp
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
            cout << "Negative cycle detected!" << endl;
            return {};
        }
    }
    
    return dist;
}
```

### Floyd-Warshall Algorithm
**Time Complexity:** O(V³)  
**Use Case:** All-pairs shortest path

```cpp
vector<vector<long long>> floydWarshall(int n, const vector<tuple<int, int, long long>>& edges) {
    vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));
    
    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    
    for (auto [u, v, w] : edges) {
        dist[u][v] = min(dist[u][v], w);
    }
    
    // Update distances through intermediate vertices
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
```

---

## Minimum Spanning Tree

### Kruskal's Algorithm (with Union-Find)
**Time Complexity:** O(E log E)  
**Use Case:** MST with edge-centric approach

```cpp
class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x == y) return false;
        
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        
        return true;
    }
};

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
```

### Prim's Algorithm
**Time Complexity:** O((V + E) log V) with min-heap  
**Use Case:** MST with vertex-centric approach

```cpp
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
```

---

## Advanced Graph Concepts

### Topological Sort (DFS-based)
```cpp
void topoDFS(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            topoDFS(v, adj, visited, st);
        }
    }
    
    st.push(u);
}

vector<int> topologicalSort(vector<vector<int>>& adj) {
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
```

### Cycle Detection (Undirected Graph)
```cpp
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

bool hasCycle(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && hasCycleDFS(i, -1, adj, visited)) {
            return true;
        }
    }
    
    return false;
}
```

### Bipartite Graph Check
```cpp
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
```

### Strongly Connected Components (Tarjan's Algorithm)
```cpp
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
```

---

## Competitive Programming Problems

### 1. Connected Components Count
```cpp
int countComponents(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(n, false);
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    
    return count;
}
```

### 2. Shortest Path in Unweighted Graph
```cpp
vector<int> shortestPath(int n, vector<pair<int, int>>& edges, int start) {
    vector<vector<int>> adj(n);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(n, -1);
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return dist;
}
```

---

## Tips and Tricks

1. **Choose Right Representation**: Use adjacency list for sparse graphs, adjacency matrix for dense ones
2. **Time Limits**: Know which algorithm fits the constraints
3. **Memory**: Be careful with large adjacency matrices
4. **Edge Cases**: Handle disconnected components, single node, empty graphs
5. **Testing**: Start with small examples and manually trace the algorithm
6. **Optimization**: Use fast I/O and appropriate data structures

---

## Complexity Comparison

| Algorithm | Time | Space | Use Case |
|-----------|------|-------|----------|
| BFS | O(V+E) | O(V) | Shortest path (unweighted) |
| DFS | O(V+E) | O(V) | Traversal, connectivity |
| Dijkstra | O((V+E)logV) | O(V) | Shortest path (non-negative) |
| Bellman-Ford | O(VE) | O(V) | Shortest path, detects negative cycle |
| Floyd-Warshall | O(V³) | O(V²) | All-pairs shortest path |
| Kruskal | O(ElogE) | O(V+E) | MST |
| Prim | O((V+E)logV) | O(V) | MST |

