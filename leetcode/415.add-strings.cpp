/**
 * https://leetcode.com/problems/add-strings/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.length() < num2.length())
            return addStrings(num2, num1);
        if(num1.length() != num2.length()) {
            return addStrings(num1, string(num1.length() - num2.length(), '0') + num2);
        }
        int i;
        bool flag = false;
        string result(num1.length(), '0');
        for(i = 1; i <= num1.length(); i++) {
            if(flag)
                result[result.length() - i]++;
            result[result.length() - i] += (num1[num1.length() - i] + num2[num2.length() - i] - '0' - '0');
            flag = (result[result.length() - i] > '9') ? true : false;
            if(flag)
                result[result.length() - i] -= 10;
        }
        if(flag)
            result = string("1") + result;
        return result;
    }	
};