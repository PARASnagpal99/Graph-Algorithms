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

struct node{
	int u , v , wt ;
	node(int first , int second , int weight){
		u = first ;
		v = second ;
		wt = weight ;
	}
};



void solve(){
	int n , m ;
	cin >> n >> m ;
	vector<node> edges ;
	for(int i=0 ; i<m ; ++i){
		int u , v , wt ;
		cin >> u >> v >> wt ;
		edges.pb(node(u,v,wt));
	}
	
	
	int src = 0 ;
	cin >> src ;
	vector<int> dist(n,INF) ;
	dist[src] = 0 ;
	
	
	// relaxing the edges n-1 time to find the shortest path .
	// we do it because max possible path without weight is n-1 so in order to cover all the proper comparisons .
	for(int i=1 ; i<=n-1 ; ++i){
		for(auto &it : edges){
			if(dist[it.u] + it.wt < dist[it.v]){
				dist[it.v] = dist[it.u] + it.wt ; 
			}
		}
	}
	
	// now checking for negative weight cycle 
	// if after relaxing n-1 times , if distance between two nodes also gets reduced further than its a negative weight cycle
	
	
	bool flag = 0 ;
	for(auto &it : edges){
		if(dist[it.u] + it.wt < dist[it.v]){
			cout << "Its a negative weighted cycle" << endl ;
			flag = true ;
			break ;
		}
	}
	
	cout << "shortest path from source to edges are : ";
	if(!flag){
		for(int i=0 ; i<n ; ++i){
		cout << dist[i] << " " ;
	   } 
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
