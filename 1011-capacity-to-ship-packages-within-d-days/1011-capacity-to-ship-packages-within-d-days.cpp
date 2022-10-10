class Solution {
public:
    bool isPossible(vector<int> &weights, int days, int capacity)
    {
        int currCapacity=0;
        int day=1;
        for(int i=0; i<weights.size(); i++)
        {
            currCapacity += weights[i];
            if(currCapacity > capacity)
            {
                day++;
                currCapacity=weights[i];
            }
            if(day > days)
                return false; 
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int start = INT_MIN;
        int end = 0;
        int ans=0;
        for(int i=0;  i<weights.size(); i++)
        {
            start = max(start, weights[i]);
            end += weights[i];
        }
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(isPossible(weights, days, mid))
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return ans;
    }
};