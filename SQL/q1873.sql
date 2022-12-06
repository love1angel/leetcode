SELECT employee_id,
       if(employee_id % 2 = 1 AND name REGEXP "^[^M]", salary, 0) bonus
FROM Employees
ORDER BY employee_id;
