class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int, int>> adj[n];
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;
            
            if(stops > k)
                continue;
            
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int adjPrice = it.second;
                if(price + adjPrice < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = price + adjPrice;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==INT_MAX)
            return -1;
        
        return dist[dst];
    }
};