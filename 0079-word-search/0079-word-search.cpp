class Solution {
public:
    bool solve(vector<vector<char>>& board, string &word, int i, int j, int index) {
        // Base case: If we found the entire word
        if (index == word.size()) {
            return true;
        }

        // Boundary checks and character match
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        // Mark cell as visited
        char ch = board[i][j];
        board[i][j] = '*';

        // Explore all 4 directions
        bool found = solve(board, word, i - 1, j, index + 1) ||  // Up
                     solve(board, word, i + 1, j, index + 1) ||  // Down
                     solve(board, word, i, j - 1, index + 1) ||  // Left
                     solve(board, word, i, j + 1, index + 1);    // Right

        // Restore cell (Backtracking)
        board[i][j] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Start DFS from every matching character
                if (board[i][j] == word[0] && solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
