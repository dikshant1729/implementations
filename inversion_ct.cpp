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
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();

    int n;
    cin>>n;
    vector<int> v(n);
    pbds s;
    int ans=0;
    for(int i=0; i<n; i++){
       cin>>v[i]; 
       s.insert({v[i],i});
    }

    // count of strictly smaller numbers with index > current index

    // for(int i=n-1; i>=0; i--){
    
    //         s.erase(s.find({v[i],i}));
         
    //         int it = s.order_of_key({v[i],i});
            
    //         ans+=s.size()-it;
           
           
    // }

    // count of numbers smaller than or equal to with index > current index

    // for(int i=n-1; i>=0; i--){
    
    //         s.erase(s.find({v[i],i}));
         
    //         int it = s.order_of_key({v[i],0});
            
    //         ans+=s.size()-it;
           
           
    // }

    // count of numbers greater than with index > current index

    // for(int i=n-1; i>=0; i--){
    
    //         s.erase(s.find({v[i],i}));
         
    //         int it = s.order_of_key({v[i],0});
            
    //         ans+=it;
           
           
    // }

    // count of numbers greater than or equal to with index > current index

    // for(int i=n-1; i>=0; i--){
    
    //         s.erase(s.find({v[i],i}));
         
    //         int it = s.order_of_key({v[i],i});
            
    //         ans+=it;
           
           
    // }

    cout<<ans<<endl;

    return 0;
}