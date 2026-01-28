# Dynamic Programming - Real Competitive Programming Problems

## LeetCode Hard DP Problems

### 1. Burst Balloons (LeetCode 312) ⭐⭐⭐
- **Type**: Interval DP
- **Dry Run**: [3,1,5,8] → Consider which balloon to burst last
- **Key**: Reverse thinking - which ball burst last, not first
- **Solution**: dp[l][r] = max coins from bursting balloons between l and r
- **Time**: O(n³)

### 2. Regular Expression Matching (LeetCode 10) ⭐⭐⭐
- **Type**: String DP
- **Dry Run**: "aa" matches "a*" → true
- **Key**: Handle * character for matching 0 or more characters
- **Solution**: dp[i][j] = pattern match up to i-th char and j-th pattern
- **Time**: O(m*n)

### 3. Wildcard Matching (LeetCode 44) ⭐⭐⭐
- **Type**: String DP
- **Dry Run**: "acdcccccccba" matches "*accc*cba" → true
- **Key**: Handle * as matching any sequence
- **Solution**: Similar to regex but simpler
- **Time**: O(m*n)

### 4. Remove Boxes (LeetCode 546) ⭐⭐⭐
- **Type**: Interval DP + Memoization
- **Dry Run**: [1,1,0,1] → Remove to maximize points
- **Key**: dp[l][r][k] = max points removing [l,r] with k same boxes after r
- **Time**: O(n³) or O(n⁴)

### 5. Distinct Subsequences (LeetCode 115) ⭐⭐
- **Type**: String DP
- **Dry Run**: "rabbbit" contains "rabbit" → 3 ways
- **Key**: Count ways to form target from source
- **Solution**: dp[i][j] = count of s[0..i] containing t[0..j]
- **Time**: O(m*n)

### 6. Edit Distance (LeetCode 72) ⭐⭐
- **Type**: String DP (Levenshtein distance)
- **Dry Run**: "horse" → "ros" requires 3 operations
- **Key**: Insert, Delete, Replace operations
- **Solution**: Standard dp[i][j] for string comparison
- **Time**: O(m*n)

---

## Codeforces DP Problems

### 7. Codeforces 1009C: Annoying Present ⭐⭐⭐
- **Type**: Bitmask DP
- **Key**: Process with bitmask tracking
- **Time**: O(2^n * n)

### 8. Codeforces 1225D: Power Products ⭐⭐⭐
- **Type**: Digit DP + Counting
- **Key**: Count numbers with specific digit product
- **Time**: Complex

### 9. Codeforces 1201D: Dodge It! ⭐⭐
- **Type**: Greedy + DP
- **Key**: Path finding with obstacles
- **Time**: O(n*m)

### 10. Codeforces 1240B: Switch and Inversions ⭐⭐
- **Type**: Array DP + Math
- **Key**: Count inversions with operations
- **Time**: O(n²)

---

## AtCoder DP Problems

### 11. AtCoder DP_A - Frog ⭐
- **Type**: Basic Array DP
- **Dry Run**: Frog jumping on stairs
- **Key**: dp[i] = min cost to reach position i
- **Time**: O(n)

### 12. AtCoder DP_B - Frog 2 ⭐
- **Type**: Array DP with multiple choices
- **Dry Run**: Jump up to k steps at a time
- **Key**: dp[i] = min(dp[i-j]) for j=1..k
- **Time**: O(n*k)

### 13. AtCoder DP_C - Vacation ⭐
- **Type**: 2D Array DP
- **Dry Run**: Choose activity each day, can't repeat
- **Key**: dp[i][j] = happiness choosing activity j on day i
- **Time**: O(n*3)

### 14. AtCoder DP_D - Knapsack 1 ⭐
- **Type**: 0/1 Knapsack
- **Dry Run**: Maximize value with weight limit
- **Key**: Standard knapsack
- **Time**: O(n*W)

### 15. AtCoder DP_H - Grid 1 ⭐
- **Type**: Grid DP
- **Dry Run**: Paths in grid with obstacles
- **Key**: dp[i][j] = paths to reach (i,j)
- **Time**: O(m*n)

---

## Problem Patterns & Approaches

### Pattern 1: Optimization DP
**Identify**: "Find maximum/minimum"
**Approach**: 
```
dp[state] = optimal value at state
Recurrence: dp[i] = max/min(f(dp[j]) for valid j)
```

### Pattern 2: Counting DP
**Identify**: "Count ways/combinations"
**Approach**:
```
dp[state] = number of ways to reach state
Recurrence: dp[i] = sum(dp[j]) for valid j
```

### Pattern 3: Existence DP
**Identify**: "Is it possible?"
**Approach**:
```
dp[state] = true if reachable, false otherwise
Recurrence: dp[i] = OR of all valid transitions
```

### Pattern 4: Prefix/Suffix DP
**Identify**: "Best prefix/suffix"
**Approach**:
```
prefix[i] = best value in [0, i]
suffix[i] = best value in [i, n-1]
Answer combines both
```

---

## Advanced DP Optimizations

### 1. Convex Hull Trick
**When**: dp[i] = min(dp[j] + a[j]*b[i])
**How**: Maintain lower convex hull of lines
**Complexity**: O(n log n) instead of O(n²)

### 2. Divide and Conquer Optimization
**When**: Monotonicity in optimal solution
**How**: Binary search on optimal k position
**Complexity**: O(n log n) instead of O(n²)

### 3. Slope Optimization (CHT)
**When**: Similar to convex hull trick
**How**: Process in specific order for online queries
**Complexity**: O(n) instead of O(n²)

### 4. Bitwise DP Optimization
**When**: dp with bitmask state
**How**: Use SOS (Sum Over Subsets) technique
**Complexity**: O(n*2^n) instead of O(3^n)

---

## Contest Strategy

1. **Identify DP Type**
   - Array/Grid/String/Tree/Graph/Bitmask/Digit?
   
2. **Define State Clearly**
   - What does dp[...] represent?
   - What are dimensions?
   
3. **Write Base Cases**
   - Handle all edge cases
   
4. **Recurrence Relation**
   - How to transition from previous states?
   
5. **Implementation**
   - 1D or 2D array?
   - Memoization or tabulation?
   
6. **Test & Debug**
   - Manual trace on small examples
   - Check boundary conditions
   - Verify complexity
   
7. **Optimize if TLE**
   - Space optimization
   - Time optimization techniques

---

## Common DP Interview Tricks

1. **Rethink the Problem**: Reverse the problem (e.g., Burst Balloons)
2. **Include/Exclude**: Two states (take/skip)
3. **Range Queries**: Try all split points
4. **Graph Problems**: Use topological sort + DP
5. **String Problems**: Always think alignment

---

## Debugging Techniques

1. **Print DP Table**: Visualize the computation
2. **Manual Trace**: Trace through a small example
3. **Check Transitions**: Verify each recurrence
4. **Boundary Conditions**: Ensure proper initialization
5. **Integer Overflow**: Use long long if needed
6. **Array Bounds**: Check indices carefully
7. **Base Cases**: Verify all base case values

---

## Resources

- **GeeksforGeeks**: Complete DP articles with examples
- **Codeforces**: Editorial for problems with detailed explanations
- **LeetCode**: Problems organized by difficulty
- **AtCoder**: Educational DP contest with clear problems
- **YouTube**: Channels like Tushar Roy, errichto, William Fiset
- **Competitive Programmer's Handbook**: Chapter 7 (Dynamic Programming)

---

## Problem Statistics

| Difficulty | Array | Grid | String | Tree | Total |
|-----------|-------|------|--------|------|-------|
| Easy | 4 | 3 | 1 | 1 | 9 |
| Medium | 6 | 4 | 5 | 3 | 18 |
| Hard | 8 | 3 | 4 | 2 | 17 |
| **Total** | **18** | **10** | **10** | **6** | **44+** |

---

## Key Insights by Type

- **Array DP**: Often O(n²) with optimization to O(n log n)
- **Grid DP**: Usually O(m*n), can be space-optimized to O(min(m,n))
- **String DP**: O(m*n) is typical, no better known
- **Tree DP**: O(n) traversal, optimal complexity
- **Bitmask DP**: O(2^n * n) unavoidable unless problem has special structure
- **Digit DP**: O(len * state) where len is number of digits
- **Knapsack**: O(n*W) where W is capacity/weight limit

