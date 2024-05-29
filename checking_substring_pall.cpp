/* dikshant sharma */
#pragma GCC optimize("O3,unroll-loops")
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 #define test int t; cin>>t; while(t--)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 /*
 find_by_order() and order_of_key(). 
 The first returns an iterator to the k-th largest element (counting from zero),
  the second — the number of items in a set that are strictly smaller than our item.
 */
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define int long long
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
int mod_mul(int a, int b){
    int res = (a * 1ll * b) % MOD;
    if (res < 0) res += MOD;
    return res;
}
 
int mod_sum(int a ,int b){
    int res = (a + b) % MOD;
    if (res < 0) res += MOD;
    return res;
}
 
int mod_sub(int a, int b){
    if(a >= b) return (a - b) % MOD;
    else return MOD - (b - a) % MOD;
}
const int N = 2e5 + 10;
const int base = 31;
vector<int> p(N), I(N);
struct Hashing {
    vector<int> A;
    string s;
    int n;
    void init(string _s){
        A.resize(_s.size());
        s = _s;
        n = _s.size();
        build();
    }
 
    void build(){
        A[0] = (s[0] - 'a' + 1);
        for(int i = 1; i < n; i++){
            A[i] = mod_sum(A[i - 1], mod_mul(s[i] - 'a' + 1, p[i]));
        }
    }
 
    int query(int l ,int r){
        int res = mod_sum(A[r], (l ? -A[l - 1] : 0));
        res = mod_mul(res, I[l]);
        return res;
    }
} hs, hsr;

void pre(){
    p[0] = 1;
    I[0] = 1;
    int Inv_base = inverse(base);
    for(int i = 1; i < N; i++){
        I[i] = mod_mul(I[i - 1], Inv_base);
        p[i] = mod_mul(p[i - 1], base);
    }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();

    // initial string

    string s;
    int n = s.size();

    // inintialization

    pre();
    hs.init(s);
    reverse(all(s));
    hsr.init(s);

    // how to check pallindrome for a substring l , r

    int l , r;
    cin>>l>>r;
    l-- , r--;
    int len = r-l+1 , mid = (l+r)/2;     
    int x1 = l, y1 = mid, x2 = ((len%2) ? mid : mid+1), y2 = r;
    swap(x2, y2);      
    x2 = n-1-x2, y2 = n-1-y2;   
    if(hs.query(x1,y1)!=hsr.query(x2, y2)){
                       
    }       
    return 0;
}