class Solution {
public:
    int edgeScore(vector<int>& edges) 
    {
        int n = edges.size();
        vector<long long> edgeScore(n, 0);
        long long score = INT_MIN;
        int ans = -1;
        for(int i=0; i<n; i++)
            edgeScore[edges[i]] += i;
        
        for(int i=0; i<n; i++)
        {
            if(score < edgeScore[i])
            {
                score = edgeScore[i];
                ans = i;
            }
        }
        return ans;
    }
};