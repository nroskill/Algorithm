/**
 * https://leetcode.com/problems/string-to-integer-atoi/
 * By Nroskill
 * runtime 25 ms
 * language cpp
 */

class Solution {
public:
    int myAtoi(string str) {
        long long int result = 0;
        int flag = 1, i = 0;
        if(str.length() == 0)
            return 0;
        while(i < str.length() && str[i] == ' ') i++;
        if(str[i] == '-') {
            flag = -1;
            i++;
        }
        else if(str[i] == '+') {
            i++;
        }
        while(i < str.length() && (str[i] == '0')) i++;
        for(; i < str.length(); i++) {
            //if(str[i] == ' ')
            //    continue;
            if(str[i] > '9' || str[i] < '0')
                return flag * (int)result;
            result = result * 10 + str[i] - '0';
            if(result > 0x7fffffff && flag == 1)
                return 0x7fffffff;
            if(result > 0x80000000 && flag == -1)
                return 0x80000000;
        }
        return flag * (int)result;
    }
};