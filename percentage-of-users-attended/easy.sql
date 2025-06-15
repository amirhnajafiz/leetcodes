# Write your MySQL query statement below
SELECT contest_id, 100 * ROUND(COUNT(user_id) / (SELECT COUNT(*) FROM Users), 4) as percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;
