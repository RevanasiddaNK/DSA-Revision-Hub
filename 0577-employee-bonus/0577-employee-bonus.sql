SELECT e.name,  b.bonus 
FROM Employee AS e 
LEFT JOIN Bonus AS b
ON b.empId = e.empId
WHERE B.bonus < 1000 OR Bonus IS NULL;