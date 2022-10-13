class Solution {
public:
    
    // bool dfsCheck(int node, vector<vector<int>>& graph, vector<int> &vis, vector<int> &dfsvis, vector<int> &safe)
    // {
    //     vis[node]=1;
    //     dfsvis[node]=1;
    //     safe[node]=0;
    //     for(auto it : graph[node])
    //     {
    //         if(!vis[it])
    //         {
    //             if(dfsCheck(it, graph, vis, dfsvis, safe))
    //             {
    //                 safe[node]=0;
    //                 return true;
    //             }
    //         }
    //         else if(dfsvis[it])
    //         {
    //             safe[node]=0;
    //             return true;
    //         }
    //     }
    //     dfsvis[node]=0;
    //     safe[node]=1;
    //     return false;
    // }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> adjRev[n];
        vector<int> indegree(n,0);
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            for(auto it : graph[i])
            {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adjRev[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
    
        sort(ans.begin(), ans.end());
        return ans; 
    }
};