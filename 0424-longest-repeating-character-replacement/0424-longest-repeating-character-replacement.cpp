class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int l = 0; 
        int r = 0; 
        int n =s.size();
        int freq = 0;
        int maxlen = 0;
        map<char, int> mp;
        
        while(r < n)
        {
            mp[s[r]]++;
            freq = max(freq, mp[s[r]]);
            int change = r - l + 1 - freq;
            if(change <= k)
            {
                maxlen = max(maxlen, (r - l + 1)); 
            }
            if(change > k)
            {
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                   mp.erase(mp[s[l]]);
                    
                l++;
            }
            r++;       
        }
        return maxlen;           
    }
};