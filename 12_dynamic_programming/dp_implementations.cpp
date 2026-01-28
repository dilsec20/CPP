#include <bits/stdc++.h>
using namespace std;

// ===========================================
// DYNAMIC PROGRAMMING - All Types with Code
// ===========================================

// ========== DP ON ARRAY ==========

// Maximum Subarray Sum (Kadane's Algorithm)
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

// Longest Increasing Subsequence
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

// Longest Increasing Subsequence - Optimized (O(n log n))
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

// Maximum Product Subarray
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

// Jump Game
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    
    return true;
}

// ========== DP ON GRID ==========

// Unique Paths
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}

// Minimum Path Sum
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

// Dungeon Game
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

// ========== KNAPSACK DP ==========

// 0/1 Knapsack
int knapsack01(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i-1][w];
            
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            }
        }
    }
    
    return dp[n][capacity];
}

// 0/1 Knapsack - Space Optimized
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

// Unbounded Knapsack
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

// Coin Change
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

// ========== DP ON STRING ==========

// Edit Distance
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

// Longest Common Subsequence
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

// Palindromic Substrings Count
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

// ========== DP ON INTERVAL ==========

// Matrix Chain Multiplication
int matrixChainMultiplication(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
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

// Palindrome Partitioning
int minCuts(string s) {
    int n = s.length();
    vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    
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

// ========== DP ON BITMASK ==========

const int INF = 1e9;

// Traveling Salesman Problem (TSP)
int tsp(vector<vector<int>>& dist) {
    int n = dist.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    
    dp[1][0] = 0;
    
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

// Subset Sum DP
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

// Sum Over Subset (SOS) DP
void sosDP(vector<int>& dp, int n) {
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << i)) {
                dp[mask] += dp[mask ^ (1 << i)];
            }
        }
    }
}

// ========== DP ON TREE ==========

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// Tree DP - Maximum Path Sum
int maxPathSum(TreeNode* root, int& globalMax) {
    if (!root) return 0;
    
    int leftMax = max(0, maxPathSum(root->left, globalMax));
    int rightMax = max(0, maxPathSum(root->right, globalMax));
    
    globalMax = max(globalMax, root->val + leftMax + rightMax);
    
    return root->val + max(leftMax, rightMax);
}

// Tree DP - House Robber III
pair<int, int> robTree(TreeNode* root) {
    if (!root) return {0, 0};
    
    auto [leftRob, leftNoRob] = robTree(root->left);
    auto [rightRob, rightNoRob] = robTree(root->right);
    
    int robCurrent = root->val + leftNoRob + rightNoRob;
    int notRobCurrent = max(leftRob, leftNoRob) + max(rightRob, rightNoRob);
    
    return {robCurrent, notRobCurrent};
}

// ========== DP ON DIGIT ==========

// Count Numbers with Specific Digit Sum
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

// ========== DP ON GRAPH ==========

// Floyd-Warshall (All Pairs Shortest Path)
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

// ========== UTILITY FUNCTIONS ==========

void printDP1D(vector<int>& dp) {
    for (int x : dp) {
        cout << x << " ";
    }
    cout << endl;
}

void printDP2D(vector<vector<int>>& dp) {
    for (auto& row : dp) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

// ========== EXAMPLE USAGE ==========

int main() {
    cout << "=== DP Examples ===" << endl;
    
    // Array DP
    cout << "\n=== Array DP ===" << endl;
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max subarray sum: " << maxSubarraySum(arr) << endl;
    
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS: " << lengthOfLIS(nums) << endl;
    
    // Grid DP
    cout << "\n=== Grid DP ===" << endl;
    cout << "Unique paths (3, 7): " << uniquePaths(3, 7) << endl;
    
    // Knapsack DP
    cout << "\n=== Knapsack DP ===" << endl;
    vector<int> weights = {2, 3, 4};
    vector<int> values = {3, 4, 5};
    cout << "0/1 Knapsack (capacity=5): " << knapsack01(weights, values, 5) << endl;
    
    vector<int> coins = {1, 2, 5};
    cout << "Coin change (amount=5): " << coinChange(coins, 5) << endl;
    
    // String DP
    cout << "\n=== String DP ===" << endl;
    cout << "Edit distance (horse, ros): " << editDistance("horse", "ros") << endl;
    cout << "LCS (abc, ac): " << longestCommonSubsequence("abc", "ac") << endl;
    cout << "Palindromic substrings (ababa): " << countSubstrings("ababa") << endl;
    
    return 0;
}
