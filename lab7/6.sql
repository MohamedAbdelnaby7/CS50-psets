SELECT songs.name 
FROM songs 
JOIN artists
ON artists.id = artist_id AND artists.name = 'Post Malone';
