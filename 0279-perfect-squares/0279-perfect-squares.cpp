class Solution {
public:
    int numSquares(int n) 
    {
        vector <int> dp(n + 1, INT_MAX);
        dp[0] = dp[1] = 1;
        double d = sqrt(n);
        int val = floor(d);

        if(val * val == n)
            return 1;

        for(int i = 1; i <= val; i++)
            dp[i * i] = 1;

        for(int i = 2; i <= n; i++) 
        {
            double d = sqrt(i);
            int val = floor(d);

            for(int j = val; j >= 1; j--)
                dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
        }

        return dp[n];
    }
};