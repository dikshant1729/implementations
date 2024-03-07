#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    map<int,int> m;

    int sum=0 , ans=0;

    // number of subarrays with their sum == k
    // subarrays can be dependent [0...4] and [2...4] can be two answers

    for(int i=0; i<n; i++){

       sum+=v[i];

       if(sum==k)ans++;

       if(m[sum-k]!=0){

        ans+=m[sum-k];

       }

       m[sum]++;
    }

    cout<<ans<<endl;
}