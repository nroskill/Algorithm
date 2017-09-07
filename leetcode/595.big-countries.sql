# 
# https://leetcode.com/problems/big-countries/
# By Nroskill
# runtime 3022 ms
# language mysql
# 

SELECT `name`, `population`, `area` FROM `World` WHERE `area` > 3000000 OR `population` > 25000000;