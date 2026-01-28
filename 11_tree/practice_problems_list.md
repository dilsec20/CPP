# Tree Algorithm Practice Problems

## Difficulty Levels
- ⭐ Easy (1-2)
- ⭐⭐ Medium (3-5)
- ⭐⭐⭐ Hard (6+)

---

## Traversal Problems

### 1. Binary Tree Traversal ⭐
- **Platforms**: LeetCode 94, 144, 145
- **Topics**: Inorder, Preorder, Postorder
- **Description**: Implement all three tree traversal methods
- **Key Insight**: Recursive simple, iterative uses stack
- **Time Complexity**: O(n)

### 2. Level Order Traversal ⭐
- **Platforms**: LeetCode 102, 107
- **Topics**: BFS, Level Order
- **Description**: Traverse tree level by level
- **Key Insight**: Use queue, process level by level
- **Time Complexity**: O(n)

### 3. Vertical Order Traversal ⭐⭐
- **Platforms**: LeetCode 987
- **Topics**: BFS, Coordinate Tracking
- **Description**: Traverse by vertical columns
- **Key Insight**: Track column coordinates with BFS
- **Time Complexity**: O(n log n)

### 4. Right View of Tree ⭐⭐
- **Platforms**: LeetCode 199
- **Topics**: BFS/DFS, Level Order
- **Description**: Get rightmost node at each level
- **Key Insight**: Process last node in each level or use DFS
- **Time Complexity**: O(n)

---

## Path Problems

### 5. Path Sum ⭐
- **Platforms**: LeetCode 112
- **Topics**: DFS, Recursion
- **Description**: Check if root-to-leaf path sum equals target
- **Key Insight**: Subtract node value, check at leaf
- **Time Complexity**: O(n)

### 6. Path Sum II ⭐⭐
- **Platforms**: LeetCode 113
- **Topics**: DFS, Backtracking
- **Description**: Find all root-to-leaf paths with target sum
- **Key Insight**: Use backtracking to reconstruct paths
- **Time Complexity**: O(n * h)

### 7. Binary Tree Maximum Path Sum ⭐⭐⭐
- **Platforms**: LeetCode 124
- **Topics**: DFS, Tree DP
- **Description**: Find max path sum (any path)
- **Key Insight**: Max through each node = node + max left + max right
- **Time Complexity**: O(n)

### 8. Path In Zigzag Labelled Binary Tree ⭐⭐
- **Platforms**: LeetCode 1104
- **Topics**: Tree Navigation
- **Description**: Find path in complete tree with zigzag labels
- **Key Insight**: Use parent formula for complete tree
- **Time Complexity**: O(log n)

---

## Lowest Common Ancestor

### 9. Lowest Common Ancestor of Binary Tree ⭐⭐
- **Platforms**: LeetCode 236
- **Topics**: DFS, LCA
- **Description**: Find LCA of two nodes
- **Key Insight**: Recursive: if both in subtrees, return root
- **Time Complexity**: O(n)

### 10. Lowest Common Ancestor of BST ⭐
- **Platforms**: LeetCode 235
- **Topics**: BST, LCA
- **Description**: Find LCA in BST
- **Key Insight**: Use BST property for faster traversal
- **Time Complexity**: O(h)

### 11. Lowest Common Ancestor with Parent Pointers ⭐⭐
- **Platforms**: LeetCode 1257
- **Topics**: Hash Set, Parent Pointers
- **Description**: Find LCA when parent pointers available
- **Key Insight**: Record all ancestors, match with other path
- **Time Complexity**: O(h)

### 12. Kth Ancestor of Tree Node ⭐⭐
- **Platforms**: LeetCode 1483
- **Topics**: Preprocessing, Binary Lifting
- **Description**: Find kth ancestor of node
- **Key Insight**: Binary lifting for O(log n) queries
- **Time Complexity**: O(n log n) preprocessing, O(log n) query

---

## BST Problems

### 13. Validate Binary Search Tree ⭐
- **Platforms**: LeetCode 98
- **Topics**: BST, Validation
- **Description**: Check if tree is valid BST
- **Key Insight**: Track min/max values for each node
- **Time Complexity**: O(n)

### 14. Binary Search Tree Iterator ⭐⭐
- **Platforms**: LeetCode 173
- **Topics**: BST, Stack
- **Description**: Implement iterator for BST
- **Key Insight**: Use stack for inorder traversal
- **Time Complexity**: O(1) amortized

### 15. Recover Binary Search Tree ⭐⭐⭐
- **Platforms**: LeetCode 99
- **Topics**: BST, Inorder Traversal
- **Description**: Fix BST with two swapped nodes
- **Key Insight**: Find violations in inorder, swap
- **Time Complexity**: O(n)

### 16. Range Sum of BST ⭐
- **Platforms**: LeetCode 938
- **Topics**: BST, Recursion
- **Description**: Sum all nodes in range [low, high]
- **Key Insight**: Use BST property to prune
- **Time Complexity**: O(n)

---

## Subtree Problems

### 17. Subtree of Another Tree ⭐
- **Platforms**: LeetCode 572
- **Topics**: Tree Comparison
- **Description**: Check if tree is subtree of another
- **Key Insight**: Compare structures recursively
- **Time Complexity**: O(m * n)

### 18. Count Univalue Subtrees ⭐⭐
- **Platforms**: LeetCode 250
- **Topics**: DFS, Postorder
- **Description**: Count subtrees with all same value
- **Key Insight**: Postorder to check before counting
- **Time Complexity**: O(n)

### 19. Most Frequent Subtree Sum ⭐⭐
- **Platforms**: LeetCode 508
- **Topics**: DFS, Hash Map
- **Description**: Find most frequent subtree sum
- **Key Insight**: Postorder to calculate sums
- **Time Complexity**: O(n)

---

## Construction Problems

### 20. Construct Binary Tree from Preorder/Inorder ⭐⭐
- **Platforms**: LeetCode 105
- **Topics**: Recursion, Hash Map
- **Description**: Build tree from traversals
- **Key Insight**: Find root in inorder, split arrays
- **Time Complexity**: O(n)

### 21. Construct Binary Tree from Postorder/Inorder ⭐⭐
- **Platforms**: LeetCode 106
- **Topics**: Recursion
- **Description**: Build tree from post and inorder
- **Key Insight**: Root is last in postorder
- **Time Complexity**: O(n)

### 22. Serialize and Deserialize Tree ⭐⭐⭐
- **Platforms**: LeetCode 297
- **Topics**: DFS, String Processing
- **Description**: Convert tree to/from string
- **Key Insight**: Use marker for null, preorder traversal
- **Time Complexity**: O(n)

---

## Tree Modification

### 23. Flatten Binary Tree to Linked List ⭐⭐
- **Platforms**: LeetCode 114
- **Topics**: DFS, Recursion
- **Description**: Flatten tree to right-skewed linked list
- **Key Insight**: Postorder to process bottom-up
- **Time Complexity**: O(n)

### 24. Trim Binary Search Tree ⭐
- **Platforms**: LeetCode 669
- **Topics**: BST, Recursion
- **Description**: Trim BST to nodes in range
- **Key Insight**: Use BST property to decide pruning
- **Time Complexity**: O(h)

### 25. Invert Binary Tree ⭐
- **Platforms**: LeetCode 226
- **Topics**: DFS, Recursion
- **Description**: Mirror the tree
- **Key Insight**: Swap left and right at each node
- **Time Complexity**: O(n)

---

## Special Trees

### 26. House Robber III ⭐⭐
- **Platforms**: LeetCode 337
- **Topics**: Tree DP
- **Description**: Rob houses in tree (no adjacent)
- **Key Insight**: DP with two states: rob or not rob
- **Time Complexity**: O(n)

### 27. Populating Next Right Pointers ⭐⭐
- **Platforms**: LeetCode 116, 117
- **Topics**: BFS, Level Order
- **Description**: Connect nodes at same level
- **Key Insight**: BFS or constant space with pointers
- **Time Complexity**: O(n)

### 28. Binary Tree Cameras ⭐⭐⭐
- **Platforms**: LeetCode 968
- **Topics**: Greedy, Tree DP
- **Description**: Minimum cameras to monitor all nodes
- **Key Insight**: Greedy with states: monitored, unmonitored, has camera
- **Time Complexity**: O(n)

---

## Balanced Tree Problems

### 29. Balanced Binary Tree ⭐
- **Platforms**: LeetCode 110
- **Topics**: Recursion, Balance Check
- **Description**: Check if tree is balanced
- **Key Insight**: Check height difference at each node
- **Time Complexity**: O(n)

### 30. AVL Tree Insertion ⭐⭐⭐
- **Platforms**: GeeksforGeeks
- **Topics**: AVL Trees, Rotations
- **Description**: Insert with rotations
- **Key Insight**: Maintain balance with rotations
- **Time Complexity**: O(log n)

---

## Distance & Diameter

### 31. Diameter of Binary Tree ⭐
- **Platforms**: LeetCode 543
- **Topics**: DFS, Recursion
- **Description**: Longest path between any nodes
- **Key Insight**: Max = max left height + right height
- **Time Complexity**: O(n)

### 32. All Nodes Distance K ⭐⭐
- **Platforms**: LeetCode 863
- **Topics**: Graph, DFS, BFS
- **Description**: Find all nodes at distance K
- **Key Insight**: Convert to graph with parent pointers
- **Time Complexity**: O(n)

---

## Study Plan

### Week 1: Basics
- Problems: 1, 2, 4, 13, 25
- Topics: Traversal, BST, Basic operations

### Week 2: Paths & Construction
- Problems: 5, 6, 20, 21, 22
- Topics: Path problems, tree construction

### Week 3: Advanced
- Problems: 7, 9, 15, 26, 31
- Topics: Tree DP, LCA, complex traversals

### Week 4: Optimization
- Problems: 12, 23, 27, 28, 30
- Topics: Advanced techniques, special cases

---

## Useful Resources
- LeetCode Tree Tag
- GeeksforGeeks Tree Articles
- NeetCode Tree Problems
- YouTube: Abdul Bari Tree Algorithms
