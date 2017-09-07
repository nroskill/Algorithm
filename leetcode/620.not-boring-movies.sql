# 
# https://leetcode.com/problems/not-boring-movies/
# By Nroskill
# runtime 200 ms
# language mysql
# 

SELECT * FROM `cinema` WHERE MOD(`id`, 2) = 1 AND `description` != 'boring' ORDER BY `rating` DESC;