/**
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/
 * By Nroskill
 * runtime 0 ms
 * language cpp
 */

class Solution {
public:
    string toHex(int num) {
        string result("");
        char hash[] = "0123456789abcdef";
        for(unsigned int mask = 0xf0000000, i = 28; mask != 0; mask = mask >> 4, i -= 4) {
            int temp = (mask & num) >> i;
            if(temp || result.length())
                result += string(1, hash[temp]);
        }
        if(result.length())
            return result;
        return string("0");
    }
};