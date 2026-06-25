class Solution {
private:
    int n;
    vector<vector<int>>* gridPtr;
    vector<vector<bool>> visited;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool canReach(int row, int col, int maxTime) {
        if (row == n - 1 && col == n - 1) {
            return true;
        }
        
        visited[row][col] = true;
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + dirs[i][0];
            int newCol = col + dirs[i][1];
            
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n 
                && !visited[newRow][newCol] && (*gridPtr)[newRow][newCol] <= maxTime) {
                if (canReach(newRow, newCol, maxTime)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        gridPtr = &grid;
        
        int left = grid[0][0];
        int right = n * n - 1;
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            visited.assign(n, vector<bool>(n, false));
            
            if (canReach(0, 0, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
};
