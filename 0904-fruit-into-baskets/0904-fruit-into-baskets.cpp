class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int l = 0;
        int r = 0;
        int len = 0;
        map<int, int> mp;
        
        while(r<fruits.size())
        {
            mp[fruits[r]]++;
            if(mp.size()>2)
            {
                if(mp.size()>2)
                {
                    mp[fruits[l]]--;
                    if(mp[fruits[l]] == 0)
                        mp.erase(fruits[l]);
                    l++;
                }
            }
            if(mp.size()<=2)
                len = max(len, (r-l+1));
            r++;
        }
        return len;
    }
};