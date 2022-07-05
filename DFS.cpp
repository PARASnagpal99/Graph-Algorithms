#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 ;
vector<int>graph[N];
bool Vis[N];
void dfs(int vertex){
    // if(Vis[vertex]) return ;
    Vis[vertex]=true ;
    cout << vertex << endl ;
    for(auto child : graph[vertex]){
        cout << "Parent " << vertex << ", child " << child << endl ;
        if(Vis[child]) continue ;
        dfs(child);
    }
}
int main() {
    int n , m ;
    cin >> n >> m ;
	for(int i=0 ; i<9 ; ++i){
	    int v1 , v2 ;
	    cin >> v1 >> v2 ;
	    graph[v1].push_back(v2);
	    graph[v2].push_back(v1);
	}
	dfs(6);
	return 0;
}
// Time complexity : O(vertex+Edges)
// Space complexity : O(N)