class Solution {
public:
    int opr(vector<vector<int>>& dp, string& a, string& b, int i, int j){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(dp[i][j] != -1)return dp[i][j];
        if(a[i] == b[j])return dp[i][j] = opr(dp, a, b, i - 1, j - 1);
        return dp[i][j] = 1 + min(opr(dp, a, b, i, j - 1), 
                min(opr(dp, a, b, i - 1, j - 1),opr(dp, a, b, i - 1, j)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return opr(dp ,word1, word2, word1.size() - 1, word2.size() - 1);
    }
};