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


void dfs(int node , vector<bool> &vis , stack<int> &st , vector<int> graph[]){
	vis[node] = true ;
	for(auto &child : graph[node]){
		if(!vis[child]){
			dfs(child,vis,st,graph);
		}
	}
	st.push(node) ;
}


void reverseDFS(int node , vector<bool>&vis , vector<int> graph[]){
	cout << node << " " ;
	vis[node] = true ;
	for(auto &child : graph[node]){
		if(!vis[child]){
			reverseDFS(child,vis,graph) ;
		}
	}
}



void solve(){
	int n , m ;
	cin >> n >> m ;
	vector<int> graph[n] ;
	for(int i=0 ; i<m ; ++i){
		int u , v ;
		cin >> u >> v ;
		graph[u].pb(v) ;   // its a directed graph 
	}
	
	// main problem we find in directly applying dfs over that to find strongly cc is that it traverses whole graph 
	// solution for that is we construct a order according to the exit time of the nodes and apply dfs over transpose of graph
	// to find the strongly cc 
	
	/*
	
	Algorithm : 
	1. sort all the nodes in order of their finishing time (topological sort)
	2. construct transpose of graph 
	3. Apply DFS according to the finishing time 
	

	*/
	
     vector<bool>vis(n,false) ;
	stack<int> st ;
	
	// constructing the order according to Toplogical sort aka according to their exit time 
	for(int i=0 ; i<n ; ++i){
		if(!vis[i]){
			dfs(i,vis,st,graph);
		}
	}
	
	 
	
	vector<int> transpose[n] ;
	for(int i=0 ; i<n ; ++i){
		vis[i] = 0 ;
		for(auto &it : graph[i]){
			transpose[it].pb(i) ;
		}
	}
	int cnt = 0 ;
	while(!st.empty()){
		auto i = st.top() ;
		if(!vis[i]){
			cnt++;
			cout << "SCC : " ;
			reverseDFS(i,vis,transpose) ;
			cout << endl ;
		}
		st.pop() ;
	}
	
	
	cout << "total number of SCC are : " << cnt << endl ;
	
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
