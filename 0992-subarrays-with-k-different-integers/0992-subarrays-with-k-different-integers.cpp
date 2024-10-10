class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    { 
        return findSubarrays(nums, k) - findSubarrays(nums, k-1);
    }
    int findSubarrays(vector<int> &nums, int k)
    {
        int i=0; int j=0;
        unordered_map<int, int> mp;
        int n = nums.size();
        int count = 0;

        while(j < n)
        {
            mp[nums[j]]++;
            
            while(mp.size()>k)
            {
                mp[nums[i]]--;
                
                if(mp[nums[i]] == 0) 
                    mp.erase(nums[i]);
                
                i++;
            }
            
            count += (j-i+1);
            j++;
        }

        return count;
    }
};