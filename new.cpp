#include<bits/stdc++.h>
using namespace std;

int main(){
	int n , x;
	cin>>n>>x;
	vector<int> safe(n+1);
    for(int i=0; i<n; i++){
    	int value;
    	cin>>value;
    	safe[i+1] = value;
    }
	vector<vector<int>> g(n+1);
	int edges = n-1;
	while(edges--){
		int a , b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	// vector<int> unsafe_count(n+1,0);
	// int ans = 0;
	// auto dfs = [&](int vertex , int par , auto &&dfs) ->void{
 //         unsafe_count[vertex] = unsafe_count[par] + safe[vertex];
 //         // cout<<unsafe_count[vertex]<<" "<<vertex<<endl;
 //         for(auto child: g[vertex]){
 //            if(child==par)continue;
 //            dfs(child,vertex,dfs);
 //         }
 //         if(g[vertex].size()==1){
 //         	if(unsafe_count[vertex]<=x)ans++;
 //         }
 //         return;
	// };
	// dfs(1,0,dfs);
	// cout<<ans<<endl;

/*
x = 1 , n = 4
0 1 1 0
1 2
1 3
2 4
ans = 2
*/
  vector<int> unsafe_count(n+1,0);
  int ans = 0;
  queue<pair<int,int>> q;
  q.push({1,0});
  while(!q.empty()){
  	  auto [node,par] = q.front();
  	  q.pop();
    //   cout<<node<<endl;
  	  for(auto child: g[node]){
  	  	 if(child==par)continue;
         unsafe_count[child] = unsafe_count[child] + unsafe_count[node] + safe[node];
         q.push({child,node});
  	  }
  	  if(g[node].size()==1){
  	  	if(unsafe_count[node]<=x)ans++;
  	  }
  }
  cout<<ans<<endl;

}