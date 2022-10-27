class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        int n=img1.size();
        vector<pair<int,int>> v1, v2;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(img1[i][j] == 1)
                    v1.push_back({i, j});
                
                if(img2[i][j] == 1)
                    v2.push_back({i, j});
            }
        }
        int ans = 0;
        map<pair<int, int>, int> mp;
        for(auto i : v1)
        {
            for(auto j : v2)
            {
                int a = i.first - j.first;
                int b = i.second - j.second;
                
                mp[{a,b}]++;
                
                ans = max(ans, mp[{a, b}]);
            } 
        }
        return ans;
    }
};