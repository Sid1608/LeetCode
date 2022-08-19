# Write your MySQL query statement below


UPDATE salary SET sex=CASE sex WHEN 'f' then 'm' ELSE 'f' END;