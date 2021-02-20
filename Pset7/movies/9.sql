select name 
from people 
join stars on people.id = person_id
join movies on movies.id = movie_id
where year = 2004
group by name
order by birth, name;
