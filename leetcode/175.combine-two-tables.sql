# 
# https://leetcode.com/problems/combine-two-tables/
# By Nroskill
# runtime 938 ms
# language mysql
# 

SELECT FirstName, LastName, City, State FROM Person LEFT JOIN Address ON Person.PersonId = Address.PersonId