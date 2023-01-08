class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int ans = 1; 
        int count = 0;
        int n = points.size();
        
        for(int i=0; i<n-1; i++)
        {
            map<double,int> m;
            for(int j=i+1;j<n;j++)
            {
                if(points[j][1]==points[i][1]) // if line is perpendicular
                    m[-90]++;
                
                else // calculate slope between two points
                { 
                    double slope = (double)(points[j][0]-points[i][0])/(double)(points[j][1]-points[i][1]);
                    m[slope]++;
                }
            }
        
            for(auto it: m)
                count = max(count, it.second+1);
            
            ans = max(count, ans);
        }
        return ans;
    }
};