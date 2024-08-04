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
int inverse(int a){ 
    return powermod(a, MOD - 2);
}

int a_divides_b(int a , int b){
   int ans = a%MOD;
   ans = (ans*(inverse(b)%MOD))%MOD;
}

int main(){

}