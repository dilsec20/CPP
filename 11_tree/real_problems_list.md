# Tree Algorithms - Real Competitive Programming Problems

## LeetCode Hard Problems

### 1. Binary Tree Maximum Path Sum (LeetCode 124) ⭐⭐⭐
- **Topic**: Tree DP, Recursion
- **Difficulty**: Hard
- **Time Complexity**: O(n)
- **Key Technique**: Return max from node, track global max
- **Tip**: Max through node = node + max(0, left) + max(0, right)

### 2. Serialize and Deserialize Binary Tree (LeetCode 297) ⭐⭐⭐
- **Topic**: DFS, String Processing
- **Difficulty**: Hard
- **Time Complexity**: O(n)
- **Key Technique**: Use markers for null, reconstruct via queue
- **Tip**: Can use different delimiters, preorder traversal works

### 3. Recover Binary Search Tree (LeetCode 99) ⭐⭐⭐
- **Topic**: BST, Inorder Traversal
- **Difficulty**: Hard
- **Time Complexity**: O(n)
- **Key Technique**: Find violations in inorder sequence, swap nodes
- **Tip**: Two cases: adjacent nodes or far apart

### 4. Binary Tree Cameras (LeetCode 968) ⭐⭐⭐
- **Topic**: Greedy, Tree DP
- **Difficulty**: Hard
- **Time Complexity**: O(n)
- **Key Technique**: Greedy from leaves up, three states
- **Tip**: States: monitored, unmonitored, has camera

### 5. Largest BST Subtree (LeetCode 333) ⭐⭐⭐
- **Topic**: BST, DFS
- **Difficulty**: Hard
- **Time Complexity**: O(n)
- **Key Technique**: For each node, check if subtree is BST
- **Tip**: Return {isBST, size, min, max}

### 6. Binary Tree Vertical Order Traversal (LeetCode 314) ⭐⭐⭐
- **Topic**: BFS, Coordinate Tracking
- **Difficulty**: Hard
- **Time Complexity**: O(n log n)
- **Key Technique**: Track column indices with BFS
- **Tip**: Handle multiple nodes at same (col, row)

### 7. All Nodes Distance K in Binary Tree (LeetCode 863) ⭐⭐⭐
- **Topic**: Graph Conversion, BFS
- **Difficulty**: Hard
- **Time Complexity**: O(n)
- **Key Technique**: Add parent pointers, treat as undirected graph
- **Tip**: Can go up, left, or right from any node

### 8. Smallest Subtree with all Deepest Nodes (LeetCode 865) ⭐⭐⭐
- **Topic**: DFS, Recursion
- **Difficulty**: Hard
- **Time Complexity**: O(n)
- **Key Technique**: Track height, find common ancestor
- **Tip**: Return node where deepest differ in height

---

## Codeforces Tree Problems

### 9. Codeforces 1104C: Sсhool Merging ⭐⭐
- **Topic**: Tree DP, Greedy
- **Difficulty**: Div2 D
- **Key Insight**: Minimum edges to connect tree

### 10. Codeforces 337D: Tree Construction ⭐⭐⭐
- **Topic**: Binary Tree, Construction
- **Difficulty**: Div1 B
- **Key Insight**: Build tree with specific properties

### 11. Codeforces 431E: Chemistry in Berland ⭐⭐⭐
- **Topic**: Tree DP, Matching
- **Difficulty**: Div1 C
- **Key Insight**: Tree matching with constraints

---

## AtCoder Tree Problems

### 12. AtCoder ABC 192 F: Potion ⭐⭐
- **Topic**: Tree DP, Knapsack
- **Difficulty**: AtCoder F
- **Key Insight**: DP on tree structure

### 13. AtCoder ARC 109 D: Kakapo ⭐⭐
- **Topic**: Tree, Recursion
- **Difficulty**: AtCoder D
- **Key Insight**: Tree traversal with constraints

---

## Problem Solving Patterns

### Pattern 1: Path Finding
**Example**: Binary Tree Maximum Path Sum
```
→ DFS from each node
→ Track max path through node
→ Return max path going down
```

### Pattern 2: Reconstruction
**Example**: Serialize and Deserialize
```
→ Serialize: Preorder traversal with nulls
→ Deserialize: Queue-based reconstruction
```

### Pattern 3: Property Checking
**Example**: Recover BST
```
→ Do inorder traversal
→ Find violations
→ Fix by swapping
```

### Pattern 4: Subtree Problems
**Example**: Largest BST Subtree
```
→ Check each subtree
→ Track BST properties (min, max, size)
→ Return largest valid
```

### Pattern 5: Graph Conversion
**Example**: All Nodes Distance K
```
→ Add parent pointers to tree
→ Treat as undirected graph
→ BFS from target
```

---

## Advanced Techniques

### 1. Tree Hashing
```cpp
// Hash each subtree for comparison
map<vector<int>, int> hashMap;
int dfsHash(TreeNode* root) {
    if (!root) return 0;
    vector<int> signature = {dfsHash(root->left), root->val, dfsHash(root->right)};
    return hashMap[signature]++;
}
```

### 2. Heavy-Light Decomposition
```cpp
// Decompose tree into paths for efficient queries
// Advanced technique for competitive programming
```

### 3. Centroid Decomposition
```cpp
// Divide tree into subtrees with balanced centroids
// Used for complex tree problems
```

### 4. Binary Lifting (LCA with Preprocessing)
```cpp
// Preprocess ancestors for fast LCA queries
// O(n log n) preprocessing, O(log n) queries
```

### 5. Tree DP with Multiple Passes
```cpp
// First pass: compute bottom-up
// Second pass: compute top-down
// Useful for rerooting problems
```

---

## Problem Classification

### Path Problems
- Maximum Path Sum, Path Sum I/II/III
- All Paths, Count Paths

### Construction Problems
- Build from traversals, Serialize/Deserialize
- Flatten, Reconstruct

### Property Problems
- Height, Diameter, Balance, Symmetry
- BST Validation, Complete Check

### Subtree Problems
- Subtree sum, count, max/min
- Largest BST subtree

### Advanced
- LCA variants, Distance K
- Tree Cameras, House Robber III

---

## Performance Tips

1. **Avoid Redundant Computation**: Cache results
2. **Early Termination**: Stop traversal if answer found
3. **Space Optimization**: Iterative > recursive for large trees
4. **Pruning**: Skip subtrees that can't contribute
5. **Preprocessing**: Build maps, hashes upfront

---

## Testing Strategy

1. **Small Trees**: 1-3 nodes, test edge cases
2. **Balanced Trees**: Test properties
3. **Skewed Trees**: Height = n, test recursion depth
4. **Complete Trees**: All levels filled
5. **BSTs**: Valid and invalid cases

---

## Common Pitfalls

1. **Tree vs Graph**: Not treating as undirected when parent pointers exist
2. **Integer Overflow**: Large sums without long long
3. **Null Handling**: Forgetting null checks in recursion
4. **Depth Limits**: Stack overflow on deep recursion
5. **Memory Leaks**: Not deleting allocated nodes
6. **Off-by-one**: Level counting errors
7. **Comparison**: Wrong operators in BST comparisons

---

## Useful Resources

- LeetCode Tree Tag (150+ problems)
- GeeksforGeeks Tree Articles
- NeetCode Tree Playlist
- Competitive Programmer's Handbook - Trees
- Codeforces Blogs on Tree DP

---

## Contest Checklist

- [ ] Draw tree diagram
- [ ] Identify tree type (BST, complete, etc.)
- [ ] Choose traversal method
- [ ] Write base cases first
- [ ] Handle null checks
- [ ] Test with small examples
- [ ] Check memory/time limits
- [ ] Verify with skewed cases

