/**
 * https://leetcode.com/problems/basic-calculator-ii/
 * By Nroskill
 * runtime 13 ms
 * language cpp
 */

class Solution {
private:
    int fetchNext(string& s, int& index) {
        int tmp = 0;
        while(index < s.length() && s[index] >= '0' && s[index] <= '9')
            tmp = tmp * 10 + s[index++] - '0';
        return tmp;
    }

public:
    int calculate(string s) {
        int c = 0;
        char op = '+';
        int result = 0;
        int cur = 0;
        for(int i = 0; i < s.length(); i++)
        	if(s[i] != ' ')
        		s[c++] = s[i];
        s = s.substr(0, c);
        for(int i = 0; i < s.length(); i++)
            if(s[i] == '+' || s[i] == '-') {
                result += cur * (op == '+' ? 1 : -1);
                op = s[i];
            }
            else {
                cur = fetchNext(s, i);
                while(i < s.length() && (s[i] == '*' || s[i] == '/')) {
                    char o = s[i++];
                    int t = fetchNext(s, i);
                    cur = (o == '*' ? cur * t : cur / t);
                }
                i--;
            }
        return result += cur * (op == '+' ? 1 : -1);
    }
};