# Dynamic Programming - Quick Reference

## State Definition Template

```cpp
// General DP structure
vector<type> dp(size, initial_value);  // 1D
vector<vector<type>> dp(n, vector<type>(m, initial_value));  // 2D

// Recurrence relation
dp[i] = f(dp[i-1], dp[i-2], ...);

// Answer
return dp[n-1];
```

---

## All DP Types Cheat Sheet

| Type | State | Recurrence | Time | Space |
|------|-------|-----------|------|-------|
| Array | dp[i] | max/min of dp[j] for j<i | O(n²) | O(n) |
| Grid | dp[i][j] | dp[i-1][j] + dp[i][j-1] | O(m*n) | O(m*n) |
| String | dp[i][j] | Match chars, take min | O(m*n) | O(m*n) |
| Knapsack | dp[i][w] | max(take, skip) | O(n*W) | O(n*W) |
| Interval | dp[i][j] | Try all splits k | O(n³) | O(n²) |
| Bitmask | dp[mask] | Try bits in mask | O(2^n*n) | O(2^n) |
| Digit | dp[pos][state][tight] | Iterate digits | O(len*state) | O(len*state) |
| Tree | dp[node] | Combine children | O(n) | O(h) |
| Graph | dp[node] | Shortest/longest path | O(V*E) | O(V) |

---

## Quick Templates

### 1. 1D Array DP
```cpp
vector<int> dp(n);
dp[0] = base_case;

for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
        dp[i] = max/min(dp[i], dp[j] + cost(j, i));
    }
}

return dp[n-1];
```

### 2. 2D Array DP
```cpp
vector<vector<int>> dp(m, vector<int>(n));

for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        dp[i][j] = f(dp[i-1][j], dp[i][j-1], ...);
    }
}

return dp[m-1][n-1];
```

### 3. Knapsack Template
```cpp
vector<int> dp(capacity + 1, 0);

for (int item = 0; item < n; item++) {
    for (int w = capacity; w >= weight[item]; w--) {
        dp[w] = max(dp[w], dp[w - weight[item]] + value[item]);
    }
}

return dp[capacity];
```

### 4. String DP Template
```cpp
vector<vector<int>> dp(m + 1, vector<int>(n + 1));

for (int i = 0; i <= m; i++) dp[i][0] = i;
for (int j = 0; j <= n; j++) dp[0][j] = j;

for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (s1[i-1] == s2[j-1]) {
            dp[i][j] = dp[i-1][j-1];
        } else {
            dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }
}

return dp[m][n];
```

### 5. Bitmask DP Template
```cpp
vector<int> dp(1 << n);
dp[0] = initial;

for (int mask = 0; mask < (1 << n); mask++) {
    for (int bit = 0; bit < n; bit++) {
        if (!(mask & (1 << bit))) {
            int newMask = mask | (1 << bit);
            dp[newMask] = max/min(dp[newMask], f(dp[mask], bit));
        }
    }
}

return dp[(1 << n) - 1];
```

### 6. Digit DP Template
```cpp
// memo[pos][state][tight]
int digitDP(string num, int pos, int state, int tight) {
    if (pos == num.length()) {
        return validate(state);
    }
    
    if (memo[pos][state][tight] != -1) {
        return memo[pos][state][tight];
    }
    
    int limit = tight ? (num[pos] - '0') : 9;
    int result = 0;
    
    for (int digit = 0; digit <= limit; digit++) {
        result += digitDP(num, pos + 1, new_state, tight && (digit == limit));
    }
    
    return memo[pos][state][tight] = result;
}
```

### 7. Tree DP Template
```cpp
pair<int, int> dfs(Node* node) {  // {include, exclude}
    if (!node) return {0, 0};
    
    auto [lInc, lExc] = dfs(node->left);
    auto [rInc, rExc] = dfs(node->right);
    
    int include = node->val + lExc + rExc;
    int exclude = max(lInc, lExc) + max(rInc, rExc);
    
    return {include, exclude};
}
```

### 8. Interval DP Template
```cpp
vector<vector<int>> dp(n, vector<int>(n));

for (int len = 1; len <= n; len++) {
    for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        
        for (int k = i; k < j; k++) {
            dp[i][j] = max/min(dp[i][j], dp[i][k] + dp[k+1][j] + cost(i, j));
        }
    }
}

return dp[0][n-1];
```

---

## Space Optimization Techniques

### 1. Rolling Array (2D → 1D)
```cpp
// Before: O(n²) space
vector<vector<int>> dp(n, vector<int>(n));

// After: O(n) space
vector<int> prev(n), curr(n);
```

### 2. Reverse Iteration for Knapsack
```cpp
// Use reverse loop to avoid using updated values
for (int w = capacity; w >= weight[i]; w--) {
    dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
}
```

### 3. Memoization Instead of Tabulation
```cpp
// Use only computed states, not all possible states
map<pair<int,int>, int> memo;

int solve(int i, int j) {
    if (i == 0 || j == 0) return 0;
    if (memo.count({i, j})) return memo[{i, j}];
    return memo[{i, j}] = f(solve(i-1, j), solve(i, j-1));
}
```

---

## State Design Patterns

### Pattern 1: Maximum/Minimum Value
```cpp
// Find maximum value ending at position i
// dp[i] = max value using elements 0..i
```

### Pattern 2: Count DP
```cpp
// Count ways to reach state
// dp[i] = number of ways to reach position i
```

### Pattern 3: Existence DP
```cpp
// Check if state is reachable
// dp[i] = true if position i is reachable, false otherwise
```

### Pattern 4: Optimal Choice DP
```cpp
// Track optimal decision at each step
// dp[i] = optimal value at position i
// parent[i] = choice made to reach dp[i]
```

---

## Common Mistakes & Fixes

| Mistake | Fix |
|---------|-----|
| Wrong base case | Write base cases for all dimensions |
| Integer overflow | Use `long long` for large sums |
| Dimension mismatch | Check dp array size matches problem |
| Incorrect recurrence | Verify with small test case manually |
| Not handling constraints | Check all conditions in recurrence |
| Forgetting -1 in string indices | Remember string is 0-indexed |
| Wrong loop order | Ensure dependencies are computed first |
| Not initializing properly | Set all dp values to initial state |
| TLE from O(3^n) | Optimize to O(2^n) or lower |

---

## Time Complexity Decisions

| Input Size | Max Complexity | Algorithm Type |
|-----------|----------------|-----------------|
| n ≤ 20 | O(2^n * n) | Bitmask DP |
| n ≤ 100 | O(n³) | Interval DP |
| n ≤ 1000 | O(n²) | String/Knapsack |
| n ≤ 10^5 | O(n log n) | Array/Greedy |
| n ≤ 10^6 | O(n) | Array |

---

## Problem Identification Flowchart

```
Question
├─ "Maximum/Minimum" → Optimization DP
├─ "Count ways" → Counting DP
├─ "Can reach?" → Existence DP
├─ "Longest/Shortest" → Optimization DP
├─ "Pattern match?" → String DP
├─ "Subset/Partition?" → Bitmask or Knapsack DP
├─ "Path in tree?" → Tree DP
├─ "Path in graph?" → Graph DP (Dijkstra/BFS)
├─ "Digit property?" → Digit DP
└─ "Range query?" → Segment Tree or Interval DP
```

---

## Essential Code Snippets

### 1. LIS Optimized
```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> lis;
    for (int num : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) lis.push_back(num);
        else *it = num;
    }
    return lis.size();
}
```

### 2. Digit Root
```cpp
int digitRoot(int n) {
    if (n == 0) return 0;
    return (n % 9 == 0) ? 9 : (n % 9);
}
```

### 3. Bit Operations
```cpp
__builtin_popcount(x);      // Count set bits
__builtin_ctz(x);           // Count trailing zeros
__builtin_clz(x);           // Count leading zeros
x & (x - 1);                // Remove last set bit
x | (x + 1);                // Add rightmost 0 as 1
```

### 4. GCD/LCM
```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
```

---

## Memory Limits

- Typical limit: 256 MB
- vector<int> of size 10^7: ~40 MB
- vector<vector<int>> 1000x1000: ~4 MB
- Safe limit: 50-100 million integers
