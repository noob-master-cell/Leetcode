class Solution {
public:
    void solve(int node, int dest, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans, vector<int> &vis)
    {
        vis[node] = 1;
        path.push_back(node);
        if(node == dest)
        {
            ans.push_back(path);
            path.pop_back();
            vis[node] = 0;
            return;
        }
        
        for(auto it : graph[node])
        {
            if(!vis[it])
                solve(it, dest, graph, path, ans, vis);
        }
        path.pop_back();
        vis[node] = 0;
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> path;
        vector<vector<int>> ans;
        solve(0, n-1, graph, path, ans, vis);
        return ans;
        
    }
};