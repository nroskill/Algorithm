/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * By Nroskill
 * runtime 35 ms
 * language cpp
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        bool isExist[255];
        int i, j;
        for(i = 0; i < s.length(); i++){
            memset(isExist, false, sizeof(isExist));
            isExist[s[i]] = true;
            for(j = i - 1; j >= 0; j--){
               	if(isExist[s[j]])
                   	break;
                isExist[s[j]] = true;
            }
            if(i - j > maxLength)
               	maxLength = i - j;
        }
        return maxLength;
    }
};