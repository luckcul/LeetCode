# Write your MySQL query statement below
select Name as Customers from Customers left join Orders on Customers.Id = Orders.CustomerId where CustomerId is NULL;
select Name as Customers from Customers where Id not in (select CustomerId from Orders);
