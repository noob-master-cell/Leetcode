class Solution {
    vector<vector<int>> adj;
    int freq[26] = {};
    vector<int> answer;

    void dfs(int node, int parent, const string& labels) 
    {
        int iChar = labels[node] - 'a';
        int prevFreq = freq[iChar];
        freq[iChar] = 0;

        for (int child : adj[node]) 
        {
            if (child == parent)
                continue;
            dfs(child, node, labels);
        }

        answer[node] = ++freq[iChar];
        freq[iChar] += prevFreq;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        adj.resize(n);
        for (const auto& edge : edges) 
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        answer.resize(n);
        dfs(0, -1, labels);
        return answer;
    }
};