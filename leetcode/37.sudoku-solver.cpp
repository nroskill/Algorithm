/**
 * https://leetcode.com/problems/sudoku-solver/
 * By Nroskill
 * runtime 19 ms
 * language cpp
 */

class Solution {
public: 
    void calX(vector<vector<char>>& board, bitset<10>& exists, int index) {
        for(int i = 0; i < 9; i++) {
            char target = board[index][i];
            if(target == '.')
                continue;
            exists.set(target - '0', 1);
        }
    }
    
    void calY(vector<vector<char>>& board, bitset<10>& exists, int index) {
        for(int i = 0; i < 9; i++) {
            char target = board[i][index];
            if(target == '.')
                continue;
            exists.set(target - '0', 1);
        }
    }
    
    void calZ(vector<vector<char>>& board, bitset<10>& exists, int index) {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) {
                char target = board[i + index / 3 * 3][j + (index % 3) * 3];
                if(target == '.')
                    continue;
                exists.set(target - '0', 1);
            }
    }
    
    bool finished(vector<vector<char>>& board) {
        for(int i = 0; i < 81; i++)
            if(board[i / 9][i % 9] == '.')
                return false;
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bitset<10> exists;
        for(int i = 0; i < 81; i++)
            if(board[i / 9][i % 9] == '.') {
                calX(board, exists, i / 9);
                calY(board, exists, i % 9);
                calZ(board, exists, (i / 9) / 3 * 3 + (i % 9) / 3);
                for(int j = 1; j <= 9; j++) {
                    if(!exists.test(j)) {
                        board[i / 9][i % 9] = '0' + j;
                        solveSudoku(board);
                        if(finished(board))
                            return;
                        board[i / 9][i % 9] = '.';
                    }
                }
                break;
            }
    }
};