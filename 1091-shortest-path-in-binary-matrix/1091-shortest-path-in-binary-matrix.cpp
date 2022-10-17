class Solution {
public:
    bool isPossible(int row, int col, int n, vector<vector<int>>& grid)
    {
        if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0) // checking that is it possible to go to new x-cordinate(row) &  y-cordinate(col) 
            return true;
        
        return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if(grid[0][0] == 1) // if starting point is 1 then it means that it is not possible to movie forwart in any direction 
            return -1;
        
        int n = grid.size(); // given that grid is N x N
        
        set<pair<int, pair<int, int>>> s; // set is used to eliminate unnecessary iterations {distance {x-cordinate, y-cordinate}}
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // 2-D vector for storing distance of each cordinate initally having infinite distance
        
        dist[0][0] = 1;
        s.insert({1, {0, 0}});
        
        // for generating 8 directions at each coordinate (left, right, up, down, diagonally)
        int delRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        while(!s.empty())
        {
            auto it = *(s.begin());
            int distance = it.first;
            int r = it.second.first;
            int c = it.second.second;
            s.erase(it);
            
            for(int i=0; i<8; i++)
            {
                // moving in each direction (left, right, up, down, diagonally)
                int row = r + delRow[i];
                int col = c + delCol[i];
                
                if(isPossible(row, col, n, grid) && distance + 1 < dist[row][col]) // checking if it is clear path or not and new distance is less than previous distance
                {
                    if(dist[row][col] != INT_MAX) // if set contains distance for row, col remove it from set
                        s.erase({distance, {row, col}});
                    
                    dist[row][col] = distance + 1;
                    s.insert({distance + 1, {row, col}}); // insert new shortest distance for rowset 
                }
            }
        }
        
        if(dist[n-1][n-1] == INT_MAX) // if last [n-1][n-1] position is still infinity it means there is no  clear path so we return -1
            return -1;
        
        return dist[n-1][n-1]; 
    }
};