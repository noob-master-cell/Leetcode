class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int dist = it[2];
            
            distance[u][v] = dist;
            distance[v][u] = dist;
        }
        
        for(int i=0; i<n; i++)
            distance[i][i] = 0;
        
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(distance[i][k] == INT_MAX || distance[k][j] == INT_MAX)
                        continue;
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        int cityNo = -1;
        int totalCity = n;
        
        for(int city=0; city<n; city++)
        {
            int cityCount = 0;
            for(int adjCity=0; adjCity<n; adjCity++)
            {
                if(distance[city][adjCity] <= distanceThreshold)
                    cityCount++;
            }
            if(cityCount <= totalCity)
            {
                totalCity = cityCount;
                cityNo = city;
            }
        }
        return cityNo;
    }
};