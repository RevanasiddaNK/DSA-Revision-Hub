SELECT euni.unique_id, e.name
FROM Employees as e
LEFT JOIN EmployeeUNI AS euni
ON e.id = euni.id;

