class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) 
    {
        auto cmp = [&](pair<int, int>& a, pair<int, int>& b)
        {
            if(a.second == b.second)
                return a.first<=b.first;
            
            return a.second>b.second;
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++; 
        
        for(auto x : mp)
            pq.push(x);
        
        while(!pq.empty())
        {
            int num = pq.top().first;
            int freq = pq.top().second;
            pq.pop();
            while(freq--)
                ans.push_back(num);
        }
        
        return ans;
    }
};