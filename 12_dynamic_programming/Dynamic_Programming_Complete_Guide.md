# Dynamic Programming in C++ for Competitive Programming

## Table of Contents
1. [DP Fundamentals](#dp-fundamentals)
2. [DP on Array](#dp-on-array)
3. [DP on Digits](#dp-on-digits)
4. [DP on Interval](#dp-on-interval)
5. [Knapsack DP](#knapsack-dp)
6. [DP on Grid](#dp-on-grid)
7. [DP on String](#dp-on-string)
8. [DP on Tree](#dp-on-tree)
9. [DP on Graph](#dp-on-graph)
10. [DP on Bitmask](#dp-on-bitmask)
11. [Advanced DP Concepts](#advanced-dp-concepts)
12. [Optimization Techniques](#optimization-techniques)

---

## DP Fundamentals

### Core Principles
1. **Overlapping Subproblems**: Same problem solved multiple times
2. **Optimal Substructure**: Optimal solution from optimal subproblems
3. **State Definition**: Clear definition of what DP state represents
4. **Transition**: How to compute current state from previous states
5. **Base Case**: Initial conditions that don't depend on other states

### Example: Fibonacci
```cpp
// Dry run: fib(5)
// fib(5) = fib(4) + fib(3)
// fib(4) = fib(3) + fib(2)
// fib(3) = fib(2) + fib(1)
// fib(2) = fib(1) + fib(0)
// fib(1) = 1, fib(0) = 0

// DP Approach:
// dp[0] = 0
// dp[1] = 1
// dp[2] = dp[1] + dp[0] = 1
// dp[3] = dp[2] + dp[1] = 2
// dp[4] = dp[3] + dp[2] = 3
// dp[5] = dp[4] + dp[3] = 5

long long fib(int n) {
    vector<long long> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```

---

## DP on Array

### 1. Maximum Subarray Sum (Kadane's Algorithm)
```cpp
// Dry run: arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
// dp[0] = -2
// dp[1] = max(1, -2+1) = 1
// dp[2] = max(-3, 1-3) = -3
// dp[3] = max(4, -3+4) = 4
// dp[4] = max(-1, 4-1) = 3
// ...
// ans = 6

int maxSubarraySum(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    int maxSum = arr[0];
    
    for (int i = 1; i < n; i++) {
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
        maxSum = max(maxSum, dp[i]);
    }
    
    return maxSum;
}
```

### 2. Longest Increasing Subsequence (LIS)
```cpp
// Dry run: arr = [10, 9, 2, 5, 3, 7, 101, 18]
// dp[0] = 1
// dp[1] = 1 (9 not > 10)
// dp[2] = 1 (2 not > 10 or 9)
// dp[3] = 2 (5 > 2)
// dp[4] = 2 (3 > 2)
// dp[5] = 3 (7 > 5 or 3)
// dp[6] = 4 (101 > all)
// dp[7] = 4 (18 > 2,5,3,7)
// ans = 4 [10,9,2,5,7,101] -> [2,3,7,101]

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

// Optimized: O(n log n) using binary search
int lengthOfLIS_Optimized(vector<int>& nums) {
    vector<int> lis;
    
    for (int num : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }
    
    return lis.size();
}
```

### 3. Maximum Product Subarray
```cpp
// Dry run: arr = [2, 3, -2, 4]
// maxDP[0] = 2, minDP[0] = 2
// maxDP[1] = max(3, 2*3) = 6, minDP[1] = 3
// maxDP[2] = max(-2, min(6,-2)*(-2)) = 4, minDP[2] = -6
// maxDP[3] = max(4, 4*4) = 16, minDP[3] = -4
// ans = 16

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> maxDP(n), minDP(n);
    maxDP[0] = minDP[0] = nums[0];
    int result = nums[0];
    
    for (int i = 1; i < n; i++) {
        maxDP[i] = max({nums[i], maxDP[i-1] * nums[i], minDP[i-1] * nums[i]});
        minDP[i] = min({nums[i], maxDP[i-1] * nums[i], minDP[i-1] * nums[i]});
        result = max(result, maxDP[i]);
    }
    
    return result;
}
```

### 4. Jump Game
```cpp
// Dry run: nums = [2, 3, 1, 1, 4]
// Can reach index 1? Yes (from 0)
// Can reach index 2? Yes (from 0 or 1)
// Can reach index 3? Yes (from 1 or 2)
// Can reach index 4? Yes (from 1 or 3)

bool canJump(vector<int>& nums) {
    int maxReach = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    
    return true;
}
```

---

## DP on Digits

### 1. Count Digit DP
```cpp
// Dry run: Count numbers from 1 to n with digit property
// Example: Count numbers where digit i appears k times

// dp[pos][count][tight]
// pos: current position
// count: count of digit i found so far
// tight: whether we're still bounded by n

int countDigits(int n, int digit) {
    string s = to_string(n);
    int len = s.length();
    
    // dp[pos][count][tight]
    vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(len + 1, vector<int>(2, -1)));
    
    function<int(int, int, int)> solve = [&](int pos, int cnt, int tight) -> int {
        if (pos == len) {
            return cnt;
        }
        
        if (dp[pos][cnt][tight] != -1) {
            return dp[pos][cnt][tight];
        }
        
        int limit = tight ? (s[pos] - '0') : 9;
        int result = 0;
        
        for (int digit = 0; digit <= limit; digit++) {
            int newCnt = cnt + (digit == 1 ? 1 : 0);
            int newTight = tight && (digit == limit) ? 1 : 0;
            result += solve(pos + 1, newCnt, newTight);
        }
        
        return dp[pos][cnt][tight] = result;
    };
    
    return solve(0, 0, 1);
}
```

### 2. Count Numbers with Specific Digit Sum
```cpp
// Dry run: Numbers 1-99 with digit sum = 10
// 19, 28, 37, 46, 55, 64, 73, 82, 91

int countNumbersWithDigitSum(int n, int digitSum) {
    string s = to_string(n);
    int len = s.length();
    
    vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(digitSum + 1, vector<int>(2, -1)));
    
    function<int(int, int, int)> solve = [&](int pos, int sum, int tight) -> int {
        if (sum < 0) return 0;
        if (pos == len) {
            return sum == 0 ? 1 : 0;
        }
        
        if (dp[pos][sum][tight] != -1) {
            return dp[pos][sum][tight];
        }
        
        int limit = tight ? (s[pos] - '0') : 9;
        int result = 0;
        
        for (int digit = 0; digit <= limit; digit++) {
            int newTight = tight && (digit == limit) ? 1 : 0;
            result += solve(pos + 1, sum - digit, newTight);
        }
        
        return dp[pos][sum][tight] = result;
    };
    
    return solve(0, digitSum, 1);
}
```

---

## DP on Interval

### 1. Matrix Chain Multiplication
```cpp
// Dry run: matrices [10x30][30x5][5x60]
// (A*B)*C: (10*30*5) + (10*5*60) = 1500 + 3000 = 4500
// A*(B*C): (30*5*60) + (10*30*60) = 9000 + 18000 = 27000
// Minimum: 4500

int matrixChainMultiplication(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    // l is chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    return dp[1][n];
}
```

### 2. Palindrome Partitioning
```cpp
// Dry run: "nitin"
// Can partition as: "n|i|t|i|n" (5 parts)
// Or: "n|iti|n" (3 parts)
// Or: "nitin" (1 part) - palindrome
// Minimum cuts: 0

int minCuts(string s) {
    int n = s.length();
    vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    
    // Check all palindromes
    for (int i = 0; i < n; i++) {
        isPalin[i][i] = true;
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                isPalin[i][j] = (len == 2) || isPalin[i+1][j-1];
            }
        }
    }
    
    vector<int> dp(n);
    
    for (int i = 0; i < n; i++) {
        if (isPalin[0][i]) {
            dp[i] = 0;
        } else {
            dp[i] = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (isPalin[j+1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    
    return dp[n-1];
}
```

### 3. Burst Balloons
```cpp
// Dry run: nums = [3, 1, 5, 8]
// Burst in order: 1, 3, 8, 5
// Score: 3*1*5 + 3*5*8 + 1*8*1 + 1*1*1 = 15 + 120 + 8 + 1 = 144

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<int> balloons(n + 2);
    balloons[0] = balloons[n+1] = 1;
    
    for (int i = 0; i < n; i++) {
        balloons[i+1] = nums[i];
    }
    
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    
    for (int len = 3; len <= n + 2; len++) {
        for (int left = 0; left + len - 1 < n + 2; left++) {
            int right = left + len - 1;
            
            for (int k = left + 1; k < right; k++) {
                int coins = balloons[left] * balloons[k] * balloons[right]
                           + dp[left][k] + dp[k][right];
                dp[left][right] = max(dp[left][right], coins);
            }
        }
    }
    
    return dp[0][n+1];
}
```

---

## Knapsack DP

### 1. 0/1 Knapsack
```cpp
// Dry run: weights = [2, 3, 4], values = [3, 4, 5], capacity = 5
// dp[0][0] = 0
// dp[1][2] = 3, dp[1][3] = 3, dp[1][4] = 3, dp[1][5] = 3
// dp[2][3] = 4, dp[2][5] = max(3, 4) = 4, dp[2][6] = 3+4=7
// dp[3][4] = 5, dp[3][6] = max(4,5)=5, dp[3][7] = max(5, 3+5)=8, dp[3][9] = 4+5=9
// Answer: 7

int knapsack01(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            // Don't take item
            dp[i][w] = dp[i-1][w];
            
            // Take item if possible
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            }
        }
    }
    
    return dp[n][capacity];
}

// Space optimized version
int knapsack01_Optimized(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    
    return dp[capacity];
}
```

### 2. Unbounded Knapsack
```cpp
// Dry run: weights = [1, 3, 4], values = [1, 4, 5], capacity = 8
// Each item can be taken unlimited times
// dp[0] = 0
// dp[1] = 1, dp[2] = 2, dp[3] = max(3, 1+3) = 4, ...
// dp[8] = 10

int knapsackUnbounded(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    
    for (int w = 0; w <= capacity; w++) {
        for (int i = 0; i < n; i++) {
            if (weights[i] <= w) {
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
    }
    
    return dp[capacity];
}
```

### 3. Coin Change
```cpp
// Dry run: coins = [1, 2, 5], amount = 5
// dp[0] = 0
// dp[1] = 1 (1)
// dp[2] = 1 (2)
// dp[3] = 2 (1+2)
// dp[4] = 2 (2+2)
// dp[5] = 1 (5)

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
```

---

## DP on Grid

### 1. Unique Paths
```cpp
// Dry run: m=3, n=2 (3 rows, 2 cols)
// dp[0][0] = 1
// dp[0][1] = 1, dp[0][2] = 1
// dp[1][0] = 1, dp[1][1] = 2, dp[1][2] = 3
// dp[2][0] = 1, dp[2][1] = 3, dp[2][2] = 6
// Answer: 6

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}
```

### 2. Minimum Path Sum
```cpp
// Dry run: grid = [[1,3,1],[1,5,1],[4,2,1]]
// dp[0][0] = 1
// dp[0][1] = 1+3=4, dp[0][2] = 4+1=5
// dp[1][0] = 1+1=2, dp[1][1] = min(4,2)+5=7, dp[1][2] = min(7,5)+1=6
// dp[2][0] = 2+4=6, dp[2][1] = min(6,7)+2=8, dp[2][2] = min(8,6)+1=7
// Answer: 7

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp = grid;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            else if (i == 0) dp[i][j] += dp[i][j-1];
            else if (j == 0) dp[i][j] += dp[i-1][j];
            else dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[m-1][n-1];
}
```

### 3. Dungeon Game
```cpp
// Dry run: dungeon = [[-3, 5], [-1, -2]]
// Working backwards from end:
// dp[1][1] = max(1, 1 - (-2)) = 3
// dp[1][0] = max(1, 3 - 5) = 1
// dp[0][1] = max(1, 3 - (-1)) = 4
// dp[0][0] = max(1, 4 - (-3)) = 7
// Answer: 7

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m][n-1] = dp[m-1][n] = 1;
    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int minHealth = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
            dp[i][j] = max(1, minHealth);
        }
    }
    
    return dp[0][0];
}
```

---

## DP on String

### 1. Edit Distance (Levenshtein Distance)
```cpp
// Dry run: word1 = "horse", word2 = "ros"
// dp[0][0] = 0
// dp[1][1] = 0 (h != r), dp[1][0] = 1, dp[0][1] = 1
// Build full table:
// distance = 3

int editDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    
    return dp[m][n];
}
```

### 2. Longest Common Subsequence (LCS)
```cpp
// Dry run: text1 = "abc", text2 = "ac"
// dp[0][*] = 0, dp[*][0] = 0
// dp[1][1] = 1 (a==a), dp[1][2] = 1
// dp[2][1] = 1, dp[2][2] = 1
// dp[3][1] = 1, dp[3][2] = 2 (ac)
// Answer: 2

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
```

### 3. Palindromic Substrings
```cpp
// Dry run: s = "abc"
// Palindromes: a, b, c (3 total)
// s = "ababa"
// Palindromes: a, b, a, b, a, aba, bab, ababa (9 total)

int countSubstrings(string s) {
    int n = s.length();
    vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        isPalin[i][i] = true;
        count++;
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                isPalin[i][j] = (len == 2) || isPalin[i+1][j-1];
                if (isPalin[i][j]) count++;
            }
        }
    }
    
    return count;
}
```

---

## DP on Tree

### 1. Tree DP - Maximum Path in Tree
```cpp
// Dry run: Tree with values
// At each node: max = node value + max(left path, 0) + max(right path, 0)

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int maxPathSum(TreeNode* root, int& globalMax) {
    if (!root) return 0;
    
    int leftMax = max(0, maxPathSum(root->left, globalMax));
    int rightMax = max(0, maxPathSum(root->right, globalMax));
    
    globalMax = max(globalMax, root->val + leftMax + rightMax);
    
    return root->val + max(leftMax, rightMax);
}
```

### 2. Tree DP - House Robber III
```cpp
// Dry run: Rob houses in tree, can't rob adjacent
// Return: {robbed, notRobbed}

pair<int, int> rob(TreeNode* root) {
    if (!root) return {0, 0};
    
    auto [leftRob, leftNoRob] = rob(root->left);
    auto [rightRob, rightNoRob] = rob(root->right);
    
    int robCurrent = root->val + leftNoRob + rightNoRob;
    int notRobCurrent = max(leftRob, leftNoRob) + max(rightRob, rightNoRob);
    
    return {robCurrent, notRobCurrent};
}
```

### 3. Tree DP - Subtree Sum DP
```cpp
// Dry run: Count subtrees with sum = targetSum

int countSubtreeWithSum(TreeNode* root, int targetSum, int& count) {
    if (!root) return 0;
    
    int sum = root->val + countSubtreeWithSum(root->left, targetSum, count)
                        + countSubtreeWithSum(root->right, targetSum, count);
    
    if (sum == targetSum) count++;
    
    return sum;
}
```

---

## DP on Graph

### 1. Shortest Path - Floyd-Warshall (DP)
```cpp
// Dry run: All pairs shortest paths
// dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

void floydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
```

### 2. Longest Path in DAG
```cpp
// Dry run: DP on DAG for longest path
// Use topological sort + DP

int longestPathDAG(vector<vector<int>>& graph, int n) {
    vector<int> dist(n, 0);
    vector<bool> visited(n, false);
    
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        
        for (int v : graph[u]) {
            if (!visited[v]) dfs(v);
            dist[u] = max(dist[u], dist[v] + 1);
        }
    };
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }
    
    return *max_element(dist.begin(), dist.end());
}
```

---

## DP on Bitmask

### 1. Traveling Salesman Problem (TSP)
```cpp
// Dry run: n=3 cities, find min distance visiting all
// dp[mask][i] = min distance to visit cities in mask, ending at i
// mask = 111 (binary) = visit all 3 cities
// dp[7][0], dp[7][1], dp[7][2] = min distances ending at each city

const int INF = 1e9;

int tsp(vector<vector<int>>& dist) {
    int n = dist.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    
    dp[1][0] = 0; // Start at city 0
    
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            if (dp[mask][u] == INF) continue;
            
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                
                int newMask = mask | (1 << v);
                dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + dist[u][v]);
            }
        }
    }
    
    int result = INF;
    for (int i = 0; i < n; i++) {
        result = min(result, dp[(1 << n) - 1][i]);
    }
    
    return result;
}
```

### 2. Subset DP
```cpp
// Dry run: Partition set into subsets with equal sum
// Subset XOR = 0 means partitionable

bool canPartitionToEqualSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i-1][j];
            
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }
    
    return dp[n][target];
}
```

---

## Advanced DP Concepts

### 1. Digit DP with Constraints
```cpp
// Count numbers in range [L, R] with specific properties

int countNumbersWithConstraints(int l, int r) {
    auto solve = [&](int num) -> int {
        string s = to_string(num);
        int len = s.length();
        vector<vector<vector<int>>> dp(len + 1, 
                                       vector<vector<int>>(10 + 1, 
                                       vector<int>(2, -1)));
        
        function<int(int, int, int)> rec = [&](int pos, int sum, int tight) -> int {
            if (pos == len) {
                return (sum > 0 && sum % 10 == 0) ? 1 : 0;
            }
            
            if (dp[pos][sum][tight] != -1) {
                return dp[pos][sum][tight];
            }
            
            int limit = tight ? (s[pos] - '0') : 9;
            int result = 0;
            
            for (int digit = 0; digit <= limit; digit++) {
                result += rec(pos + 1, (sum + digit) % 10, tight && (digit == limit));
            }
            
            return dp[pos][sum][tight] = result;
        };
        
        return rec(0, 0, 1);
    };
    
    return solve(r) - (l > 0 ? solve(l - 1) : 0);
}
```

### 2. Convex Hull Trick
```cpp
// Optimization for DP with linear inequalities
// Used in problems like: Maximize j*x[i] - dp[j] + y[i]
```

### 3. Divide and Conquer Optimization
```cpp
// When dp[i][j] = min(dp[i-1][k] + cost(k,j))
// And cost function satisfies Monge property
// Can reduce from O(n²m) to O(nm log n)
```

---

## Optimization Techniques

### 1. Space Optimization
```cpp
// Instead of 2D array, use 1D rolling array
// dp[i] depends on dp[i-1]

// Before:
vector<vector<int>> dp(n+1, vector<int>(m+1));

// After:
vector<int> prev(m+1), curr(m+1);
```

### 2. Time Optimization with SOS DP
```cpp
// Sum Over Subset DP - O(n * 2^n) instead of O(3^n)
// dp[mask] = sum of all dp[submask] where submask is subset of mask

void sosDP(vector<int>& dp, int n) {
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << i)) {
                dp[mask] += dp[mask ^ (1 << i)];
            }
        }
    }
}
```

### 3. Memoization vs Tabulation
```cpp
// Memoization: Top-down, only compute needed states
map<int, int> memo;

int fib_memo(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fib_memo(n-1) + fib_memo(n-2);
}

// Tabulation: Bottom-up, compute all states
vector<int> dp(n+1);
dp[0] = 0; dp[1] = 1;
for (int i = 2; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
}
```

---

## DP State Transitions Summary

| Type | State Definition | Transition | Complexity |
|------|------------------|-----------|-----------|
| Array | dp[i] | dp[i] = f(dp[j]) for j < i | O(n²) |
| Grid | dp[i][j] | dp[i][j] = f(dp[i-1][j], dp[i][j-1]) | O(m*n) |
| String | dp[i][j] | Match/mismatch string[i] with string[j] | O(m*n) |
| Tree | dp[node] | Sum/max of children | O(n) |
| Bitmask | dp[mask] | Toggle bits in mask | O(2^n * n) |
| Digit | dp[pos][state][tight] | Iterate digit 0 to limit | O(len * state * 2) |

---

## Common DP Mistakes

1. **Wrong base case**: Leads to incorrect recursion
2. **Integer overflow**: Use long long for sums
3. **Not handling negative**: Min/max with negatives
4. **Duplicate counting**: Ensure transitions avoid duplicates
5. **Time limit**: Not optimizing from O(3^n) to O(2^n)
6. **Memory**: 2D arrays too large, use rolling array

