/**
 * https://leetcode.com/problems/word-ladder/
 * By Nroskill
 * runtime 759 ms
 * language cpp
 */

class Solution {
public:
    bool judge(string a, string b) {
        int result = 0;
        for(int i = 0; i < a.length() && result < 2; i++)
            if(a[i] != b[i])
                result++;
        return result == 1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<int> save;
        int result = 2;
        bool record[wordList.size()];
        for(int i = 0; i < wordList.size(); i++)
            if(judge(beginWord, wordList[i])) {
                save.push(i);
                record[i] = true;
            }
            else
                record[i] = false;
        int c = save.size();
        int t = 0;
        while(!save.empty()) {
            int index = save.front();
            for(int i = 0; i < wordList.size(); i++)
                if(!record[i] && judge(wordList[index], wordList[i])) {
                    t++;
                    record[i] = true;
                    save.push(i);
                }
            if(wordList[index] == endWord)
                return result;
            save.pop();
            c--;
            if(c == 0) {
                result++;
                c = t;
                t = 0;
            }
        }
        return 0;
    }
};