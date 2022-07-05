/*  ੴ   Satnam Waheguru */
#include<bits/stdc++.h>
#define REP(it,n) for(int i=it; i<n; i++)
#define mod 1000000007
#define int long long
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define ll long long
#define INF 1000000000
#define prDouble(x) cout << fixed << setprecision(10) << x  
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
void solve(){
    	int n , m ;
    	cin >> n >> m ;
    	vector<pair<int,int>> graph[n+1] ;  // (node,weight) 
    	vector<int> dist(n+1,INF) ;
    	for(int i=0 ; i<m ; ++i){
    		int u , v , wt ;
    		cin >> u >> v >> wt ;
    		graph[u].pb({v,wt});
    		graph[v].pb({u,wt});
    	}
    	
    	// (dist , node) , min heap 
    	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;
    	
    	int source ;
    	cin >> source ;
    	
    	pq.push({0,source});
    	dist[source] = 0 ;
    	
    	while(!pq.empty()){
    		//auto curr_dist = pq.top().first ;
    		auto curr_node = pq.top().second ;
    		pq.pop() ;
    		
    		for(auto &it : graph[curr_node]){
    			auto child_node = it.first ;
    			auto child_wt = it.second  ;
    			
    			if(dist[child_node] > dist[curr_node] + child_wt){
    				dist[child_node] = dist[curr_node] + child_wt ;
    				pq.push({dist[child_node],child_node}) ;
    			}
    		}
    	}
    	
    	cout << "Dist from source to nodes are : " ;
    	for(int i=0 ; i<n ; ++i){
    		cout << dist[i] << " " ;
    	}
    	cout << endl ;
    	
    	
}

int32_t main(){
 	 ios_base::sync_with_stdio(false); cin.tie(NULL); // fast input output
      int t ;
     // cin >> t ;
      t = 1 ;
      while(t--){
      	solve() ;
      } 

}