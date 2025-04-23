# Write your MySQL query statement below
SELECT e.name , b.bonus
FROM Employee AS e
LEFT JOIN Bonus AS b
ON b.empId = e.empId
WHERE bonus < 1000 || bonus IS NULL;