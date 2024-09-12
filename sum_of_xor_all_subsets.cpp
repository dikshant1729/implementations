#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> v;
    int tot = (1<<n);
    int ans = 0;
    /*
    key observation was that 
    if there is atleast one set bit at ith position in any of the numbers 
    then the ith bit will be set in the xors of half of the total number of subsets
    */
    for(int i=0; i<31; i++){
            int bit = 0;
            for(int j=0; j<n; j++){
               bit+=(v[j]>>i)&1;
            }
            if(bit){
                ans+=(tot/2)*(1<<i);
            }
    }
}