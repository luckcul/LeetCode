# Write your MySQL query statement below
select Email from Person group by Email having count(*) > 1;
select distinct a.Email from Person a inner join Person b on a.Email=b.Email where a.Id != b.Id;