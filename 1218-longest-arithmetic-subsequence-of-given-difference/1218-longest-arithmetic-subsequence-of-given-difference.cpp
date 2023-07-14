class Solution {
public:
    int longestSubsequence(vector<int>& a, int diff) 
    {
        int n = a.size();
        int ans = 1; // Initialize the length of the longest subsequence found so far
        unordered_map<int, int> dp; // Map to store the length of subsequence ending at each element

        for (int i = 0; i < n; ++i) 
        {
            // Compute the length of subsequence ending at current element a[i]
            // by adding 1 to the length of subsequence ending at a[i] - diff
            dp[a[i]] = dp[a[i] - diff] + 1;
            ans = max(ans, dp[a[i]]); // Update the maximum length
        }
        return ans;
    }
};