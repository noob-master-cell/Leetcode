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
            for(auto i:rooms[val])
            {
                if(!vis.count(i))
                {
                    q.push(i);
                    vis.insert(i);
                }
            }
        }
        return (vis.size()==rooms.size());
    }
};