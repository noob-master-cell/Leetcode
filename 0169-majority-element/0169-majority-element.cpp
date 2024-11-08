class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int el = nums[0];
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(count == 0)
            {
                el = nums[i];
                count++;
            }
            else if(nums[i] == el)
                count++;
            else
                count--;
        }
        return el;
    }
};