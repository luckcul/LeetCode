select Department.Name as Department, a.Name as Employee, Salary
from Employee a inner join Department 
where a.DepartmentId = Department.Id
    and 3 > (
        select count(distinct b.Salary) from Employee b where a.Salary < b.Salary and a.DepartmentId = b.DepartmentId
    );