#include<bits/stdc++.h>
using namespace std;    

int main(){
    int n;
    vector<int> v(n);
    int sum = 0;
    int mul = 1;
    for(int i=0; i<31; i++){
       vector<int> bit(n);
         for(int j=0; j<n; j++){
              bit[j] = (v[j]>>i)&1;
         }
         int odd_ct=0;
         int even_ct=0;
         int ct=0;
         for(int j=0; j<n; j++){
            ct+=bit[j];
             if(ct&1){
                 sum += mul;
                 sum+= even_ct*(mul);
             }
             else{
                 sum += odd_ct*(mul);
             }

             if(ct&1){
                odd_ct++;
             }
             else{
                even_ct++;
             }
         }
         sum-=ct*(mul);
         mul*=2;
    }
}