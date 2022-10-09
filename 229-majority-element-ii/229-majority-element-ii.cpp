class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int, int> m;
        for(auto it : nums)
            m[it]++;
        for(auto it : m)
        {
            if(it.second>n/3)
                ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};