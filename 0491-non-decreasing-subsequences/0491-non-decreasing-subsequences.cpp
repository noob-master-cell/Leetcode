class Solution {
public:
    void helper(vector<int>& nums,set<vector<int>>& ans,int i,vector<int> temp = {}){
        if(i == nums.size())
        {
            if(temp.size() > 1)
            {
                ans.insert(temp);
            }
            return;
        }
        //not-take
        helper(nums,ans,i+1,temp);
        if(temp.size() == 0 || nums[i] >= temp[temp.size() - 1])
        {
            //take
            temp.push_back(nums[i]);
            helper(nums,ans,i+1,temp);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        set<vector<int>> ans;
        helper(nums,ans,0);
        vector<vector<int>> sequences;
        for(vector<int> v : ans)
        {
            sequences.push_back(v);
        }
        return sequences;
    }
};