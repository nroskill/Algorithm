/**
 * https://leetcode.com/problems/decode-ways/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    int numDecodings(string s) {
        if(s.length() < 1 || s[0] == '0')
            return 0;
        if(s.length() == 1)
        	return 1;
        int c = 10 * s[0] - 11 * '0' + s[1]; 
        if(s[1] == '0' && c > 26)
        	return 0;
        int last = 1;
        int cur  = (s[1] != '0' && c <= 26 ? 2 : 1);
        for(int i = 2; i < s.length(); i++) {
            c = 10 * s[i - 1] - 11 * '0' + s[i];
            if(c == 0)
                return 0;
            if(s[i - 1] == '0') {
            	last = cur;
				continue;
            }
            
            if(s[i] == '0') {
            	if(c <= 26)
            		swap(cur, last);
            	else//0
            		return 0;
			}
            else if(c <= 26) {
                int t = last + cur;
                last = cur;
                cur = t;
            }
            else
            	last = cur;
        }
        return cur;
    }
};