# 
# https://leetcode.com/problems/customers-who-never-order/
# By Nroskill
# runtime 520 ms
# language mysql
# 

SELECT Name AS Customers FROM Customers WHERE Id NOT IN (SELECT DISTINCT CustomerId FROM Orders);