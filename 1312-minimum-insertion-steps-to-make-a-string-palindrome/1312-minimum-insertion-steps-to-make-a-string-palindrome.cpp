class Solution {
public:
    int lcs(vector<vector<int>>& dp, string& a, string& b, int i, int j){
        if(i < 0 || j < 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(a[i] == b[j])return dp[i][j] = 1 + lcs(dp, a, b, i - 1, j - 1);
        return 
        dp[i][j] = max(lcs(dp, a, b, i - 1, j), lcs(dp, a, b, i, j-1));
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        string a = s;
        reverse(a.begin(), a.end());
        return s.size() - lcs(dp, a, s, n - 1, n - 1);
    }
};