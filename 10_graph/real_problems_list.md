# Graph Algorithms - Real Competitive Programming Problems

## LeetCode Hard Problems

### 1. Word Ladder II (LeetCode 126) ⭐⭐⭐
- **Topic**: BFS, Graph Construction, DFS
- **Difficulty**: Hard
- **Time Complexity**: O(N*L² + paths)
- **Key Technique**: Build graph first, then find all shortest paths
- **Tip**: Use BFS to find distances, then DFS to reconstruct all paths

### 2. Alien Dictionary (LeetCode 269) ⭐⭐⭐
- **Topic**: Topological Sort, Graph Building
- **Difficulty**: Hard
- **Time Complexity**: O(N*L + V + E)
- **Key Technique**: Extract ordering from word pairs, topological sort
- **Tip**: Compare adjacent words character by character

### 3. Critical Connections in Network (LeetCode 1192) ⭐⭐⭐
- **Topic**: Bridge Finding, DFS
- **Difficulty**: Hard
- **Time Complexity**: O(V + E)
- **Key Technique**: Find bridges using discovery and low times
- **Tip**: A bridge is an edge (u,v) where low[v] > disc[u]

### 4. Minimum Cost to Make at Least One Valid Path (LeetCode 1368) ⭐⭐⭐
- **Topic**: Dijkstra, 0-1 BFS
- **Difficulty**: Hard
- **Time Complexity**: O(m*n)
- **Key Technique**: 0-1 BFS with weight 0 for same direction, 1 for change
- **Tip**: Use deque instead of priority queue for efficiency

### 5. Bus Routes (LeetCode 815) ⭐⭐⭐
- **Topic**: BFS, Graph Building
- **Difficulty**: Hard
- **Time Complexity**: O(N*S)
- **Key Technique**: Build graph where nodes are buses, edges connect buses sharing stops
- **Tip**: Start from all buses containing start stop

### 6. Regions Cut By Slashes (LeetCode 959) ⭐⭐⭐
- **Topic**: Union-Find, Grid Problem
- **Difficulty**: Hard
- **Time Complexity**: O(n² * α(n²))
- **Key Technique**: Divide each cell into 4 triangles, use Union-Find
- **Tip**: Can be solved with Union-Find or DFS on expanded grid

### 7. Maximum Network Rank (LeetCode 1761) ⭐⭐⭐
- **Topic**: Graph, Connectivity
- **Difficulty**: Hard
- **Time Complexity**: O(n²)
- **Key Technique**: Count degrees and handle special case of connected nodes
- **Tip**: Rank = degree[u] + degree[v] - (1 if connected else 0)

### 8. Minimum Edge Reversals to Make a Graph Strongly Connected (Hard) ⭐⭐⭐
- **Topic**: SCC, Graph Reconstruction
- **Difficulty**: Hard
- **Time Technique**: Find SCCs, build meta-graph, minimum reversals
- **Tip**: Need to reverse edges to connect SCCs into one

---

## Codeforces Problems

### 9. Codeforces 1097C: Yuhao and a Parenthesis ⭐⭐
- **Topic**: Graph, Matching
- **Difficulty**: Div2 C
- **Key Insight**: Match parentheses, build graph of constraints

### 10. Codeforces 1101C: Sсhool Merging ⭐⭐⭐
- **Topic**: Graph, MST, Kruskal
- **Difficulty**: Div2 D
- **Key Insight**: Merge schools with minimum cost using MST

### 11. Codeforces 1182D: Additive Combinations ⭐⭐⭐
- **Topic**: Graph, BFS, Shortest Path
- **Difficulty**: Div2 D
- **Key Insight**: Model problem as graph, find shortest paths

### 12. Codeforces 427C: Checkposts ⭐⭐
- **Topic**: SCC, Tarjan's Algorithm
- **Difficulty**: Div2 C
- **Key Insight**: Find SCCs, compute minimum cost for each SCC

---

## AtCoder Problems

### 13. AtCoder ABC 145 F: Unification ⭐⭐
- **Topic**: Graph, Minimum Spanning Tree
- **Difficulty**: AtCoder F
- **Key Insight**: Make all numbers equal with minimum cost using MST

### 14. AtCoder ABC 216 F: Max Sum + **⭐⭐
- **Topic**: Topological Sort, Dynamic Programming
- **Difficulty**: AtCoder F
- **Key Insight**: Use topological sort on DAG for DP

---

## Problem Solving Patterns

### Pattern 1: Convert Text Problem to Graph
**Example**: Word Ladder
```
Words = ["hot", "dot", "dog", "lot", "log"]
→ Build graph where edge exists if words differ by 1 letter
→ BFS for shortest path
```

### Pattern 2: Extract Ordering from Constraints
**Example**: Alien Dictionary
```
Input: ["wrt", "wrf", "er", "ett", "rftt"]
→ Extract constraints: w→e, r→t, t→f
→ Topological sort to get order
```

### Pattern 3: Find Critical Edges
**Example**: Critical Connections
```
→ Find bridges (edges whose removal disconnects graph)
→ Use DFS with discovery and low times
```

### Pattern 4: Minimize Cost in Graph
**Example**: Cheapest Flights
```
→ Use Dijkstra or Bellman-Ford
→ Add constraint on number of hops
→ Use modified Bellman-Ford
```

### Pattern 5: Group Connected Elements
**Example**: Number of Islands
```
→ Count connected components
→ Use BFS/DFS or Union-Find
```

---

## Advanced Techniques

### 1. Bridge Finding
```cpp
// Find all bridges in graph
// A bridge (u,v) has low[v] > disc[u]
vector<pair<int,int>> findBridges(vector<vector<int>>& adj) {
    // Implementation using DFS with discovery and low times
}
```

### 2. Articulation Points
```cpp
// Find cut vertices
// A vertex u is articulation point if low[v] >= disc[u] for child v
vector<int> findArticulationPoints(vector<vector<int>>& adj) {
    // Implementation
}
```

### 3. 2-SAT Problem
```cpp
// Solve boolean satisfiability using graph
// Build implication graph for 2-CNF
// Find SCCs to determine satisfiability
```

### 4. Bipartite Matching
```cpp
// Maximum matching in bipartite graph
// Use DFS with augmenting paths
// Hungarian algorithm for weighted
```

### 5. Network Flow
```cpp
// Maximum flow from source to sink
// Ford-Fulkerson, Dinic's, Push-Relabel algorithms
// Min-cut max-flow theorem
```

---

## Problem Classification by Topic

### BFS-Based (Level-order, Shortest Path)
- Word Ladder, Number of Islands, Shortest Path in Binary Matrix
- All Cells In Order, Surrounded Regions

### DFS-Based (Connectivity, Ordering)
- Number of Connected Components, Course Schedule
- Accounts Merge, Path to Tree Root

### Dijkstra/Bellman (Weighted Paths)
- Network Delay Time, Cheapest Flights Within K Stops
- Path With Minimum Effort

### MST (Kruskal/Prim)
- Min Cost to Connect All Points, Connecting Cities
- Minimum Spanning Tree

### Topological Sort (DAG)
- Course Schedule II, Alien Dictionary
- Task Scheduling, Build Array From Permutation

### Advanced (SCC, Bridges, Bipartite)
- Critical Connections, Accounts Merge (Union-Find)
- Graph Bipartite, Possible Bipartition

---

## Tips for Contest

1. **Read carefully**: Understand if graph is directed/undirected, weighted/unweighted
2. **Check constraints**: Determines which algorithm to use
3. **Start simple**: Implement basic algorithm first, optimize if needed
4. **Test edge cases**: Empty, single node, disconnected components
5. **Use templates**: Have standard implementations ready
6. **Debug systematically**: Print adjacency list, trace algorithm step-by-step
7. **Optimize I/O**: Use `ios_base::sync_with_stdio(false)` for large inputs

---

## Reading List

1. Competitive Programmer's Handbook - Chapter on Graphs
2. CLRS - Chapter on Graph Algorithms
3. Codeforces Blog: Graph Theory Techniques
4. GeeksforGeeks - All Graph Articles
5. YouTube: William Fiset - Graph Algorithms Playlist
