// Depth first search (DFS) in Tree 
#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

const int N = 1e5 + 10 ;
vector<int>g[N];

int depth[N] , height[N] ;


void dfs(int vertex , int par=0){
	   // take action on vertex after entering the vertex 
	   for(int child : g[vertex]){
	   	   // Take action on child before entering the child node 
	   	   if(child==par) continue ;
	   	   depth[child] = depth[vertex] + 1 ;
	   	   
	   	   dfs(child , vertex);
	   	   height[vertex] = max(height[vertex] , height[child]+1) ;
	   	   // Take action on child after exiting child node 
	   }
	   // Take action on vertex before exitting the vertex 	   
}


int main()
{
	int n ;
	cin >> n ;
	for(int i=0 ; i<n-1 ; ++i)
	{
		int v1 , v2 ;
	    cin >> v1 >> v2 ;
	    g[v1].push_back(v2);
	    g[v2].push_back(v1);
	}
	dfs(1);
	
	for(int i=1 ; i<=n ; ++i)
	{
		cout << depth[i]  << " "  << height[i] << endl ;
	}
   return 0 ;
}


// Time complexity O(vertices +  edges )  , depends on number of recursive calls .

