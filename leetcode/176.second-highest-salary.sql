# 
# https://leetcode.com/problems/second-highest-salary/
# By Nroskill
# runtime 877 ms
# language mysql
# 

SELECT MAX(Salary) AS SecondHighestSalary FROM Employee WHERE Salary < (SELECT MAX(Salary) FROM Employee);