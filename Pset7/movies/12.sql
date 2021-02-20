select title
from people 
join stars on people.id = stars.person_id and (people.name = 'Johnny Depp' or people.name = 'Helena Bonham Carter')
join movies on stars.movie_id = movies.id
group by title
having count(title) > 1;
