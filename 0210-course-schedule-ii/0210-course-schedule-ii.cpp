class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) 
    {
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        vector<int>adj[numCourses]; 
        
        for(int i=0; i<pre.size(); i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        
        for(int i=0; i<numCourses; i++)
        {
            for(auto it : adj[i])
                indegree[it]++;
        }
        
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int count=0;
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            ans.insert(ans.begin(), node);
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(count==numCourses)
            return ans;
        return {};
    }
};