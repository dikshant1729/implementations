#include<bits/stdc++.h>
using namespace std;
int main(){

    // number of ways to create a sum of n with numbers in range of [1,k] 

    // these numbers can be in vector form also

    // one case is in which order matters and other in which order doesnot matter
    // For ex. 1+2+1 and 2+1+1 

    // these are standard dp problems

    // (repetition allowed)

    int n,k;
    vector<int> v(k);
    vector<int> dp(n+1 , 0);

    int MOD = 1e9+7;
    dp[0] = 1;

    // [1,2...k] or it can be v[0],v[1],...v[k-1]

    // v[0],v[1],...v[k-1]

    for(int i=1; i<=n; i++){
         for(int j = 0; j<k; j++){
            if(i>=v[j])dp[i] = (dp[i] + dp[i-v[j]])%MOD;
         }
    }



    //if it is 1,2,...k

    for(int i=1; i<=n; i++){
         for(int j = 0; j<=k; j++){
            if(i>=j)dp[i] = (dp[i] + dp[i-j])%MOD;
         }
    }


   cout<<dp[n];


}