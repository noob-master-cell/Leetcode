class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy=0-prices[0];
        int sell=0;
        int cool=0;
        int prev_buy;
        
        for(int i=1; i<prices.size(); i++)
        {
            prev_buy = buy;
            buy = max(buy, cool-prices[i]);
            cool = max(sell, cool);
            sell = max(sell, prices[i]+prev_buy);
        }
        return sell;
    }
};