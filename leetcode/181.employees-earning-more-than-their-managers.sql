# 
# https://leetcode.com/problems/employees-earning-more-than-their-managers/
# By Nroskill
# runtime 944 ms
# language mysql
# 

SELECT a.Name AS Employee FROM Employee a JOIN Employee b ON a.ManagerId = b.Id WHERE a.Salary > b.Salary; 