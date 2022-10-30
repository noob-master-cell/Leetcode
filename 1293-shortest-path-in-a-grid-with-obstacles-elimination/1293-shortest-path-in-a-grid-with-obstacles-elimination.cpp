class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        
        int delRow[4] = {0, 1, 0, -1};
        int delCol[4] = {1, 0, -1, 0};
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;  i<size; i++)
            {
                int x = q.front()[0];
                int y = q.front()[1];
                int step = q.front()[2];
                int newk = q.front()[3];
                q.pop();
                
                if(x == row-1 && y == col-1) 
                    return step;
                
                if(x < 0 || x >= row || y < 0 || y >= col) 
                    continue; 
                
                if(vis[x][y] != -1 && vis[x][y] >= newk) 
                    continue;
                
                if(grid[x][y] == 1)
                {
                    if(newk > 0) 
                        newk--;
                    else 
                        continue;
                }
                vis[x][y] = newk;
                
                for(int i=0; i<4; ++i)
                {
                    int nRow = x + delRow[i];
                    int nCol = y + delCol[i];
                    q.push({nRow, nCol, step+1, newk});
                }
            }
        }
        return -1;
    }
};