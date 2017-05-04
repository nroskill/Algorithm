/**
 * https://leetcode.com/problems/happy-number/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:	
    int judge[101] = {0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1};

	int value(int num) {
		int result = 0;
		while(num > 0) {
			result += (num % 10) * (num % 10);
			num /= 10; 
		}
		return result;
	}

    bool isHappy(int num) {
    	while(num > 100)
    	    num = value(num);
    	return judge[num];
	}
};