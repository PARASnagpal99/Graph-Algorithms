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
	vector<int> graph[n] ;
	vector<int> dist(n,0) ;
	vector<bool> vis(n,false) ;
	
	for(int i=0 ; i<m ; ++i){
		int u , v ;
		cin >> u >> v ;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	
	queue<int> q ;
	q.push(0) ;
	vis[0] = true ;
	dist[0] = 0 ;
	
	while(!q.empty()){
		auto node = q.top() ;
		q.pop() ;
		for(auto &child : graph[node]){
			if(!vis[child]){
				vis[child] = true ;
				dist[child] = dist[node] + 1 ;
				q.push(child) ;
			}
		}
	}
	
	// time complexity : O(V+E) 
	// Space complexity : O(N)
	
	
}

int32_t main(){
 	 ios_base::sync_with_stdio(false); cin.tie(NULL); // fast input output
      int t ;
    //  cin >> t ;
      t = 1 ;
      while(t--){
      	solve() ;
      } 

}
