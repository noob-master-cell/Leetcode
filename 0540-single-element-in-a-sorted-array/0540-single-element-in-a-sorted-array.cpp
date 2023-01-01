class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left<right)
        {
             int mid = left + (right-left)/2;
            
            // mid is odd means subarray [0,mid] length is even
            // single element in the right half if nums[mid]==nums[mid-1], otherwise left half
            if(mid % 2 == 1)
            {
                if(nums[mid] != nums[mid-1])
                    right = mid;
                
                else 
                    left = mid + 1;                
            }
            // mid is even means subarray [0,mid] length is odd
            // single element in the right half if nums[mid]==nums[mid+1], otherwise left half
            else
            {
                if(nums[mid] != nums[mid+1])
                    right = mid;
                
                else 
                    left = mid + 1;
            }            
        }
        
        // after binary search the left element will contain the single element
        return nums[left];
    }
};