# Graph Algorithm Practice Problems

## Difficulty Levels
- ⭐ Easy (1-2)
- ⭐⭐ Medium (3-5)
- ⭐⭐⭐ Hard (6+)

---

## Traversal Problems

### 1. Number of Islands ⭐⭐
- **Platforms**: LeetCode 200, HackerRank
- **Topics**: BFS/DFS, Connected Components
- **Description**: Find the number of islands in a 2D grid
- **Key Insight**: Mark visited cells to avoid recounting
- **Time Complexity**: O(m*n)

### 2. All Paths From Source to Target ⭐
- **Platforms**: LeetCode 797
- **Topics**: DFS, Backtracking
- **Description**: Find all paths from source to target in a DAG
- **Key Insight**: Use DFS with path reconstruction
- **Time Complexity**: O(2^n * n)

### 3. Clone Graph ⭐⭐
- **Platforms**: LeetCode 133
- **Topics**: BFS/DFS, Graph Cloning
- **Description**: Create a deep copy of an undirected graph
- **Key Insight**: Use hashmap to track visited nodes and their copies
- **Time Complexity**: O(V + E)

### 4. Surrounded Regions ⭐⭐
- **Platforms**: LeetCode 130
- **Topics**: DFS/BFS, Connected Components
- **Description**: Mark regions surrounded by 'X' with 'O'
- **Key Insight**: Start from boundaries and mark connected Os
- **Time Complexity**: O(m*n)

---

## Shortest Path Problems

### 5. Shortest Path in Binary Matrix ⭐⭐
- **Platforms**: LeetCode 1091
- **Topics**: BFS, 0-1 Graph
- **Description**: Find shortest path from top-left to bottom-right in binary matrix
- **Key Insight**: All edges have weight 1, use BFS
- **Time Complexity**: O(m*n)

### 6. Network Delay Time ⭐⭐
- **Platforms**: LeetCode 743
- **Topics**: Dijkstra's Algorithm
- **Description**: Find minimum time for signal to reach all nodes
- **Key Insight**: Single-source shortest path problem
- **Time Complexity**: O((V + E) log V)

### 7. Cheapest Flights Within K Stops ⭐⭐
- **Platforms**: LeetCode 787
- **Topics**: Bellman-Ford, DP
- **Description**: Find cheapest flight with at most K stops
- **Key Insight**: Modified Bellman-Ford with constraint on number of edges
- **Time Complexity**: O(K * E)

### 8. Word Ladder II ⭐⭐⭐
- **Platforms**: LeetCode 126
- **Topics**: BFS, Graph Construction, Backtracking
- **Description**: Find all shortest paths between two words
- **Key Insight**: Build graph then find all shortest paths via BFS+DFS
- **Time Complexity**: O(V + E) for BFS + O(paths) for backtracking

### 9. Path With Minimum Effort ⭐⭐
- **Platforms**: LeetCode 1631
- **Topics**: Dijkstra's Algorithm, 2D Grid
- **Description**: Find path with minimum maximum absolute difference
- **Key Insight**: Dijkstra with effort as weight
- **Time Complexity**: O(m*n log(m*n))

### 10. Floyd-Warshall Problems ⭐⭐⭐
- **Platforms**: Various
- **Topics**: All-Pairs Shortest Path
- **Description**: Find shortest paths between all pairs
- **Key Insight**: O(n³) DP solution good for small n
- **Time Complexity**: O(V³)

---

## Minimum Spanning Tree Problems

### 11. Minimum Spanning Tree ⭐⭐
- **Platforms**: LeetCode 1584
- **Topics**: Kruskal's, Union-Find
- **Description**: Find MST of a weighted undirected graph
- **Key Insight**: Sort edges by weight and use Union-Find
- **Time Complexity**: O(E log E)

### 12. Connect All Points ⭐⭐
- **Platforms**: LeetCode 1584
- **Topics**: Kruskal's Algorithm, Prim's Algorithm
- **Description**: Minimum cost to connect all points
- **Key Insight**: Create complete graph and find MST
- **Time Complexity**: O(n² log n)

### 13. Connecting Cities With Minimum Cost ⭐⭐
- **Platforms**: LeetCode 1135
- **Topics**: Kruskal's, Union-Find
- **Description**: Connect cities with minimum total cost
- **Key Insight**: Standard MST problem
- **Time Complexity**: O(E log E)

---

## Topological Sort Problems

### 14. Course Schedule ⭐
- **Platforms**: LeetCode 207
- **Topics**: Topological Sort, Cycle Detection
- **Description**: Determine if all courses can be completed
- **Key Insight**: Detect cycle in directed graph
- **Time Complexity**: O(V + E)

### 15. Course Schedule II ⭐⭐
- **Platforms**: LeetCode 210
- **Topics**: Topological Sort
- **Description**: Return valid ordering of courses
- **Key Insight**: Topological sort (Kahn's or DFS)
- **Time Complexity**: O(V + E)

### 16. Alien Dictionary ⭐⭐⭐
- **Platforms**: LeetCode 269
- **Topics**: Topological Sort, Graph Construction
- **Description**: Derive dictionary order from alien language
- **Key Insight**: Build graph from words then do topological sort
- **Time Complexity**: O(N*L + V + E)

### 17. Task Scheduling Order ⭐⭐
- **Platforms**: Various
- **Topics**: Topological Sort
- **Description**: Schedule tasks respecting dependencies
- **Key Insight**: Use topological sort with Kahn's algorithm
- **Time Complexity**: O(V + E)

---

## Cycle Detection Problems

### 18. Detect Cycle in Undirected Graph ⭐
- **Platforms**: GeeksforGeeks, LeetCode 261
- **Topics**: DFS, Union-Find
- **Description**: Check if undirected graph has cycle
- **Key Insight**: Use DFS with parent tracking or Union-Find
- **Time Complexity**: O(V + E)

### 19. Detect Cycle in Directed Graph ⭐⭐
- **Platforms**: GeeksforGeeks, LeetCode
- **Topics**: DFS with Colors, Topological Sort
- **Description**: Check if directed graph has cycle
- **Key Insight**: Use color-based DFS (white/gray/black)
- **Time Complexity**: O(V + E)

### 20. Redundant Connection ⭐⭐
- **Platforms**: LeetCode 684
- **Topics**: Union-Find
- **Description**: Find redundant edge creating cycle
- **Key Insight**: Use Union-Find to detect when edge creates cycle
- **Time Complexity**: O(E * α(V))

---

## Connected Components Problems

### 21. Number of Connected Components ⭐
- **Platforms**: LeetCode 323
- **Topics**: BFS/DFS, Union-Find
- **Description**: Count connected components in undirected graph
- **Key Insight**: Multiple BFS/DFS from unvisited nodes
- **Time Complexity**: O(V + E)

### 22. Friend Circles ⭐⭐
- **Platforms**: LeetCode 547
- **Topics**: DFS/BFS, Union-Find
- **Description**: Find number of friend circles (friend groups)
- **Key Insight**: Connected components in adjacency matrix
- **Time Complexity**: O(n²)

---

## Bipartite Graph Problems

### 23. Is Graph Bipartite? ⭐⭐
- **Platforms**: LeetCode 785
- **Topics**: Graph Coloring, BFS/DFS
- **Description**: Check if graph is bipartite
- **Key Insight**: Try 2-coloring with BFS
- **Time Complexity**: O(V + E)

### 24. Possible Bipartition ⭐⭐
- **Platforms**: LeetCode 886
- **Topics**: Graph Bipartition
- **Description**: Group into two groups with constraints
- **Key Insight**: Build conflict graph and check if bipartite
- **Time Complexity**: O(V + E)

---

## Advanced Problems

### 25. Strongly Connected Components ⭐⭐⭐
- **Platforms**: GeeksforGeeks, CodeSignal
- **Topics**: Tarjan's Algorithm, Kosaraju's Algorithm
- **Description**: Find all SCCs in directed graph
- **Key Insight**: Use Tarjan's or Kosaraju's algorithm
- **Time Complexity**: O(V + E)

### 26. Critical Connections in Network ⭐⭐⭐
- **Platforms**: LeetCode 1192
- **Topics**: Bridge Finding, DFS
- **Description**: Find critical connections (bridges)
- **Key Insight**: Find bridges using DFS with discovery/low times
- **Time Complexity**: O(V + E)

### 27. Accounts Merge ⭐⭐
- **Platforms**: LeetCode 721
- **Topics**: Union-Find, DFS
- **Description**: Merge accounts with common emails
- **Key Insight**: Union-Find to group emails, then reconstruct
- **Time Complexity**: O(N log N)

### 28. Graph Valid Tree ⭐⭐
- **Platforms**: LeetCode 261
- **Topics**: DFS/BFS, Connected Components, Cycle Detection
- **Description**: Check if graph forms a valid tree
- **Key Insight**: n-1 edges, no cycle, connected
- **Time Complexity**: O(V + E)

### 29. Regions Cut By Slashes ⭐⭐⭐
- **Platforms**: LeetCode 959
- **Topics**: Union-Find, Grid Problem
- **Description**: Count connected regions in divided grid
- **Key Insight**: Divide each cell into 4 parts and use Union-Find
- **Time Complexity**: O(n²)

### 30. Minimum Height Trees ⭐⭐
- **Platforms**: LeetCode 310
- **Topics**: Graph, Topological Sort, BFS
- **Description**: Find nodes forming minimum height trees
- **Key Insight**: Topological sort from leaves inward
- **Time Complexity**: O(V + E)

---

## Template Problems

### 31. Build Graph from List ⭐
```cpp
vector<vector<int>> buildGraph(vector<pair<int,int>>& edges, int n) {
    vector<vector<int>> adj(n);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
```

### 32. Count Connected Components ⭐
```cpp
int countComponents(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            // BFS/DFS
        }
    }
    return count;
}
```

---

## Study Plan

### Week 1: Basics
- Problems: 1, 2, 5, 21
- Topics: BFS, DFS, basic traversal

### Week 2: Shortest Path
- Problems: 6, 7, 9, 10
- Topics: Dijkstra, Bellman-Ford

### Week 3: MST & Sorting
- Problems: 11, 12, 13, 20
- Topics: Kruskal, Prim, Union-Find

### Week 4: Advanced
- Problems: 14, 15, 25, 26, 27
- Topics: Topological sort, Bridges, SCCs

---

## Useful Resources
- GeeksforGeeks Graph Algorithms
- LeetCode Graph Tag Problems
- Competitive Programmer's Handbook
- Codeforces Graph Tutorials
