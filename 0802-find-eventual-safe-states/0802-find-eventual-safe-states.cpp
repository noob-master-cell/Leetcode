class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int> &vis, vector<int> &dfsvis, vector<int> &safe)
    {
        vis[node]=1;
        dfsvis[node]=1;
        safe[node]=0;
        for(auto it : graph[node])
        {
            if(!vis[it])
            {
                if(dfsCheck(it, graph, vis, dfsvis, safe))
                {
                    safe[node]=0;
                    return true;
                }
            }
            else if(dfsvis[it])
            {
                safe[node]=0;
                return true;
            }
        }
        dfsvis[node]=0;
        safe[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        int m = graph[0].size();
        vector<int> vis(n,0);
        vector<int> dfsVis(n,0);
        vector<int> safe(n, 0);
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfsCheck(i, graph, vis, dfsVis, safe);
            }
        }
    
        for(int i=0; i<n; i++)
        {
            if(safe[i]==1)
                ans.push_back(i);
        }
        return ans; 
    }
};