# 
# https://leetcode.com/problems/rising-temperature/
# By Nroskill
# runtime 780 ms
# language mysql
# 

SELECT b.Id FROM Weather a JOIN Weather b ON TO_DAYS(a.Date) + 1 = TO_DAYS(b.Date) WHERE a.Temperature < b.Temperature;