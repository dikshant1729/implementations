#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> v(n);
    set<int> feasible; // max elts in this set can be log(max(v[i]))

    for(int i=0; i<n; i++){

        set<int> new_feasible;

        for(auto val: feasible){

            new_feasible.insert(val&v[i]);

        }

        new_feasible.insert(v[i]); // size 1 subarray

        // new feasible set is all possible AND ending at v[i]

        feasible = new_feasible;

    }

    // this works for OR also

}