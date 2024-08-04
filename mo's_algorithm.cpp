#include<bits/stdc++.h>
using namespace std;


const int block_size = 320;

struct query {
    int l, r, id, block, ans;
    query(){};
    query(int l, int r, int id){
        this->l = l;
        this->r = r;
        this->id = id;
        this->block = l/block_size;
    };
    bool operator<(query P) const {
        return make_pair(this->block, r) < make_pair(P.block, P.r);
    }
};

struct mos_algorithm{

    int n;
    vector<int> a;
    vector<query> q;
    int answer = 0;
   
    mos_algorithm(int n, vector<int> a, vector<query> q){
        this->n = n;
        this->a = a;
        this->q = q;
        solve();
    }

    void add(int val) {
        
    }

    void remove(int val) {
        
    }

    void solve(){
        sort(q.begin(), q.end());
        int cur_l = 0;
        int cur_r = -1;
   
        for (query q : q) {


            while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
            }


            while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
            }


            while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
            }


            while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
            }

            
            q.ans = answer;
        }
        sort(q.begin(), q.end(), [&](query a, query b) {
            return a.id < b.id;
        });
    }

};



int main(){

}