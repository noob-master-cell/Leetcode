class Solution {
public:
    int dfs(int start, int n, vector<vector<int>>& graph, vector<bool>& hasApple, vector<bool>& visited) 
    {
        int time = 0, childTime;

        for(auto i: graph[start]) 
        {
            if(!visited[i]) 
            {
                visited[i] = true;
                childTime = dfs(i, n, graph, hasApple, visited);
                if(childTime != 0 || hasApple[i])
                    time += (childTime + 2);
            }
        }

        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        
        for(auto& edge: edges) 
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        visited[0] = true;
        return dfs(0, n, graph, hasApple, visited);
    }
};