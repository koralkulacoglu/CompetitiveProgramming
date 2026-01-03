-- Write your PostgreSQL query statement below

select
    eu.unique_id,
    e.name
from
    employees e
left join
    employeeUNI eu
on
    e.id = eu.id
