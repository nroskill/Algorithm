/**
 * https://leetcode.com/problems/base-7/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    string convertToBase7(int num) {
        string result = "";
        int flag, sum;
        if(!num)
            return string("0");
        flag = num / abs(num);
        num = abs(num);
        sum = pow(7, (int)(log(num) / log(7)));
        while(num || sum) {
        	int temp = num / sum;
            result += '0' + temp;
            num -= sum * temp;
			sum /= 7;
        }
        return flag == 1 ? result : string("-") + result;
    }
};