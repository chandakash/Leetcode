# Write your MySQL query statement below

#using join and Subdate function , subdate returns the date minus the days provided inside params.
# select Today.id
# from Weather Today join Weather Yesterday
#     on Today.Temperature > Yesterday.Temperature
#     and SUBDATE(Today.recordDate, 1) = Yesterday.recordDate;
    
# using DATEDIFF
select Today.id
from Weather Today join Weather Yesterday
    on Today.Temperature > Yesterday.Temperature
    and DATEDIFF(Today.recordDate, Yesterday.recordDate) = 1;
    
    
    
    