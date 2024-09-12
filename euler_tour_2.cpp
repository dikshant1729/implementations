#include<bits/stdc++.h>
 
using namespace std;

struct segmenttree{
int n;
vector<int> st;

void init(int n){
    this->n = n;
    st.resize(4*n , 0 /*default value */);
}

void build(int start , int ending , int node , vector<int> &v){

          if(start==ending){

            st[node] = v[start];

            return;

          }

          int mid = (start + ending)/2;

          //left subtree
          build(start , mid , 2*node+1 , v);

          // right subtree
          build(mid+1 , ending , 2*node+2 , v);

          // operation
          st[node] = st[2*node+1] + st[2*node+2];

}

void build(vector<int> &v){ build(0 , n-1 , 0 , v);}

int query(int start , int ending , int l , int r , int node){

    // no overlapping
    if(start>r || ending<l){
        return 0;
    }

    // complete overlap
    if(start>=l && ending<=r){
        return st[node];
    }

    //partial case
    int mid = (start+ending)/2;

    int q1 = query(start,mid,l,r,2*node+1);

    int q2 = query(mid+1 , ending , l , r , 2*node + 2);

    return q1+q2;
}

int query(int l , int r){ return query(0 , n-1 , l , r , 0);}

void update(int start , int ending , int node , int index , int value){
     
     if(start==ending){
        st[node] = value;
        return;
     }

     int mid = (start+ending)/2;

     if(index<=mid){
        //left subtree
       update(start , mid , 2*node+1 , index , value);
     }
     else{
        //right subtree
       update(mid+1 , ending , 2*node+2 , index , value);
     }
     
     // update with new value
     st[node] = st[2*node+1] + st[2*node+2];
}

void update(int x , int y){
     update(0 , n-1 , 0 , x , y);
}

};

int main(){

    // Euler tour technique is basically a way to represent a tree in linear form for updating and querying in log(n)
    
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++)cin>>v[i];
    vector<vector<int>> g(n+1);
    int m = n-1;
    while(m--){
        int a , b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> intime(n+1),outtime(n+1);

    int timer = 0;

    auto dfs = [&](int vertex , auto && dfs , int par = 0) ->void{
             
            intime[vertex] = timer++;

            for(auto &child: g[vertex]){
                if(child==par)continue;
                dfs(child,dfs,vertex);
            }

            outtime[vertex] = timer++;
    };

    dfs(1,dfs);

    segmenttree tree;
    tree.init(2*(n+1));
    
    for(int i=1; i<=n; i++){
        tree.update(intime[i] , v[i]);
    }

    for(int i=1; i<=n; i++){
        tree.update(outtime[i] , -v[i]);
    }
    
    for(int i=1; i<=q; i++){
        int type;
        cin>>type;
        if(type==1){
          int node , num;
          cin>>node>>num;
          tree.update(intime[node],num);
          tree.update(outtime[node],-num);
        }
        else{
          int node;
          cin>>node;
          cout<<tree.query(0 , intime[node])<<endl;
        }
    }

    return 0;
    
}