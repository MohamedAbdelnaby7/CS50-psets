select name 
from people 
join stars on people.id = person_id
join movies on movies.id = movie_id
where title = "Toy Story";
