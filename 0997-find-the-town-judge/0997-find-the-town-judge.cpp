class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> inDegree(n+1, 0);
        vector<int> outDegree(n+1, 0);
        for(auto it : trust)
        {
            outDegree[it[0]]++;
            inDegree[it[1]]++;
        }
        for(int i=1; i<=n; i++)
        {
            if(outDegree[i] == 0 && inDegree[i] == n-1) // town judge trusts nobody -> outDegree[judge] = 0
                return i;
        }
        return -1;
    }
};