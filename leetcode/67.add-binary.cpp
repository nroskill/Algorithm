/**
 * https://leetcode.com/problems/add-binary/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length())
            return addBinary(b, a);
        int f = 0;
        string ret = string(a.length() + 1, '0');
        for(int i = 0; i < a.length() || f; i++) {
            f += i < a.length() ? a[a.length() - 1 - i] - '0' : 0;
            f += i < b.length() ? b[b.length() - 1 - i] - '0' : 0;
            ret[ret.length() - 1 - i] += f % 2;
            f /= 2;
        }
        return ret[0] == '0' ? ret.substr(1) : ret;
    }
};