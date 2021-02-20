select count(title)
from movies 
join ratings 
on id = movie_id and rating = 10;
