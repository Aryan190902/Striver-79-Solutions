#include<vector>

using namespace std;

// For Recursive approach
// int solve(vector<int>&v, int ind, vector<int>&dp){
//     if(ind >= v.size()) return 0;
//     if(dp[ind] != -1)   return dp[ind];
//     int np = solve(v, ind+1, dp);
//     int p = v[ind] + solve(v, ind+2, dp);

//     return dp[ind] = max(p, np);
// }

// For Iterative approach
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n, 0);
    if(n == 1)  return nums[0];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int ind = 2 ; ind < n ; ind++){
        int np = dp[ind-1];
        int p = nums[ind] + dp[ind-2];
        dp[ind] = max(p, np);
    }  
    return dp[n-1];
}