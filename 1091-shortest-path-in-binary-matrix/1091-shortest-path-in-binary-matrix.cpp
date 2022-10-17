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
        if(grid[0][0] == 1)
            return -1;
        
        int n = grid.size(); // given that grid is N x N
        
        set<pair<int, pair<int, int>>> s; // {distance {x-cordinate, y-cordinate}}
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // 2-D vector for storing distance of each cordinate initally having infinite distance
        
        dist[0][0] = 1;
        s.insert({1, {0, 0}});
        
        int delRow[] = {-1,-1,-1,0,0,1,1,1};
        int delCol[] = {-1,0,1,-1,1,-1,0,1};
        
        while(!s.empty())
        {
            auto it = *(s.begin());
            int distance = it.first;
            int r = it.second.first;
            int c = it.second.second;
            s.erase(it);
            
            for(int i=0; i<8; i++)
            {
                int row = r + delRow[i];
                int col = c + delCol[i];
                
                if(isPossible(row, col, n, grid) && distance + 1 < dist[row][col])
                {
                    if(dist[row][col] != INT_MAX)
                        s.erase({distance, {row, col}});
                    
                    dist[row][col] = distance + 1;
                    s.insert({distance + 1, {row, col}});
                }
            }
        }
        
        if(dist[n-1][n-1] == INT_MAX)
            return -1;
        
        return dist[n-1][n-1];
    }
};