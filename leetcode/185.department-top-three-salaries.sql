# 
# https://leetcode.com/problems/department-top-three-salaries/
# By Nroskill
# runtime 990 ms
# language mysql
# 

SELECT
    a.Name AS Department, 
    b.Name AS Employee, 
    b.Salary AS Salary 
FROM Department a 
    JOIN Employee b 
    ON b.DepartmentId = a.Id
WHERE (SELECT COUNT(DISTINCT Salary) FROM Employee d WHERE d.DepartmentId = a.Id AND d.Salary > b.Salary) < 3
ORDER BY a.Id ASC, b.Salary DESC;