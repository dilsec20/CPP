# Graph Algorithms - Quick Reference

## Time Complexities Cheat Sheet

| Algorithm | Time | Space | When to Use |
|-----------|------|-------|-------------|
| BFS | O(V+E) | O(V) | Shortest path (unweighted), level-order |
| DFS | O(V+E) | O(V) | Traversal, connectivity, cycles |
| Dijkstra | O((V+E)logV) | O(V) | Shortest path (no negative) |
| Bellman-Ford | O(VE) | O(V) | Shortest path, negative edges |
| Floyd-Warshall | O(V³) | O(V²) | All pairs shortest path |
| Kruskal | O(ElogE) | O(V+E) | MST |
| Prim | O((V+E)logV) | O(V) | MST |
| Topological Sort | O(V+E) | O(V) | DAG ordering |
| Tarjan SCC | O(V+E) | O(V) | Strongly connected components |

---

## Code Templates

### 1. Build Graph from Edges
```cpp
// Adjacency list
vector<vector<int>> adj(n);
for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // For undirected
}

// Adjacency list with weights
vector<vector<pair<int, int>>> adj(n);  // {neighbor, weight}
for (auto [u, v, w] : edges) {
    adj[u].push_back({v, w});
}
```

### 2. BFS Template
```cpp
vector<int> bfs(int start, vector<vector<int>>& adj) {
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

### 3. DFS Template
```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    // Process u
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}
```

### 4. Dijkstra's Algorithm
```cpp
vector<long long> dijkstra(int start, vector<vector<pair<int, long long>>>& adj) {
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

### 5. Union-Find (DSU)
```cpp
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
        
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};
```

### 6. Kruskal's Algorithm
```cpp
long long kruskal(int n, vector<tuple<int, int, int>>& edges) {
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
        return get<2>(a) < get<2>(b);
    });
    
    UnionFind uf(n);
    long long mst = 0;
    
    for (auto [u, v, w] : edges) {
        if (uf.unite(u, v)) {
            mst += w;
        }
    }
    
    return mst;
}
```

### 7. Topological Sort (DFS)
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

### 8. Topological Sort (Kahn's Algorithm)
```cpp
vector<int> kahnsAlgorithm(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }
    
    return (result.size() == n) ? result : vector<int>();
}
```

### 9. Cycle Detection (Undirected)
```cpp
bool hasCycle(int u, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycle(v, u, adj, visited)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}
```

### 10. Cycle Detection (Directed - Colors)
```cpp
// 0: white, 1: gray, 2: black
bool hasCycle(int u, vector<vector<int>>& adj, vector<int>& color) {
    color[u] = 1;  // Mark gray
    
    for (int v : adj[u]) {
        if (color[v] == 1) return true;  // Back edge
        if (color[v] == 0 && hasCycle(v, adj, color)) return true;
    }
    
    color[u] = 2;  // Mark black
    return false;
}
```

### 11. Bipartite Check
```cpp
bool isBipartite(vector<vector<int>>& adj) {
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

---

## Common Patterns

### Pattern 1: Graph exists but not constructed
```cpp
vector<vector<int>> adj(n);
for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

### Pattern 2: 2D Grid as Graph
```cpp
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
        // Process neighbor
    }
}
```

### Pattern 3: Find distances from source
```cpp
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
```

### Pattern 4: Detect if Graph is Tree
```cpp
// A tree: n-1 edges, connected, no cycle
bool isTree(int n, vector<pair<int, int>>& edges) {
    if (edges.size() != n - 1) return false;
    
    // Check connected using BFS/DFS
    // Check no cycle using DFS
}
```

---

## Tips & Tricks

1. **Start with small n**: Test algorithms with n ≤ 10 first
2. **LLONG_MAX vs INT_MAX**: Use LLONG_MAX for distances to avoid overflow
3. **Edge cases**: Empty graph, single node, disconnected components
4. **Priority Queue**: Use `greater<>` for min-heap in Dijkstra
5. **Visited array**: Initialize based on graph representation (adjacency list or matrix)
6. **Path reconstruction**: Store parent array during BFS/DFS if needed
7. **Modulo operations**: Apply modulo in MST/shortest path if required

---

## Common Mistakes

❌ Forgetting to mark visited nodes  
❌ Using INT_MAX instead of LLONG_MAX  
❌ Not handling disconnected components  
❌ Incorrect parent tracking in cycle detection  
❌ Edge weight overflow in MST  
❌ Infinite loops when queue/stack never empties  
❌ Using wrong data structure (list vs set)

---

## Quick Decision Tree

**Need shortest path?**
- Unweighted → BFS
- Non-negative weights → Dijkstra
- Negative weights → Bellman-Ford
- All pairs → Floyd-Warshall

**Need MST?**
- Dense graph → Prim
- Sparse graph → Kruskal

**Need to order nodes?**
- DAG → Topological sort
- Find cycles → DFS with colors (directed) or parent tracking (undirected)

**Need to group nodes?**
- Connected components → BFS/DFS
- Strongly connected → Tarjan/Kosaraju
- Bipartite → 2-coloring
