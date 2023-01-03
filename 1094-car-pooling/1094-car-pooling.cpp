class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<int> total(1001, 0);
        for(auto it : trips)
        {
            total[it[1]] += it[0];
            total[it[2]] -= it[0];
        }
        int curr_cap = 0;
        for(int curr : total)
        {
            curr_cap += curr;
            if(curr_cap > capacity)
                return false;
        }
        return true;
    }
};