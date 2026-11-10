
class Solution {
public:
    int solve(int n, vector<int>& costs, vector<int>& dp) {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int j = 1; j <= 3; j++){
            if(n - j >= 0) 
            {
                ans = min(ans, solve(n - j, costs, dp) + costs[n - 1] + j * j);
            }
        }
        return dp[n] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return solve(n, costs, dp);
    }
};
