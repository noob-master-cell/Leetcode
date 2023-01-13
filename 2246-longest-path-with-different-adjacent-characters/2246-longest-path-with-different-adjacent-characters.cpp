class Solution {
public:
    int longestPathDownFrom(vector<vector<int>>& graph, int u, const string& s, int& ans) 
    {
        int max1 = 0;
        int max2 = 0;

        for(int v : graph[u]) 
        {
            int res = longestPathDownFrom(graph, v, s, ans);
            if(s[u] == s[v])
                continue;
            if(res > max1) 
            {
                max2 = max1;
                max1 = res;
            } 
            else if(res > max2) 
            {
                max2 = res;
            }
        }
        ans = max(ans, 1 + max1 + max2);
        return 1 + max1;
    }
    int longestPath(vector<int>& parent, string s) 
    {
        int n = parent.size();
        int ans = 1;
        vector<vector<int>> graph(n);

        for(int i = 1; i < n; ++i)
          graph[parent[i]].push_back(i);

        longestPathDownFrom(graph, 0, s, ans);
        return ans;
  }
};