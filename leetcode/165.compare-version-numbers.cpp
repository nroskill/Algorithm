/**
 * https://leetcode.com/problems/compare-version-numbers/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int atoi(string a) {
        int r = 0;
        for(int i = 0; i < a.length(); i++)
            r = r * 10 + a[i] - '0';
        return r;
    }
    
    int compareVersion(string version1, string version2) {
        if(version1.length() == 0 && version2.length() == 0)
            return 0;
        int p1 = version1.find_first_of('.');
        int p2 = version2.find_first_of('.');
        int v1 = atoi(version1.substr(0, p1 == string::npos ? version1.length() : p1));
        int v2 = atoi(version2.substr(0, p2 == string::npos ? version2.length() : p2));
        if(v1 != v2)
            return v1 > v2 ? 1 : -1;
        return compareVersion(p1 == string::npos ? "" : version1.substr(p1 + 1), p2 == string::npos ? "" : version2.substr(p2 + 1)); 
    }
};