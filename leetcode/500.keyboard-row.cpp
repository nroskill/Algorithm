/**
 * https://leetcode.com/problems/keyboard-row/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        vector<string> dic;
        dic.push_back(string("QWERTYUIOPqwertyuiop"));
        dic.push_back(string("ASDFGHJKLasdfghjkl"));
        dic.push_back(string("ZXCVBNMzxcvbnm"));
        for(int i = 0; i < words.size(); i++)
            for(int j = 0; j < dic.size(); j++) {
                bool isInOneRow = true;
                for(int k = 0; k < words[i].length(); k++)
                    if(dic[j].find(words[i][k], 0) == string::npos) {
                        isInOneRow = false;
                        break;
                    }
                if(isInOneRow) {
                    result.push_back(words[i]);
                    break;
                }        
            }
        return result;
    }
};