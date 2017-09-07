/**
 * https://leetcode.com/problems/first-unique-character-in-a-string/
 * By Nroskill
 * runtime 42 ms
 * language cpp
 */

class Solution {
public:
    int firstUniqChar(string s) {
        int offset[26], min = 0x7fffffff;
        for(int i = 0; i < 26; i++)
        	offset[i] = -2; 
        for(int i = 0; i < s.length(); i++)
            if(offset[s[i] - 'a'] == -1)
                continue;
            else if(offset[s[i] - 'a'] == -2)
                offset[s[i] - 'a'] = i;
            else
                offset[s[i] - 'a'] = -1;
        for(int i = 0; i < 26; i++)
            if(offset[i] >= 0)
                min = std::min(min, offset[i]);
        if(min == 0x7fffffff)
            return -1;
        return min;
    }
};