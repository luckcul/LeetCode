# Write your MySQL query statement below
select * 
from (
select if(id < (select max(id) from seat), if(id mod 2 = 0, id-1, id+1), if(id mod 2 = 0, id-1, id)) as id, student
from seat t 
    ) t
order by id