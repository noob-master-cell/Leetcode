class Solution {
public:
    bool isClockwiseTurn(vector<int> &a, vector<int> &b, vector<int> &c) 
    {
        int xa = a[0], xb = b[0], xc = c[0];
        int ya = a[1], yb = b[1], yc = c[1];
        bool isConvex = (((yc - yb) * (xb - xa)) - ((yb - ya) * (xc - xb))) >= 0;
        return isConvex;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees){
        vector<vector<int>> v;
        int n = trees.size();
       
        auto cmp = [&](vector<int> &a, vector<int> &b) 
        {
            if(a[0] < b[0])
                return true;
            
            else if (a[0] == b[0] && a[1] < b[1])
                return true;
            
            return false;
        };
        
        sort(trees.begin(), trees.end(), cmp);
        
        for(int i = 0; i < n; i++) 
        {
            while(v.size() > 1 && !isClockwiseTurn(v[v.size() - 2], v[v.size() - 1], trees[i])) 
                v.pop_back();
            
            v.push_back(trees[i]);
        }
        
        for(int i = n - 1; i >= 0; i--) 
        {
            while(v.size() > 1 && !isClockwiseTurn(v[v.size() - 2], v[v.size() - 1], trees[i]))
                v.pop_back();
            
            v.push_back(trees[i]);
        }
        v.pop_back(); 
        sort(v.begin(), v.end(), cmp);
        v.erase(unique(v.begin(), v.end()), v.end());
        return v;
    }
};