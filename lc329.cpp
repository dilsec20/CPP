#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>>* mat;
    vector<vector<int>> memo;
    const int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    int dfs(int r, int c) {
        if (memo[r][c]) return memo[r][c];
        int best = 1;
        for (auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && (*mat)[nr][nc] > (*mat)[r][c]) {
                best = max(best, 1 + dfs(nr, nc));
            }
        }
        memo[r][c] = best;
        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        m = matrix.size();
        n = matrix[0].size();
        mat = &matrix;
        memo.assign(m, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };
    cout << sol.longestIncreasingPath(mat) << '\n'; // expected 4
    return 0;
}
class Solution {
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
    }
};