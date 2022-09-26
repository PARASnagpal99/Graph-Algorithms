/*  ੴ   Satnam Waheguru */
#include<bits/stdc++.h>
using namespace std;

int parent[1000];
int rank[1000];

void makeSet(n){
	for(int i=1 ; i<=n ; ++i){
		parent[i] = i ;
		rank[i] = 0 ;
	}
}

int findPar(int node){
	if(node == parent(node)){
		return node ;
	}
	
	return parent[node] = findPar(parent[node]);
}


void union(int u , int v){
	u = findPar(u);
	v = findPar(v);
	
	if(rank[u] < rank[v]){
		parent[u] = v ;
	}else if(rank[v] < rank[u]){
		parent[v] = u ;
	}else{
		parent[v] = u ;
		rank[u]++;
	}
}





void solve(){
	makeSet() ;
	int m ;
	cin >> m ;
	while(m--){
		int u , v ;
		union(u,v);
	}
	
	// if 2 and 3 belong to the same component or not 
	if(findPar(2)!=findPar(3)){
		cout << "Yes they belong to the different components" << endl ;
	}else{
		cout << "No , they are part of same connected component" << endl ;
	}
	
}

int32_t main(){
 	 ios_base::sync_with_stdio(false); cin.tie(NULL); // fast input output
      int t ;
      //cin >> t ;
      t = 1 ;
      while(t--){
      	solve() ;
      } 

}
