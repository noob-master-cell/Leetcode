class Solution {
public:
      string orderlyQueue(string s, int k) 
      {
        if(k > 1) 
        {
            sort(s.begin(), s.end());
            return s;
        }
        
        int n = s.size();
        string res = s;
        s += s;
        for(int i=0; i<n; i++) 
            if(s.substr(i, n) < res) 
                res = s.substr(i, n);
        return res;
    }
};