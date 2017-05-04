# 
# https://leetcode.com/problems/rank-scores/
# By Nroskill
# runtime 1408 ms
# language mysql
# 

SELECT r.Score, (SELECT COUNT(DISTINCT Score) FROM Scores t WHERE t.Score >= r.Score) AS Rank From Scores r ORDER BY Score DESC;