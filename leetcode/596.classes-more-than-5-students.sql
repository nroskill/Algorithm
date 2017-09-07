# 
# https://leetcode.com/problems/classes-more-than-5-students/
# By Nroskill
# runtime 3122 ms
# language mysql
# 

# Write your MySQL query statement below
SELECT `class` FROM `courses` GROUP BY `class` HAVING COUNT(DISTINCT `student`) > 4;