class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int l=1, h=1e9;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            int idx=lower_bound(arr.begin(), arr.end(), mid)-arr.begin();
            
            int miss=mid-idx;
            
            if(miss<=k) 
                l=mid+1;
            else 
                h=mid-1;
        }
        return h;
    }
};