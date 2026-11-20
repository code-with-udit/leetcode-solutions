class Solution {
public:
    bool canPlace(vector<string>& grid, int cr, int cc) {
        int n = grid.size();

        // Check vertically upward
        int i = cr, j = cc;
        while(i >= 0) {
            if(grid[i--][j] == 'Q') return false;
        }

        // Check upper-left diagonal
        i = cr, j = cc;
        while(i >= 0 && j >= 0) {
            if(grid[i--][j--] == 'Q') return false;
        }

        // Check upper-right diagonal
        i = cr, j = cc;
        while(i >= 0 && j < n) {
            if(grid[i--][j++] == 'Q') return false;
        }

        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& grid, int cr) {
        int n = grid.size();

        if(cr == n) {
            ans.push_back(grid);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(canPlace(grid, cr, i)) {
                grid[cr][i] = 'Q';

                solve(ans, grid, cr + 1);

                // Backtracking
                grid[cr][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> grid(n, string(n, '.'));

        solve(ans, grid, 0);

        return ans;
    }
};