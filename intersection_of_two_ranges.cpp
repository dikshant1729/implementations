#include<bits/stdc++.h>
using namespace std;
int main(){

    // intersect return pair of the intersection of two ranges 
    // if the intersection is (phi) then it returns {-1,-1};
    
     auto intersect = [&](int l1 , int r1 , int l2 , int r2) -> pair<int,int>{
              
              int l , r;

              if ((r1 < l2) ||  (r2 < l1)) return {-1,-1};
       
              else {l = max(l1, l2);  r = min(r1, r2);}

              return {l,r};
        };

    
}