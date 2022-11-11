class Solution {
public:
    int solve(vector<vector<int>> &dp, int i, int j, int n, int m)
    {
        if(i==(n-1) && j==(m-1)) //Reached destination so it is ppossible solution we return 1
            return 1;
        if(i>=n || j>=m) //Goes out of grid so we return 0
            return 0;
        if(dp[i][j]!=-1) // if subProblem is already solved and stored
           return dp[i][j];
        else
            return dp[i][j] = solve(dp, i+1, j, n, m) + solve(dp, i,j+1, n, m); // moving right and down in grid
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n,-1)); // DP vector (m x n)
        return solve(dp, 0, 0, m, n);    
    }
};