-- SELECT 
--     st.student_id, 
--     st.student_name, 
--     sb.subject_name, 
--     COUNT(*) AS attended_exams
-- FROM Examinations AS e
--  CROSS JOIN Subjects AS sb
--     ON sb.subject_name = e.subject_name
-- right JOIN  Students AS st
--     ON st.student_id = e.student_id
-- GROUP BY st.student_name, sb.subject_name
-- order by st.student_id, sb.subject_name;

SELECT 
    st.student_id, 
    st.student_name, 
    sb.subject_name, 
    COUNT(e.subject_name) AS attended_exams
FROM Students AS st
CROSS JOIN Subjects AS sb
LEFT JOIN Examinations AS e
    ON e.student_id = st.student_id
    AND e.subject_name = sb.subject_name
GROUP BY st.student_id, st.student_name, sb.subject_name
ORDER BY st.student_id, sb.subject_name;
