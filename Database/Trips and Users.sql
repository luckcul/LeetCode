select Ta.Request_at as Day, round(bb/a, 2) as "Cancellation Rate" 
from (
    select count(*) as a, Request_at 
    from Trips inner join Users 
    where Trips.Client_Id = Users_Id and Banned = "NO"  AND
    to_days(Trips.Request_at) >= to_days("2013-10-01") and to_days(Trips.Request_at) <= to_days("2013-10-03")
    group by Request_at

) as Ta inner join (
    select distinct suba.Request_at, ifnull(subb.b, 0) as bb 
    from Trips as suba
    left join (
        select count(*) as b, Request_at 
        from Trips inner join Users 
        where Trips.Client_Id = Users_Id and Banned = "NO" and 
        (Trips.Status = "cancelled_by_driver" or Trips.Status = "cancelled_by_client") 
        group by Request_at
    ) as subb
    on suba.Request_at = subb.Request_at
    
)as Tb 
where Ta.Request_at = Tb.Request_at;


