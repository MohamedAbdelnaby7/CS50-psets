SELECT AVG(energy) 
FROM songs 
JOIN artists
ON artists.id = artist_id AND artists.name = 'Drake';
