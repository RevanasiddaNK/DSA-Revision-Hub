# Write your MySQL query statement below
-- SELECT customer_id , COUNT( visit_id ) AS  count_no_trans
-- FROM Visits
-- WHERE  visit_id NOT IN ( SELECT  visit_id FROM Transactions)
-- GROUP BY customer_id;

SELECT customer_id , COUNT( * ) AS  count_no_trans 
FROM Visits AS v
LEFT JOIN Transactions AS t
ON v.visit_id = t.visit_id
WHERE t.visit_id IS NULL
GROUP BY customer_id ;