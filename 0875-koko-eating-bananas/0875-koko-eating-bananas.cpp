class Solution {
public:
    bool isPossible(vector<int> &piles, int totalTime, long long totalBananas)
    {
        int time=0;
        for(int i=0;i<piles.size();i++)
        {
            time += piles[i] / totalBananas;
            
            if(piles[i] % totalBananas != 0)
                time++;
        }
        return time <= totalTime;
    }   
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int ans = -1;
        int start = 1;
        long long end = accumulate(piles.begin(), piles.end(), end);
        
        while(start<=end)
        {
            long long mid = start+(end-start)/2;
            if(isPossible(piles, h, mid))
            {
                ans=mid;
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