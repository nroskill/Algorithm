/**
 * https://leetcode.com/problems/surrounded-regions/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    void helper(vector<vector<char>>& board, int row, int col, int i, int j) {
        stack<pair<int, int>> h;
        h.push(pair<int, int>(i, j));
        board[i][j] = '1';
        while(!h.empty()) {
            auto t = h.top();
            h.pop();
            int x = t.first;
            int y = t.second;
            if(x + 1 < row && board[x + 1][y] == 'O') {
                board[x + 1][y] = '1';
                h.push(pair<int, int>(x + 1, y));
            }
            if(x - 1 >= 0 && board[x - 1][y] == 'O') {
                board[x - 1][y] = '1';
                h.push(pair<int, int>(x - 1, y));
            }
            if(y + 1 < col && board[x][y + 1] == 'O') {
                board[x][y + 1] = '1';
                h.push(pair<int, int>(x, y + 1));
            }
            if(y - 1 >= 0 && board[x][y - 1] == 'O') {
                board[x][y - 1] = '1';
                h.push(pair<int, int>(x, y - 1));
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0)
            return;
        int col = board[0].size();
        for(int i = 0; i < row; i++) {
            if(board[i][0] == 'O')
                helper(board, row, col, i, 0);
            if(board[i][col - 1] == 'O')
                helper(board, row, col, i, col - 1);
        }
        for(int i = 1; i + 1 < col; i++) {
            if(board[0][i] == 'O')
                helper(board, row, col, 0, i);
            if(board[row - 1][i] == 'O')
                helper(board, row, col, row - 1, i);
        }
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                board[i][j] = (board[i][j] == '1' ? 'O' : 'X');
    }
};