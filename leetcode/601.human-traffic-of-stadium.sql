# 
# https://leetcode.com/problems/human-traffic-of-stadium/
# By Nroskill
# runtime 817 ms
# language mysql
# 

SELECT DISTINCT(`d`.`id`) AS `id`, `d`.`date` AS `date`, `d`.`people` AS `people` 
FROM `stadium` AS `d` 
    INNER JOIN (
        SELECT `a`.`id` AS `id`
        FROM `stadium` AS `a` 
			INNER JOIN `stadium` AS `b` 
                ON `b`.`id` = `a`.`id` - 1 
            INNER JOIN `stadium` AS `c` 
                ON `c`.`id` = `a`.`id` + 1 
        WHERE `a`.`people` >= 100 
            AND `b`.`people` >= 100
            AND `c`.`people` >= 100
    ) AS `t` 
        ON `t`.`id` = `d`.`id` 
            OR `t`.`id` = `d`.`id` + 1 
            OR `t`.`id` = `d`.`id` - 1;