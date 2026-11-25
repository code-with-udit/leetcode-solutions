class Solution {
public:
    int solve(vector<vector<int>>& dp, string& s1, string& s2, int i, int j){
        if(i < 0 || j < 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s1[i] == s2[j])
        return dp[i][j] = 1 + solve(dp, s1, s2, i - 1, j - 1);
        return dp[i][j] = max(solve(dp, s1, s2, i - 1, j), 
                    solve(dp, s1, s2, i, j - 1));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(dp, text1, text2, n - 1, m - 1);
    }
};