#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int powermod(int a, int b){
    int res = 1;
    a %= MOD;
    while (b > 0){
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
int inverse(int a){ return powermod(a, MOD - 2);}
 
int nCr(int n , int r){
    int sum = 1;
    for(int i = 1; i <= r; i++){
            sum = (sum * ((n - r + i)%MOD * inverse(i)%MOD)%MOD)%MOD;
        }
        return sum;
}
int main(){

}