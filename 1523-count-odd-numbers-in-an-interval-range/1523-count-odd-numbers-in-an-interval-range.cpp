class Solution {
public:
    int countOdds(int low, int high) 
    {
        int n = (high - low) / 2;
     
        if(low%2 != 0 || high%2 != 0)
            n += 1;
        return n;
    }
};