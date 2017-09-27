# Write your MySQL query statement below
select Score,(select count(distinct(b.Score)) from Scores b where b.Score > a.Score) + 1 as Rank
from Scores a 
order by Score desc;

# faster solution

select 
    Score, 
    (select count(*) from (select distinct(Score) as s from Scores) tmp where tmp.s >= Score) as Rank
From Scores 
order by Score desc;