# Write your MySQL query statement below
SELECT FirstName, LastName, City, State FROM Address a
RIGHT JOIN Person p ON a.PersonId = p.PersonId