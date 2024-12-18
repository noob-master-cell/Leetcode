class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        stack<int> s;
        vector<int> res(prices);
        int n = prices.size();
        s.push(prices.back());
        
        for(int i=n-2; i>=0; i--)
        {
            while(!s.empty() && s.top()> prices[i])
                s.pop();
            
            if(!s.empty()) 
                res[i]-=s.top();
            
            s.push(prices[i]);
        }
        return res;
    }
};