# 
# https://leetcode.com/problems/trips-and-users/
# By Nroskill
# runtime 119 ms
# language mysql
# 

SELECT a.Request_at AS Day, ROUND(COUNT(IF(a.`Status` != 'completed', 1, NULL))/COUNT(*), 2) AS `Cancellation Rate` FROM Trips a JOIN Users b ON a.Client_Id = b.Users_Id WHERE b.Banned = 'No' AND (a.Request_at BETWEEN '2013-10-01' AND '2013-10-03') GROUP BY a.Request_at;