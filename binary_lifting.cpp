#include<bits/stdc++.h>
using namespace std;

int main(){
    int LOG = 20;
    int n;
    vector<vector<int>> up(n+1,vector<int>(LOG+1));
    // up[v][j] is the 2^j-th ancestor of v
    vector<vector<int>> g(n+1);
    vector<int> depth(n+1);
     auto dfs = [&](int vertex , auto && dfs , int par = 0) -> void{
        up[vertex][0] = par;
        for(int i=1;i<=LOG;i++){
            up[vertex][i] = up[up[vertex][i-1]][i-1];
        }
        for(auto &child : g[vertex]){
            if(child == par) continue;
            depth[child] = depth[vertex] + 1;
            dfs(child,dfs,vertex);
        }
     };

     dfs(1,dfs);

     auto get_kth_ancestor = [&](int vertex , int k){
         for(int i=0;i<=LOG;i++){
             if(k & (1<<i)){
                 vertex = up[vertex][i];
             }
         }
         return vertex;
     };

     auto lca = [&](int a , int b) ->int{
            if(depth[a] < depth[b]) swap(a,b);
            a = get_kth_ancestor(a,depth[a]-depth[b]);
            if(a == b) return a;
            for(int i=LOG;i>=0;i--){
                if(up[a][i] != up[b][i]){
                    a = up[a][i];
                    b = up[b][i];
                }
            }
            return up[a][0];
    
     };

    auto distance = [&](int a , int b) ->int{

          if(depth[a] < depth[b]) swap(a,b);

          int lc = lca(a,b);

          int ans = depth[b] - depth[lc] + depth[a] - depth[lc];

          return ans;

    };
     
}