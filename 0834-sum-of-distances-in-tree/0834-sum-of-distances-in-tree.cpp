class Solution {
public:  
    void count(vector<vector<int>> &adj, int u, int parent, vector<int> &ans, vector<int> &Nodes)
    {
        for(auto v : adj[u])
        {
            if(v == parent)
                continue;
            
            count(adj, v, u, ans, Nodes);
            
            Nodes[u] += Nodes[v];
            
            ans[u] += ans[v] + Nodes[v];
        }
        
        Nodes[u]++;
    }
    
    void distance(vector<vector<int>> &adj, int u, int parent, vector<int> &ans, vector<int> &Nodes)
    {
        for(auto v : adj[u])
        {
            if(v == parent)
            {
                continue;
            }
            
            ans[v] = ans[u] - Nodes[v] + (adj.size() - Nodes[v]);
            
            distance(adj, v, u, ans, Nodes);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        vector<int> ans(n, 0);
        vector<int> Nodes(n, 0);
        
        // creating adjacency list
        vector<vector<int>> adj(n);
        
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // calculating all the nodes in a subtree
        count(adj, 0, -1, ans, Nodes);
        
        // calculating distances for each node to every other nodes 
        distance(adj, 0, -1, ans, Nodes);
        
        return ans;
    }
};