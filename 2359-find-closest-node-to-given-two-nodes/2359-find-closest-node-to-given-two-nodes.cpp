class Solution {
public:
    void solve(vector<vector<pair<int, int>>> &adj, vector<int> &dist, int src)
    {
        set<pair<int, int>> s;
        s.insert({0, src});
        dist[src] = 0;
        while(!s.empty())
        {
            auto it = *(s.begin());
            int node = it.second;
            int dis = it.first;
            s.erase(it);
            
            for(auto i : adj[node])
            {
                int adjNode = i.first;
                int adjDis = i.second;
                if(dis + adjDis < dist[adjNode])
                {
                    if(dist[adjNode] != INT_MAX)
                        s.erase({dist[adjNode], adjNode});
                        
                    dist[adjNode] = dis + adjDis;
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<n; i++)
        {
            if(edges[i] != -1)
                adj[i].push_back({edges[i], 1});
        }
        
        vector<int> distance_node1(n, INT_MAX);
        vector<int> distance_node2(n, INT_MAX);
        
        solve(adj, distance_node1, node1);
        solve(adj, distance_node2, node2);
        
        int ans = INT_MAX;
        int node = -1;
        for(int i=0;  i<n; i++)
        {
            int distance = max(distance_node1[i], distance_node2[i]);
            if(distance < ans)
            {
                ans = distance;
                node = i;
            }
        }
        return node;   
    }
};