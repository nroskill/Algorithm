/**
 * https://leetcode.com/problems/isomorphic-strings/
 * By Nroskill
 * runtime 12 ms
 * language cpp
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char, char> db;
        unordered_set<char> cache;
        for(int i = 0; i < s.length(); i++) {
            auto temp = db.find(s[i]);
            if((temp == db.end() && cache.find(t[i]) != cache.end()) || (temp != db.end() && db[s[i]] != t[i]))
                return false;
            cache.insert(t[i]);
            db[s[i]] = t[i];
        }
        return true;
    }
};