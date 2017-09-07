/**
 * https://leetcode.com/problems/implement-strstr/
 * By Nroskill
 * runtime 66 ms
 * language cpp
 */

class Solution {
public:
    void init(string& a, vector<int>& kmp) {
	    if(a.length() < 1)
		    return;
	    kmp[0] = 0;
	    for(int i = 1; i < a.length(); i++) {
		    int j = i - 1;
		    char x;
		    for(j = kmp[j]; j > 0 ; j = kmp[j - 1])
			    if(a[j] == a[i]) {
				    kmp[i] = j + 1;
			    	break;
			    }
		    if(j == 0)
		    	kmp[i] = a[i] == a[0] ? 1 : 0;
	   }
    }

    int cmp(string& target, string& a, vector<int>& kmp) {
	    int i = 0, j = 0;
	    while(i < target.length() && j < a.length()) {
		    cout<<i<<" "<<j<<endl;
		    if(target[i] == a[j]) {
			    i++;
			    j++;
		    }
		    else if(j == 0)
			    i++;
		    else
			    j = kmp[j - 1];
	    }
	    if(j == a.length())
		    return i - j;
    	return -1;
    }
    
    int strStr(string haystack, string needle) {
        vector<int> kmp(needle.length(), 0);
        init(needle, kmp);
        return cmp(haystack, needle, kmp);
    }
};