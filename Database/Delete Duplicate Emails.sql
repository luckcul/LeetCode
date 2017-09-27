# Write your MySQL query statement below
delete from Person where Person.Id not in (select * from (select min(Id) as ids from Person  group by Email) as t) ;