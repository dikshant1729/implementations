#include<bits/stdc++.h>
using namespace std;    

int main(){
    auto lis = [&](vector<int> v) ->int{
    int n = v.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int ans = dp[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
};

auto lis = [&](vector<int> v) -> int {
    int n = v.size();
    const int INF = 1e9;
    vector<int> dp(n+1, INF);
    dp[0] = -INF;

     for (int i = 0; i < n; i++) {
        int l = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if (dp[l-1] < v[i] && v[i] < dp[l])
            dp[l] = v[i];
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (dp[l] < INF)
            ans = l;
    }
    return ans;
};
}