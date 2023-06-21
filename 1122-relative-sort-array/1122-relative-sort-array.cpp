class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m= b.size();
        vector<int> res;
    unordered_map<int, int> mp;
    for(int i : a)
        mp[i]++;

    sort(a.begin(), a.end());
    for(int i : b)
    {
        auto it = mp.find(i);
        int count = it->second;
        while(count--)
        {
            res.push_back(it->first);
            auto val = find(a.begin(), a.end(), it->first);
            a.erase(val);
        }
    }
    for(int i : a)
        res.push_back(i);
    
    return res;
        
    }
};