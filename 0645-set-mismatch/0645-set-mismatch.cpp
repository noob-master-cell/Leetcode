class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {    
        unordered_map<int,int> m;
        int a,b;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;
    
        for(auto it : m)
          if(it.second == 2)
              a= it.first;
    
        for(int i=1; i<=nums.size(); i++)
          if(m[i] == 0)
              b = i;
          
        return {a, b};
    }
};