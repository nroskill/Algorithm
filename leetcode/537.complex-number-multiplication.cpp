/**
 * https://leetcode.com/problems/complex-number-multiplication/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int val(string a, int start, int end) {
        int flag = 1;
        int i = start + 1, result = 0;
        if(a[start] == '-')
            flag = -1;
        else
            i--;
        for(; i <= end; i++) {
            result = result * 10 + a[i] - '0';
        }
        return flag * result;
    }
    
    string complexNumberMultiply(string a, string b) {
        int i;
        for(i = 0; i < a.length(); i++)
            if(a[i] == '+')
                break;
        int v1 = val(a, 0, i - 1);
        int v2 = val(a, i + 1, a.length() - 2);
        for(i = 0; i < b.length(); i++)
            if(b[i] == '+')
                break;
        int v3 = val(b, 0, i - 1);
        int v4 = val(b, i + 1, b.length() - 2);
        return to_string(v1 * v3 - v2 * v4) + "+" + to_string(v1 * v4 + v2 * v3) + "i";
        
    }
};