class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int ans = 1;
        int mini = INT_MAX;
        
        sort(points.begin(), points.end());
        
        for(auto it : points)
        {
            if(it[0] > mini)
            {
                ans += 1;
                mini = it[1];
            }
            else
                mini = min(mini, it[1]);
        }
        return ans;
    }
};