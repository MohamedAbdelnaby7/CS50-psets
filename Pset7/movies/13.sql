select name
from people 
join stars 
on people.id = stars.person_id 
and stars.movie_id in ( select movie_id from people join stars on people.id=stars.person_id and people.name = 'Kevin Bacon' and people.birth= 1958)
where name <> 'Kevin Bacon'
group by name;


