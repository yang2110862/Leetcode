-- 员工奖金
select name, bonus
from Employee left join bonus
on Employee.EmpId = Bonus.EmpId
where bonus < 1000 or bonus is null
