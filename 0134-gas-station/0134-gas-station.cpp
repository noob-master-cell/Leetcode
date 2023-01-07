class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        
        if(totalGas < totalCost)
            return -1;
        int start = 0;
        int currGas = 0;
        for(int i=0; i<cost.size(); i++)
        {
            if(currGas < 0)
            {
                start = i;
                currGas = 0;
            }
            currGas += gas[i]-cost[i];
        }
        return start;
    }
};