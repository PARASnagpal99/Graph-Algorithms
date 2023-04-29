class Tarjan {
public:
    int t = 1 ;
        
    void dfs(int src , int par , vector<int> graph[] , vector<int>&In , vector<int>&low , vector<vector<int>>&bridges){
         In[src] = low[src] = t++;
         
         for(auto &it : graph[src]){
             if(it == par) continue ;
             if(In[it] == 0){
                 dfs(it , src , graph , In , low , bridges);
                 low[src] = min(low[src] , low[it]);
                 
                 // checking for bridge bw src and it 
                 if(low[it] > In[src]){
                     bridges.push_back({it,src});
                 }
                 
             }else{
                 low[src] = min(low[src] , low[it]);
             }
         }
        
    }
    
    
    
    
    vector<vector<int>> FindBridges(int n, vector<vector<int>>& edges) {
         vector<int> graph[n] ;
        
         for(auto &it : edges){
             graph[it[0]].push_back(it[1]);
             graph[it[1]].push_back(it[0]);
         }
        
    
         vector<int> In(n , 0);
         vector<int> low(n , 0);
         vector<vector<int>> bridges ;
        
         dfs(0 , -1 , graph , In , low , bridges);
        
         return bridges ;
        
        
    }
};
