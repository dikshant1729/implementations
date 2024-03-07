#include<bits/stdc++.h>
using namespace std;

vector<int> nge(int arr[], int n)
{
    stack<pair<int,int>> s;
 
    
    s.push({arr[0],0});
 
   vector<int> ans(n,-1);
    for (int i = 1; i < n; i++) {
 
        if (s.empty()) {
            s.push({arr[i],i});
            continue;
        }
        while (s.empty() == false && s.top().first < arr[i]) {
            ans[s.top().second] = i;
            s.pop();
        }
 
        /* push next to stack so that we can find
        next greater for it */
        s.push({arr[i],i});
    }
    return ans;
}