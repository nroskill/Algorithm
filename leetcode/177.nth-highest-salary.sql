# 
# https://leetcode.com/problems/nth-highest-salary/
# By Nroskill
# runtime 856 ms
# language mysql
# 

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N = N - 1;
  RETURN (
      SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT N,1
  );
END