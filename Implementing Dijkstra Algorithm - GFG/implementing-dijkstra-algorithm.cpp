//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {                         
    //                          SET SOLUTION
        set<pair<int, int>> s;
        vector<int> dist(V, 1e9);
        
        s.insert({0, S});
        dist[S]=0;
        
        while(!s.empty())
        {
            auto it = *(s.begin());
            int node = it.second;
            int dis = it.first;
            s.erase(it);
            
            for(auto it : adj[node])
            {
                int adjNode = it[0];
                int weight = it[1];
                if(dis + weight < dist[adjNode])
                {
                    if(dist[adjNode] != 1e9)
                        s.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis + weight;
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
        
        
        
    //                          PRIORITY QUEUE SOLUTION
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    //     vector<int> dist(V, 1e9);
    //     q.push({0, S});
    //     dist[S]=0;
        
    //     while(!q.empty())
    //     {
    //         int node = q.top().second;
    //         int dis = q.top().first;
    //         q.pop();
    //         for(auto it : adj[node])
    //         {
    //             int adjNode = it[0];
    //             int weight = it[1];
    //             if(dis + weight < dist[adjNode])
    //             {
    //                 dist[adjNode] = dis + weight;
    //                 q.push({dist[adjNode], adjNode});
    //             }
    //         }
    //     }
    //     return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends