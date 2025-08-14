#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    int best = 0, sum = 0;
    // kadane's is basically space optimized dp solution
    for (int i = 0; i < n; i++) {
      sum = max(v[i],sum+v[i]);
      best = max(best,sum);
    }

   // lets elaborate dp states and transitions
   vector<int> dp(n);
   dp[0] = v[0];
   for (int i = 1; i < n; ++i) {
   // dp[i] is the max subarray sum we can get ending at index i
   dp[i] = max(v[i], dp[i - 1] + v[i]);
   }
   

   // find minimum we can do similar to above just do min istead of max
   // 
}