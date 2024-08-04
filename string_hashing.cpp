#include<bits/stdc++.h>
using namespace std;

struct hasher{
    int sz;
    int mod,p;
    vector<int>fHash;
    vector<int>pk;
 
    void init(string s,int _p,int _mod){
        mod=_mod,p=_p;
        sz=s.size();
        fHash.resize(sz);
        pk.resize(sz);
        fHash[0]=(s[0]-'a'+1);
        pk[0]=1;
        for(int i=1;i<s.size();i++){
            fHash[i]=(fHash[i-1]*p + (s[i]-'a'+1))%mod;
            pk[i]=(pk[i-1]*p)%mod;
        }
    };
 
    int getfHash(int l,int r){
            if(l==0) return fHash[r];
            else return ((fHash[r]-fHash[l-1]*pk[r-l+1])%mod+mod)%mod;
        }
} ;

int main(){

    // 2 hashes two avoid collisions
    hasher h1 , h2;
    
    string s;
    h1.init(s,31,1e9+7);
    h2.init(s,37,1e9+9);
    
    int l , r;
    int hash1 = h1.getfHash(l,r);
    int hash2 = h2.getfHash(l,r);
     //pair of hashes are unique
}