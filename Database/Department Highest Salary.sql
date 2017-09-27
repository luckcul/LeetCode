select Department.Name as Department, newEmployee.Name as Employee, newEmployee.Salary
from 
(
select a.Name, a.Salary, a.DepartmentId 
from Employee a inner join 
    (select max(Salary) as maxS, DepartmentId from Employee group by DepartmentId) as b
where a.Salary = b.maxS and a.DepartmentId = b.DepartmentId
) as newEmployee

inner join 
Department 
where newEmployee.DepartmentId = Department.Id;