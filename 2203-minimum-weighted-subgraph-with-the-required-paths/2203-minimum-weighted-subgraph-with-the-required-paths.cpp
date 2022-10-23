class Solution {
public:
     void solve(vector<vector<pair<int, int>>> &adj, vector<long long> &dist, int src)
    {
        set<pair<long long, long long>> s;
        s.insert({0, src});
        dist[src] = 0;
        while(!s.empty())
        {
            auto it = *(s.begin());
            int node = it.second;
            long long dis = it.first;
            s.erase(it);
            
            for(auto i : adj[node])
            {
                int adjNode = i.first;
                long long adjDis = i.second;
                if(dis + adjDis < dist[adjNode])
                {
                    if(dist[adjNode] != LONG_MAX)
                        s.erase({dist[adjNode], adjNode});
                        
                    dist[adjNode] = dis + adjDis;
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        vector<vector<pair<int, int>>> adj(n), adjRev(n);
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adjRev[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> dist1(n, LONG_MAX);
        vector<long long> dist2(n, LONG_MAX);
        vector<long long> dist3(n, LONG_MAX);
        
        solve(adj, dist1, src1);
        solve(adj, dist2, src2);
        solve(adjRev, dist3, dest);
        
        long long ans = LONG_MAX;
        
        for(int i=0; i<n; i++)
        {
            if(dist1[i] == LONG_MAX  || dist2[i] == LONG_MAX || dist3[i] == LONG_MAX)
                continue;
            ans = min(ans, dist1[i] + dist2[i] + dist3[i]);
        }
        
        if(ans==LONG_MAX)
            return -1;
        
        return ans;
    }
};