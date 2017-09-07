/**
 * https://leetcode.com/problems/two-sum/
 * By Nroskill
 * runtime 212 ms
 * language javascript
 */

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
        var r = [];
        var i = 0, j = 0;
        for(i = 0; i < nums.length; i++)
            for(j = i + 1; j < nums.length; j++)
                if(nums[i] + nums[j] == target)
                {
                    r.push(i);
                    r.push(j);
                    return r;
                }
        return r;
};