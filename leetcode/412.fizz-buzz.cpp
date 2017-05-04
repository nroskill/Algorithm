/**
 * https://leetcode.com/problems/fizz-buzz/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    string itoc(int n) {
	    string result = "";
    	string temp = "0";
    	while(n > 0) { 
	    	result = "0" + result;
	    	result[0] += n % 10;
	    	n /= 10;
	    }
    	return result;
    }

    vector<string> fizzBuzz(int n) {
        vector<string> result(n, string(""));
        for(int i = 1; i <= n; i++)
        	result[i - 1] = itoc(i);
        for(int i = 1; i * 3 <= n; i++) {
			result[i * 3 - 1] = string("Fizz");
			if(i * 5 <= n)
				result[i * 5 - 1] = string("Buzz");
		}
		for(int i = 1; i * 15 <= n; i++)
			if(i * 15 <= n)
				result[i * 15 - 1] = string("FizzBuzz");
		return result;
    }
};