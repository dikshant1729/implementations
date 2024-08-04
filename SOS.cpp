#include<bits/stdc++.h>
using namespace std;    
int main(){
    // brute force 
    int n;
    for (int mask = 0; mask <=n; mask++){
 
            // iterate over all the subsets of the mask

           // assume mask = 10101
 
            for(int i = mask; i > 0; i = (i-1) & mask){

               // i will iterate over 10101, 10100, 10001, 10000, 00101, 00100, 00001

            }
 
    }

    // SOS DP
    int n;
    // in SOS dp we dont iterate over all the subsets of the mask
    // instead we iterate over submasks with their bits = mask(bits) - 1

    vector<vector<int>> dp;

    for( int mask = 0; mask < (1<<n) ; ++mask ) {
	
    // n max number of bits in mask
	for( int i = 0; i < n; ++i ) {

		if(mask & (1<<i))
			dp[mask][i] = /*dependent on mask^(1<<i) */ 1; 
		else
            // i'th bit is not set in mask
			dp[mask][i] = dp[mask][i-1];
	}
	
}

}