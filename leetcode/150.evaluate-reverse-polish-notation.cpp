/**
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    int atoi(string a) {
        int r = 0;
        int flag = a[0] == '-' ? -1 : 1;
        for(int i = a[0] == '-' ? 1 : 0; i < a.length(); i++) {
            r *= 10;
            r += a[i] - '0';
        }
        return r * flag;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> save;
        for(int i = 0; i < tokens.size(); i++) {
            int r;
            if(tokens[i][tokens[i].length() - 1] >= '0' && tokens[i][tokens[i].length() - 1] <= '9')
                r = atoi(tokens[i]);
            else {
                int t = save.top();
                save.pop();
                r = save.top();
                save.pop();
                switch(tokens[i][0]) {
                    case '+':
                        r += t;
                        break;
                    case '-':
                        r -= t;
                        break;
                    case '*':
                        r *= t;
                        break;
                    case '/':
                        r /= t;
                        break;
                }
            }
            save.push(r);
        }
        return save.top();
    }
};