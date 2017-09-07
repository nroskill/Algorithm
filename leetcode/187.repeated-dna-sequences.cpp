/**
 * https://leetcode.com/problems/repeated-dna-sequences/
 * By Nroskill
 * runtime 52 ms
 * language cpp
 */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, bool> save;
        vector<string> result;
        if(s.length() < 10)
            return result;
        for(int i = 0; i + 9 < s.length(); i++) {
            auto t = s.substr(i, 10);
            if(save.find(t) == save.end())
                save[t] = false;
            else if(!save[t]) {
                save[t] = true;
                result.push_back(t); 
            }   
        }
        return result;
    }
};