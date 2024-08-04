#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    
    int l = -1 , r = n;

    // l  = min - 1
    // r  = max + 1

    while(r - l > 1){

        int mid = (l+r) >> 1 ;

        if(v[mid] < x) l = mid;

        else r = mid;
    }
    // cout<<l<<" "<<r<<endl;
    // l will be the index of number less than x 
    // r will be the index of number equal to x (first)
}

// practice Q https://codeforces.com/problemset/problem/1772/D
// https://codeforces.com/problemset/problem/348/A

// it is not necessary that function which undergo BS will directly change l , r it may depend on other var