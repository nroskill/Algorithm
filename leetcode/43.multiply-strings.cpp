/**
 * https://leetcode.com/problems/multiply-strings/
 * By Nroskill
 * runtime 18 ms
 * language cpp
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length() < num2.length())
            return multiply(num2, num1);
        int carry = 0, i;
        string result(num1.length() + num2.length(), '0');
        for(i = 0; i < result.length(); i++) {
            int r = carry;
            for(int j = 0; j < num2.size(); j++)
            	if(i - j >= 0 && i - j < num1.size())
                	r += (num1[num1.length() - 1 - i + j] - '0') * (num2[num2.length() - 1 - j] - '0');
            carry = r / 10;
            cout<<r<<endl;
            result[result.length() - 1 - i] += r % 10;
        }
        for(i = 0; i < result.length() - 1; i++)
        	if(result[i] != '0')
        		break;
        return result.substr(i);
    }
};