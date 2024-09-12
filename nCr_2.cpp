#include<bits/stdc++.h>
using namespace std;

int N = 1e6;

vector<int> factorialNumInverse(N+1);
vector<int> naturalNumInverse(N+1);
vector<int> fact(N+1);

void pre(int p){

naturalNumInverse[0] = naturalNumInverse[1] = 1;
for (int i = 2; i <= N; i++) naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
    
factorialNumInverse[0] = factorialNumInverse[1] = 1;
for (int i = 2; i <= N; i++) factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;

fact[0] = 1;
for (int i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % p;

}
int main(){
    
    int MOD;
    pre(MOD);
    auto nCr = [&](int n , int r , int p) ->int{
         int ans = ((fact[n] * factorialNumInverse[r])
              % p * factorialNumInverse[n - r])
             % p;
         return ans;
    };

}