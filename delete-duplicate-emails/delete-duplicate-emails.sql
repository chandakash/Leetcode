# Write your MySQL query statement below
#delete p1 from Person p1 inner join Person p2 on p1.Email= p2.Email and p1.Id > p2.Id;

DELETE from Person 
where Id NOT IN 
(
    select * from (select MIN(Id) from Person P1 group by Email) P 
)