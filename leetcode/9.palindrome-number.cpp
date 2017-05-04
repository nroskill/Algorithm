/**
 * https://leetcode.com/problems/palindrome-number/
 * By Nroskill
 * runtime 139 ms
 * language cpp
 */

class Solution {
public:
    long long int reverse(int x) {
        long long int result = 0;
        while(x > 0) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }

    bool isPalindrome(int x) {
        long long int rev = reverse(x);
        return (rev <= (int)0x7fffffff && rev >= (int)0x80000000 && x == rev);
    }
};