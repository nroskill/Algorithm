# 
# https://leetcode.com/problems/department-highest-salary/
# By Nroskill
# runtime 647 ms
# language mysql
# 

SELECT a.Name AS Department, b.Name AS Employee, b.Salary AS Salary FROM Department a JOIN Employee b ON b.DepartmentId = a.Id JOIN (SELECT DepartmentId, MAX(Salary) AS Salary FROM Employee GROUP BY DepartmentId) c ON c.DepartmentId = a.Id WHERE b.Salary = c.Salary;