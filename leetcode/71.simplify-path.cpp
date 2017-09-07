/**
 * https://leetcode.com/problems/simplify-path/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    string simplifyPath(string path) {
        if(path == "/")
            return path;
        string result, t;
        vector<string> save;
        stringstream ps(path);
        while(getline(ps, t, '/')) {
            if(t == ".." && !save.empty()) save.pop_back();
            else if(t != "." && t != "" && t != "..") save.push_back(t);
        }
        for_each(save.begin(), save.end(), [&result](string& tmp){ result += "/" + tmp;});
        return result.length() == 0 ? "/" : result;
    }
};