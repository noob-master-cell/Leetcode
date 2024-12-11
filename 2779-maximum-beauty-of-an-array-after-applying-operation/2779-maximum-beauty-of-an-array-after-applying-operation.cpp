class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());

        int l=0;
        int r=0;
        int maxlen=1;
        int n=nums.size();
        
        while(r<n)
        {
          if(nums[r]-nums[l] <= 2*k)
          {
            maxlen = max(maxlen, r-l+1);
            r++;
          }
          
            while(r<n && nums[r]-nums[l] > 2*k && r >= l)
              l++; 
        }

        return maxlen;
    }
};