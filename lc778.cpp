/*
LeetCode 778 - Swim in Rising Water

Problem:
- n x n grid with integer elevations in each cell
- Start at (0,0), reach (n-1, n-1)
- At time t, can only visit cells with elevation <= t
- Find minimum time t to reach destination

Approach: Dijkstra's Algorithm (Priority Queue)
- Use min-heap to always process cell with minimum max elevation
- For each cell, track the maximum elevation encountered on the path
- The answer is the maximum elevation on the optimal path

Time: O(n² log n²) = O(n² log n)
Space: O(n²)
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Priority queue: {max_elevation_so_far, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        
        // Visited array
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Directions: up, down, left, right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Start from (0, 0) with elevation grid[0][0]
        pq.push({grid[0][0], {0, 0}});
        int maxTime = 0;
        
        while (!pq.empty()) {
            auto [currentMax, pos] = pq.top();
            pq.pop();
            
            int row = pos.first;
            int col = pos.second;
            
            // If already visited, skip
            if (visited[row][col]) continue;
            
            visited[row][col] = true;
            maxTime = max(maxTime, currentMax);
            
            // If reached destination, return the answer
            if (row == n - 1 && col == n - 1) {
                return maxTime;
            }
            
            // Explore all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int newRow = row + dirs[i][0];
                int newCol = col + dirs[i][1];
                
                // Check bounds and visited
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n 
                    && !visited[newRow][newCol]) {
                    int newMax = max(currentMax, grid[newRow][newCol]);
                    pq.push({newMax, {newRow, newCol}});
                }
            }
        }
        
        return maxTime;
    }
};

/*
Example:
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The path is (0,0) -> (0,1) -> ... -> (4,4)
We need to wait until time 16 to visit all cells in the optimal path.

Key Points:
- Dijkstra's ensures we find the path with minimum maximum elevation
- The heap processes cells by minimum max elevation encountered
- We stop when we reach the destination
- The answer is the maximum elevation on that optimal path
*/
