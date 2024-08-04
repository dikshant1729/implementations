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
    
    int n;
    vector<vector<int>> g(n+1);

    vector<int> intime(n+1),outtime(n+1);

    int timer = 0;

    auto dfs = [&](int vertex , auto && dfs , int par = 0) ->void{
             
            intime[vertex] = timer++;

            for(auto &child: g[vertex]){
                if(child==par)continue;
                dfs(child,dfs,vertex);
            }

            outtime[vertex] = timer-1;
    };

    dfs(1,dfs);

    vector<int> values(n+1);  // values at each node

    segmenttree tree;
    tree.init(n+1);

    // as my segment use 0 based indexing for input 
    // intime[i] and outtime[i] are also 0 based --> entry of node 1 at time 0 their values are 0 based
   
    for(int i=1;i<=n;i++){
        tree.update(intime[i],values[i]);
    }
    int q;
    for(int i=1; i<=q; i++){

        int node , val;
       
        // updating node with new value val
        tree.update(intime[node] , val);

        // querying the sum of values of all nodes in subtree of node
        tree.query(intime[node] , outtime[node]);
    }

    
}