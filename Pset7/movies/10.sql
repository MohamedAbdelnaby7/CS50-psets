select name 
from people 
join directors on people.id = person_id
join ratings on directors.movie_id = ratings.movie_id
where rating >= 9
group by name;
