/**
 * https://leetcode.com/problems/word-search/
 * By Nroskill
 * runtime 56 ms
 * language cpp
 */

class Solution {
public:
    bool tryThis(vector<vector<char>>& board, string word, unordered_set<int>& offsets, int current, int offset) {
        offsets.insert(current);
        int up    = current - board[0].size();
        int down  = current + board[0].size();
        int left  = current - 1;
        int right = current + 1;
        
        offset += 1;
        if(offset == word.length() ||
		   (current / board[0].size() >= 1 && 
            word[offset] == board[up / board[0].size()][up % board[0].size()] && 
            offsets.count(up) == 0 && 
            tryThis(board, word, offsets, up, offset)) ||
           (current / board[0].size() + 1 < board.size() && 
            word[offset] == board[down / board[0].size()][down % board[0].size()] && 
            offsets.count(down) == 0 && 
            tryThis(board, word, offsets, down, offset)) ||
           (current % board[0].size() >= 1 && 
            word[offset] == board[left / board[0].size()][left % board[0].size()] && 
            offsets.count(left) == 0 && 
            tryThis(board, word, offsets, left, offset)) ||
           (current % board[0].size() + 1 < board[0].size() && 
            word[offset] == board[right / board[0].size()][right % board[0].size()] && 
            offsets.count(right) == 0 && 
            tryThis(board, word, offsets, right, offset))
        )
            return true;
        
        offsets.erase(offsets.find(current));
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() < 1)
            return false;
        unordered_set<int> offsets;
        
        for(int i = 0; i < board.size() * board[0].size(); i++)
            if(board[i / board[0].size()][i % board[0].size()] == word[0] && tryThis(board, word, offsets, i, 0))
                return true;
        return false;
    }
};