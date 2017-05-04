# 
# https://leetcode.com/problems/delete-duplicate-emails/
# By Nroskill
# runtime 684 ms
# language mysql
# 

DELETE
FROM Person
WHERE
    id NOT in (SELECT * FROM (SELECT MIN(a.Id) FROM Person a GROUP BY a.Email) b);