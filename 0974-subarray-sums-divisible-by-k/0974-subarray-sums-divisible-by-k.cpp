class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        map<int, int> m;
        m[0]=1;

        int subarray=0;
        int sum=0;
        int rem=0;

        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            rem = sum%k;
            
            if(rem<0)
               rem += k;
            
            if(m[rem]>=1)
            {
                subarray += m[rem];
                m[rem]++;
            }

            else 
                m[rem]++;
        }

        return subarray;
    }
};