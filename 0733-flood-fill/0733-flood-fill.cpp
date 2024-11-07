class Solution {
public:
    void dfs(vector<vector<int>>& ans, int row, int col, int val, int color)
    {
        if(row<0 || col<0 || col>=ans[0].size() || row>=ans.size() || ans[row][col] == color || ans[row][col]!= val)
            return;
        ans[row][col] = color;
        dfs(ans, row+1, col, val, color);
        dfs(ans, row-1, col, val, color);
        dfs(ans, row, col+1, val, color);
        dfs(ans, row, col-1, val, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        vector<vector<int>> ans = image;
        int val = image[sr][sc];
        
        dfs(ans, sr, sc, val, newColor);
        
        return ans;
    }
};