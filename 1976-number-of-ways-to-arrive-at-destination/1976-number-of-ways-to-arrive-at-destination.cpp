class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        int mod = (int)(1e9 + 7);
        vector<pair<long long, long long>> adj[n];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        vector<long long> dist(n, LONG_MAX);
        vector<int> ways(n, 0);
        
        ways[0] = 1;
        q.push({0, 0});
        dist[0] = 0;
        
        while(!q.empty())
        {
            long long node = q.top().second;
            long long time = q.top().first;
            q.pop();
            
            for(auto it : adj[node])
            {
                long long adjNode = it.first;
                long long adjTime = it.second;
                
                if(time + adjTime < dist[adjNode])
                {
                    dist[adjNode] = time + adjTime;
                    q.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(time + adjTime == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] +  ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};