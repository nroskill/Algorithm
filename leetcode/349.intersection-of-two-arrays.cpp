/**
 * https://leetcode.com/problems/intersection-of-two-arrays/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> sb1;
        multiset<int> sb2;
        vector<int> result;
        if(nums1.size() > nums2.size())
            return intersection(nums2, nums1);
        for(int i = 0; i < nums1.size(); i++)
            if(sb1.count(nums1[i]) == 0)
                sb1.insert(nums1[i]);
		for(int i = 0; i < nums2.size(); i++)
            sb2.insert(nums2[i]);
        auto i = sb1.begin(), j = sb2.begin();
        while(i != sb1.end() && j != sb2.end())
			if(*i == *j) {
                result.push_back(*i);
        		i++;
        		j++;
			}
            else if(*i < *j)
                i++;
            else
                j++;
        return result;
    }
};