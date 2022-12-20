class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        queue<int> q;
        unordered_set<int> vis;
        vis.insert(0);
        q.push(0);
        
        while(!q.empty())
        {
            int val= q.front();
            q.pop();
            for(auto it : rooms[val])
            {
                if(!vis.count(it))
                {
                    q.push(it);
                    vis.insert(it);
                }
            }
        }
        return vis.size() == rooms.size();
    }
};