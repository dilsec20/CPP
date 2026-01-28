# Dynamic Programming Practice Problems

## Organized by DP Type

---

## DP on Array (⭐⭐)

### 1. Maximum Subarray Sum (Kadane's Algorithm)
- **LeetCode**: 53
- **Dry Run**: [-2, 1, -3, 4, -1, 2, 1, -5, 4] → 6 (subarray [4, -1, 2, 1])
- **Time**: O(n) | **Space**: O(n)

### 2. Longest Increasing Subsequence
- **LeetCode**: 300
- **Dry Run**: [10, 9, 2, 5, 3, 7, 101, 18] → 4 ([2, 3, 7, 101])
- **Time**: O(n²) or O(n log n) | **Space**: O(n)

### 3. Maximum Product Subarray
- **LeetCode**: 152
- **Dry Run**: [2, 3, -2, 4] → 6 (subarray [2, 3])
- **Time**: O(n) | **Space**: O(n)

### 4. Jump Game
- **LeetCode**: 55, 45
- **Dry Run**: [2, 3, 1, 1, 4] → Can reach last index
- **Time**: O(n) | **Space**: O(1)

### 5. Best Time to Buy and Sell Stock
- **LeetCode**: 121, 122, 123
- **Dry Run**: [7, 1, 5, 3, 6, 4] → 5 (buy at 1, sell at 6)
- **Time**: O(n) | **Space**: O(1)

### 6. Decode Ways
- **LeetCode**: 91
- **Dry Run**: "226" → 3 (2-2-6, 22-6, 2-26)
- **Time**: O(n) | **Space**: O(n)

### 7. Climbing Stairs
- **LeetCode**: 70
- **Dry Run**: n=5 → 8 ways
- **Time**: O(n) | **Space**: O(n)

### 8. House Robber
- **LeetCode**: 198, 213
- **Dry Run**: [5, 3, 4, 11] → 16 (rob 5 and 11)
- **Time**: O(n) | **Space**: O(1)

---

## DP on Grid (⭐⭐)

### 9. Unique Paths
- **LeetCode**: 62, 63
- **Dry Run**: 3x7 grid → 28 paths
- **Time**: O(m*n) | **Space**: O(m*n)

### 10. Minimum Path Sum
- **LeetCode**: 64
- **Dry Run**: [[1,3,1],[1,5,1],[4,2,1]] → 7
- **Time**: O(m*n) | **Space**: O(m*n)

### 11. Dungeon Game
- **LeetCode**: 174
- **Dry Run**: [[-3, 5], [-1, -2]] → 7 HP needed
- **Time**: O(m*n) | **Space**: O(m*n)

### 12. Cherry Pickup
- **LeetCode**: 741
- **Dry Run**: 2D grid with cherries → max cherries collected
- **Time**: O(n³) | **Space**: O(n²)

### 13. Number of Ways to Reach Destination
- **LeetCode**: Various
- **Dry Run**: mxn grid → count paths
- **Time**: O(m*n) | **Space**: O(m*n)

---

## Knapsack DP (⭐⭐⭐)

### 14. 0/1 Knapsack
- **Source**: GeeksforGeeks
- **Dry Run**: weights=[2,3,4], values=[3,4,5], capacity=5 → 7
- **Time**: O(n*W) | **Space**: O(n*W)

### 15. Unbounded Knapsack
- **Source**: GeeksforGeeks
- **Dry Run**: Each item can be used multiple times
- **Time**: O(n*W) | **Space**: O(W)

### 16. Coin Change
- **LeetCode**: 322, 518
- **Dry Run**: [1,2,5], amount=5 → 1 coin (5)
- **Time**: O(amount*n) | **Space**: O(amount)

### 17. Partition Equal Subset Sum
- **LeetCode**: 416
- **Dry Run**: [1,5,11,5] → True (11 = 1+5+5)
- **Time**: O(n*sum) | **Space**: O(sum)

### 18. Target Sum
- **LeetCode**: 494
- **Dry Run**: [1,1,1,1,1], target=3 → 5 ways
- **Time**: O(n*sum) | **Space**: O(sum)

### 19. Combination Sum IV
- **LeetCode**: 377
- **Dry Run**: [1,2,3], target=4 → 7 combinations
- **Time**: O(n*target) | **Space**: O(target)

### 20. Ones and Zeros
- **LeetCode**: 474
- **Dry Run**: ["10","0001","111001","1","0"], m=5, n=3 → max 4 strings
- **Time**: O(len*m*n) | **Space**: O(m*n)

---

## DP on String (⭐⭐⭐)

### 21. Edit Distance
- **LeetCode**: 72
- **Dry Run**: "horse" → "ros" = 3 edits
- **Time**: O(m*n) | **Space**: O(m*n)

### 22. Longest Common Subsequence
- **LeetCode**: 1143
- **Dry Run**: "abc" → "ac" = 2 (ac)
- **Time**: O(m*n) | **Space**: O(m*n)

### 23. Palindromic Substrings
- **LeetCode**: 647, 5
- **Dry Run**: "ababa" → 9 palindromes
- **Time**: O(n²) | **Space**: O(n²)

### 24. Longest Palindromic Substring
- **LeetCode**: 5
- **Dry Run**: "babad" → "bab" or "aba"
- **Time**: O(n²) | **Space**: O(n²)

### 25. Wildcard Matching
- **LeetCode**: 44
- **Dry Run**: "aa" matches pattern "a" → false
- **Time**: O(m*n) | **Space**: O(m*n)

### 26. Regular Expression Matching
- **LeetCode**: 10
- **Dry Run**: "aa" matches pattern "a*" → true
- **Time**: O(m*n) | **Space**: O(m*n)

### 27. Word Break
- **LeetCode**: 139, 140
- **Dry Run**: "leetcode", ["leet","code"] → true
- **Time**: O(n²) | **Space**: O(n)

### 28. Distinct Subsequences
- **LeetCode**: 115
- **Dry Run**: s="rabbbit", t="rabbit" → 3
- **Time**: O(m*n) | **Space**: O(m*n)

---

## DP on Interval (⭐⭐⭐)

### 29. Matrix Chain Multiplication
- **Source**: GeeksforGeeks
- **Dry Run**: 3 matrices → optimal parenthesization
- **Time**: O(n³) | **Space**: O(n²)

### 30. Palindrome Partitioning II
- **LeetCode**: 132
- **Dry Run**: "nitin" → 0 cuts (palindrome itself)
- **Time**: O(n²) | **Space**: O(n²)

### 31. Burst Balloons
- **LeetCode**: 312
- **Dry Run**: [3,1,5,8] → max score 167
- **Time**: O(n³) | **Space**: O(n²)

### 32. Remove Boxes
- **LeetCode**: 546
- **Dry Run**: [1,1,0,1] → max 9 points
- **Time**: O(n³) | **Space**: O(n³)

---

## DP on Bitmask (⭐⭐⭐)

### 33. Traveling Salesman Problem (TSP)
- **Source**: Codeforces
- **Dry Run**: n=4 cities → min distance visiting all
- **Time**: O(2^n * n²) | **Space**: O(2^n * n)

### 34. Subset Sum
- **LeetCode**: Various
- **Dry Run**: [1,1,1,1,1], target=3 → count subsets
- **Time**: O(n*2^n) | **Space**: O(2^n)

### 35. Assign Cookies
- **LeetCode**: 455
- **Dry Run**: Content assignment with bitmask
- **Time**: O(2^n) | **Space**: O(2^n)

### 36. Sum Over Subset (SOS) DP
- **Source**: Codeforces
- **Dry Run**: Count contributions of all subsets
- **Time**: O(n*2^n) | **Space**: O(2^n)

---

## DP on Tree (⭐⭐⭐)

### 37. Maximum Path Sum in Binary Tree
- **LeetCode**: 124
- **Dry Run**: Tree → max path between any nodes
- **Time**: O(n) | **Space**: O(h)

### 38. House Robber III
- **LeetCode**: 337
- **Dry Run**: Tree of houses → max rob without adjacent
- **Time**: O(n) | **Space**: O(h)

### 39. Diameter of Binary Tree
- **LeetCode**: 543
- **Dry Run**: Tree → longest path length
- **Time**: O(n) | **Space**: O(h)

### 40. Binary Tree Maximum Path Sum II
- **LeetCode**: 129
- **Dry Run**: Root to leaf → max sum
- **Time**: O(n) | **Space**: O(h)

---

## DP on Graph (⭐⭐⭐)

### 41. Shortest Path in DAG
- **Source**: GeeksforGeeks
- **Dry Run**: DAG → longest/shortest path
- **Time**: O(V + E) | **Space**: O(V)

### 42. Floyd-Warshall (All Pairs Shortest Path)
- **LeetCode**: 1334
- **Dry Run**: All pairs → shortest distances
- **Time**: O(V³) | **Space**: O(V²)

### 43. Number of Ways to Arrive at Destination
- **LeetCode**: 1976
- **Dry Run**: Count shortest paths in graph
- **Time**: O((V+E) log V) | **Space**: O(V)

---

## Advanced DP (⭐⭐⭐)

### 44. Digit DP - Count Numbers with Property
- **Source**: Codeforces
- **Dry Run**: Count numbers with specific digit sum
- **Time**: O(len * state * 2) | **Space**: O(len * state)

### 45. Digit DP - Non-Decreasing Digits
- **LeetCode**: 1015
- **Dry Run**: Count non-decreasing numbers in range
- **Time**: O(10 * len) | **Space**: O(10 * len)

### 46. LCS with Printing
- **Source**: GeeksforGeeks
- **Dry Run**: Find and print LCS
- **Time**: O(m*n) | **Space**: O(m*n)

### 47. Convex Hull Trick
- **Source**: Codeforces
- **Dry Run**: Optimize linear DP
- **Time**: O(n log n) | **Space**: O(n)

### 48. SOS DP Optimization
- **Source**: Codeforces
- **Dry Run**: Sum over all subsets
- **Time**: O(n*2^n) | **Space**: O(2^n)

---

## Study Plan

### Week 1: Basic DP
- Array DP: 1-8
- Grid DP: 9-13

### Week 2: Knapsack & String
- Knapsack: 14-20
- String DP: 21-28

### Week 3: Advanced
- Interval DP: 29-32
- Bitmask DP: 33-36

### Week 4: Specialized
- Tree DP: 37-40
- Graph DP: 41-43
- Advanced: 44-48

---

## Resource Links

- **LeetCode**: Dynamic Programming problems
- **Codeforces**: DP tutorials and problems
- **GeeksforGeeks**: Algorithm articles
- **AtCoder**: Educational DP contests
- **YouTube**: errichto, Tushar Roy DP playlists
