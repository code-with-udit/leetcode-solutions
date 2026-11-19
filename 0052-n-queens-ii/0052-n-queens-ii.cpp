
class Solution {
public:
    bool canPlace(vector<vector<char>>& grid, int cr, int cc) {
        int n = grid.size();

        // Check vertically upward
        int i = cr, j = cc;
        while(i >= 0) {
            if(grid[i--][j] == '*') return false;
        }

        // Check upper-left diagonal
        i = cr, j = cc;
        while(i >= 0 && j >= 0) {
            if(grid[i--][j--] == '*') return false;
        }

        // Check upper-right diagonal
        i = cr, j = cc;
        while(i >= 0 && j < n) {
            if(grid[i--][j++] == '*') return false;
        }
        return true;
    }

    int solve(vector<vector<char>>& grid, int cr) {
        int n = grid.size();
        if(cr == n) return 1;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(canPlace(grid, cr, i)) {
                grid[cr][i] = '*';
                count += solve(grid, cr + 1);

                // Backtracking
                grid[cr][i] = '.';
            }
        }
        return count;
    }

    int totalNQueens(int n) {
        vector<vector<char>> grid(n, vector<char>(n, '.'));
        return solve(grid, 0);
    }
};
