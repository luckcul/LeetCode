select * from stadium where id in (
    select distinct a.id
    from stadium a inner join stadium b inner join stadium c 
    where a.people >= 100 and b.people >= 100 and c.people >= 100 and a.id !=b.id and b.id != c.id and a.id != c.id
        and ((abs(a.id - b.id) = 1 and abs(a.id - c.id)=1 ) 
            or (abs(b.id - a.id) = 1 and abs(b.id - c.id) = 1) 
            or (abs(c.id - a.id) = 1 and abs(c.id - b.id) = 1)  )
) order by id;
