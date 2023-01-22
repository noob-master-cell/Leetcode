class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for (const auto & e : prerequisites)
        {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0) {q.push(i);}
        }

        vector<unordered_set<int>> topo(n);
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (auto v : adj[u])
            {
                topo[v].insert(topo[u].begin(), topo[u].end());
                topo[v].insert(u);

                indegree[v] --;
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        vector<bool> ans;
        for (auto &q : queries)
        {
            int u = q[0], v = q[1];
            ans.push_back(topo[v].find(u) != topo[v].end());
        }

        return ans;
    }
};