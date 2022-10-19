class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        priority_queue<pair<int, string>> pq; 
        
        unordered_map<string, int>m;
        
        for(int i=0;i<words.size();i++)
            m[words[i]]++;
        
        for(auto i : m)
        {
            pq.push({-i.second, i.first});
            while(pq.size()>k)
                pq.pop();
        }
        
        vector<string> ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;    
    }
};