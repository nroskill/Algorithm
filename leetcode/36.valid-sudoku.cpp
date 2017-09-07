/**
 * https://leetcode.com/problems/valid-sudoku/
 * By Nroskill
 * runtime 12 ms
 * language cpp
 */

class Solution {
public:
    bool judgeX(vector<vector<char>>& board, int index) {
        bitset<10> exists;
        for(int i = 0; i < 9; i++) {
            char target = board[index][i];
            if(target == '.')
                continue;
            if(exists.test(target - '0'))
                return false;
            else
                exists.set(target - '0', 1);
        }
        return true;
    }
    
    bool judgeY(vector<vector<char>>& board, int index) {
        bitset<10> exists;
        for(int i = 0; i < 9; i++) {
            char target = board[i][index];
            if(target == '.')
                continue;
            if(exists.test(target - '0'))
                return false;
            else
                exists.set(target - '0', 1);
        }
        return true;
    }
    
    bool judgeZ(vector<vector<char>>& board, int index) {
        bitset<10> exists;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) {
                char target = board[i + index / 3 * 3][j + (index % 3) * 3];
                if(target == '.')
                    continue;
                if(exists.test(target - '0'))
                    return false;
                else
                    exists.set(target - '0', 1);
            }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
            if(!judgeX(board, i) || !judgeY(board, i) || !judgeZ(board, i))
                return false;
        return true;
    }
};