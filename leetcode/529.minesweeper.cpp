/**
 * https://leetcode.com/problems/minesweeper/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:

    int pos[3] = {-1, 0, 1};
    
    int cal(vector<vector<char>>& board, int x, int y) {
        int result = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(x + pos[i] >= 0 && x + pos[i] < board.size() && y + pos[j] >= 0 && y + pos[j] < board[0].size())
                    result += board[x + pos[i]][y + pos[j]] == 'M' ? 1 : 0;
        return result;
    }
    
    bool judge(vector<vector<char>>& board, int x, int y) {
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return true;
        }
        if(board[x][y] == 'B' || (board[x][y] >= '1' && board[x][y] <= '8'))
            return false;
        int count = cal(board, x, y);
        if(count != 0)
            board[x][y] = '0' + count;
        else {
            board[x][y] = 'B';
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    if(x + pos[i] >= 0 && x + pos[i] < board.size() && y + pos[j] >= 0 && y + pos[j] < board[0].size())
                        judge(board, x + pos[i], y + pos[j]);
        }
        return false;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        for(int i = 0; i < click.size(); i += 2) {
            if(judge(board, click[i], click[i + 1]))
                break;
        }
        return board;
    }
};