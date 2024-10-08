class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans = 0;
        int len=0;
        vector<int> v(256, -1);
        int l=0; 
        int r=0;
        int n = s.size();
        while(r<n)
        {
            if(v[s[r]] != -1)
                    l = max(v[s[r]] + 1, l);
            
            len = r-l+1;
            ans = max(ans, len);
            
            v[s[r]] = r;
            r++;
        }
        return ans;
    }
};