//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	#define ii pair<int,int>
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
         vector<int> vis(V) ; // visited array 
         priority_queue<ii,vector<ii>,greater<ii>>pq ; // Min heap 
         // {wt , node} 
         int sum = 0 ; // Mst Sum 
         pq.push({0,0}) ;
         
         while(!pq.empty()){
             auto curr = pq.top() ;
             pq.pop() ;
             
             int node = curr.second ;
             int wt = curr.first ;
             
             if(vis[node] == 1) continue ;
             
             vis[node] = 1 ;
             sum += wt ;
             
             for(auto &it : adj[node]){
                 int u = it[0] ;
                 int w = it[1] ;
                 if(!vis[u]){
                     pq.push({w,u});
                 }
             }
         }
         
         return sum ;
         
         
         
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
