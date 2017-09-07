# 
# https://leetcode.com/problems/swap-salary/
# By Nroskill
# runtime 560 ms
# language mysql
# 

UPDATE `salary` SET `sex` = CHAR(211 - ASCII(`sex`));