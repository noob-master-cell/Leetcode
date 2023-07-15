class Solution {
public:
    int helper(vector<vector<int>>& events, int k, int pos, int n, vector<vector<int>>& dp) 
    {
        // Base case if there are no more events to attend or k events have already attended
        if (pos >= n || k == 0) 
        {
            return 0;
        }

        // If the subproblem has already solved return its value
        if (dp[pos][k] != -1) 
        {
            return dp[pos][k];
        }
        int i;
        vector<int> temp = {events[pos][1], INT_MAX, INT_MAX};
        i = upper_bound(begin(events) + pos + 1, end(events), temp) - begin(events);
        // Recursively calculate the maximum sum of values
        int maxSum = max(helper(events, k, pos + 1, n, dp), helper(events, k - 1, i, n, dp) + events[pos][2]);
        return dp[pos][k] = maxSum;
    }

    int maxValue(vector<vector<int>>& events, int k) 
    {
        int n = events.size();
        // Sort the events based on the start day
        sort(begin(events), end(events));
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return helper(events, k, 0, n, dp);
    }
};