/**
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 * By Nroskill
 * runtime 25 ms
 * language cpp
 */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.length() < 1 || words.size() < 1)
            return result;
        unordered_map<string, int> target;
        for(auto& i : words)
            target[i]++;
        int wordLength = words[0].length();
        for(int offset = 0; offset < wordLength; offset++) {
            unordered_map<string, int> current;
            int left = offset;
            int right = left;
            while(right < s.length()) {
                string temp = string(s, right, wordLength);
                
                if(target.count(temp) == 0) {
                    current.clear();
                    left = right + wordLength;
                    right = left;
                    continue;
                }
                
                int times = current[temp] + 1;
                if(times > target[temp]) {
                    current[string(s, left, wordLength)]--;
                    left += wordLength;
                }
                else if(times < target[temp] || (times == target[temp] && right - left + wordLength != words.size() * wordLength)) {
                    current[temp] = times;
                    right += wordLength;
                }
                else {
                    result.push_back(left);
                    current[temp] = times;
                    right += wordLength;
                    current[string(s, left, wordLength)]--;
                    left += wordLength;
                }
            }
        }
        return result;
    }
};