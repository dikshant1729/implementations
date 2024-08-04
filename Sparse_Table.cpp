#include<bits/stdc++.h>
using namespace std;

const int k = 25;

int main(){

    int n;
    vector<int> v;
    vector<vector<int>> st(n, vector<int>(k + 1));

    for (int i = 0; i < n; i++) st[i][0] = v[i];

    for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = __gcd(st[i][j - 1] , st[i + (1 << (j - 1))][j - 1]);

    auto query = [&](int l, int r) ->int{
        int len = r - l + 1;
        int k = log2(len);
        return __gcd(st[l][k] , st[r - (1 << k) + 1][k]);
        // why this work ?
        // gcd(a,b,c,d,e) = (gcd(a,b,c,d) , gcd(b,c,d,e))
        // overlapping doesnt effect answer similar to RMQ
    };


    auto query = [&](int l , int r) ->int{
        int sum = 0;
        for (int j = k; j >= 0; j--) {
            if ((1 << j) <= r - l + 1) {
                sum += st[l][j];
                l += 1 << j;
            }
        }
        return sum;
    };
}