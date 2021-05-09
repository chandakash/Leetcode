# Write your MySQL query statement below

select Request_at as "Day",

ROUND(sum(if(status !="completed",1,0))/count(status) , 2) as "Cancellation Rate"
# from Trips join Users on Trips.Client_Id = Users.Users_Id or Trips.Driver_Id = Users.Users_Id
from Trips

where Request_at between "2013-10-01" and "2013-10-03"
and Client_Id not in (select Users_Id from Users where Banned = "Yes")
and Driver_Id not in (select Users_Id from Users where Banned = "Yes")

group by Request_at


# with cte 
# as
# (
# select *
# from Trips left join Users on Trips.Client_Id = Users.Users_Id or Trips.Driver_Id = Users.Users_Id
# where Banned = "No" and Request_at between "2013-10-01" and "2013-10-03"

# )
# select Request_at as Day, ROUND(count(select status from )/sum(total) , 2)
# from cte
# group by Request_at
