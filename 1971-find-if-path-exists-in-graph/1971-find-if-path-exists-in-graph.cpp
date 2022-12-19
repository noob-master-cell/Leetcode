class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {   
        //Simple BFS
        vector<int> adj[n];
        //Form graph form given edges
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        //Visited vector make it 0
        vector<int> vis(n, 0);
        queue<int> q;
        ///Push source in queue
        q.push(source);
        vis[source] = 1;
        // Do simple BFS
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            for(auto it : adj[v])
            {
                if(vis[it] == 0)
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        //After bfs if destination in visited vector if 1 it means path exists if it is still 0 then path does not exist
        return vis[destination];
    }
};