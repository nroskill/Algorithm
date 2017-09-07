# 
# https://leetcode.com/problems/consecutive-numbers/
# By Nroskill
# runtime 1092 ms
# language mysql
# 

SELECT DISTINCT a.Num AS ConsecutiveNums FROM Logs a, Logs b, Logs c WHERE a.Num = b.Num AND b.Num = c.Num AND a.Id + 1 = b.Id AND a.Id + 2 = c.Id;