class Solution {
public:
    void solve(string& s, int pos, string curr, string num, int dots, vector<string> &ans)
    {
        if(pos == s.size())
        {
            if(dots == 3) 
                ans.push_back(curr);
            return;
        }
        
        if(num!="0" && stoi(num + s[pos])<=255)  
            solve(s, pos+1, curr+s[pos], num+s[pos], dots, ans);
        
        if(curr.back() != '.' && dots<3) 
            solve(s, pos, curr+'.', "", dots+1, ans);
    }
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> ans;
        
        if(s.size()<4) 
            return ans;
        
        string curr(1, s[0]);
        
        solve(s, 1, curr, curr, 0, ans);
        
        return ans;
    }
};