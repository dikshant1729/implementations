#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
vector<int> v;
vector<vector<int>> prefixbits(n, vector<int>(32, 0));

for(int i=0; i<n; i++){
    int num = v[i];
    for(int j=0; j<32; j++){
           prefixbits[i][j] = ((num>>j) & 1);
    }
}

for(int i=1; i<n; i++){
    for(int j=0; j<32; j++){
       prefixbits[i][j]+=prefixbits[i-1][j];
    }
}

    auto check = [&](int l , int r) ->int {

        int ans = 0;

        for(int i = 0; i < 32; i++){
           
           int bits = 0;

           if(l==0){

             bits = prefixbits[r][i];

           }
           else{

            bits = prefixbits[r][i] - prefixbits[l-1][i];

           }

           if(bits == (r - l +1)){

              ans = ans | (1LL<<i);

           }

        }
        return ans;
    };

}