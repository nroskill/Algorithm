/**
 * https://leetcode.com/problems/fraction-to-recurring-decimal/
 * By Nroskill
 * runtime 0 ms
 * language cpp
 */

class Solution {
public:
    string h(long long int a) {
        if(a == 0)
            return "0";
        string result;
        while(a > 0) {
            result = string(1, '0' + a % 10) + result;
            a /= 10;
        }
        return result;
    }
    
    string fractionToDecimal_h(long long int numerator, long long int denominator) {
        bool flag = true;
        if(numerator < 0) {
            numerator = -numerator;
            flag = !flag;
        }
        if(denominator < 0) {
            denominator = -denominator;
            flag = !flag;
        }
        if(!flag)
            return "-" + fractionToDecimal_h(numerator, denominator);
        string result = h(numerator / denominator);
        numerator %= denominator;
        if(numerator == 0)
            return result;
        result += ".";
        unordered_map<long long int, long long int> helper;
        numerator *= 10;
        while(true) {
            if(numerator == 0)
                return result;
            if(helper.find(numerator) != helper.end())
                break;
            if(numerator < denominator) {
                result += "0";
                helper[numerator] = result.length() - 1;
                numerator *= 10;
                continue;
            }
            result += string(1, '0' + numerator / denominator);
            helper[numerator] = result.length() - 1;
            numerator %= denominator;
            numerator *= 10;
        }
        result.insert(helper[numerator], "(");
        result += ")";
        return result;
    }
    
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        return fractionToDecimal_h(numerator, denominator);
    }
};