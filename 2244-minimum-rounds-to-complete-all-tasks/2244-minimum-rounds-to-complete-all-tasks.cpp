class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        sort(tasks.begin(), tasks.end());
        int count = 0;
        unordered_map<int, int> m;
        for(auto it : tasks)
            m[it]++;
        
        int ans = 0;
        
        for(auto it : m)
        {
            count = it.second;
            if(count == 1)
                return -1;
            if(count%3 == 0)
                ans += count/3;
            else
                ans += count/3 +1;
        }
        return ans;
    }
};