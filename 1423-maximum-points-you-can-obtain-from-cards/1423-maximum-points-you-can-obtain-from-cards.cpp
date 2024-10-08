class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int lsum=0;
        int rsum=0;
        int n = cardPoints.size()-1;
        int sum = 0;
        int maxi = INT_MIN;
        
        for(int i=0; i<k; i++)
            lsum += cardPoints[i]; 
        
        maxi = lsum;
        k--;
        while(k>=0)
        {
            
            rsum += cardPoints[n];
            lsum -= cardPoints[k];
            sum = lsum+rsum;
            maxi = max(maxi, sum);
            n--;
            k--;
        }
        return maxi;
    }
};