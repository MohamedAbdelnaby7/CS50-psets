-- Keep a log of any SQL queries you execute as you solve the mystery.
-- getting the report of the theft happened in Chamberlin Street on 2020/07/28
select description 
from crime_scene_reports
where month = 7 and year = 2020 and day =28 and street = 'Chamberlin Street';

-- getting the witnesses transcripts that has the word courthouse in it
select transcript, name 
from interviews 
where transcript like '%courthouse%' and year = 2020 and month = 7 and day = 28;

-- getting the timing of the earliest flight leaving fiftyville city
select flights.hour, flights.minute 
from flights
where flights.origin_airport_id = (select id from airports where city = 'Fiftyville') and flights.year = 2020 and flights.month = 7 and flights.day = 29
order by flights.hour, flights.minute
limit 1;

select name, phone_number, flight_id, flights.destination_airport_id
from people 
join bank_accounts
on people.id = bank_accounts.person_id
join atm_transactions
on 
(
	bank_accounts.account_number = atm_transactions.account_number 
	and atm_transactions.year=2020 and atm_transactions.month = 7 and atm_transactions.day = 28 
	and atm_location = 'Fifer Street' and atm_transactions.transaction_type = 'withdraw'
)
join courthouse_security_logs
on 
(
	people.license_plate = courthouse_security_logs.license_plate
	and courthouse_security_logs.year = 2020 and courthouse_security_logs.month = 7 and courthouse_security_logs.day = 28 
	and courthouse_security_logs.hour = 10 and courthouse_security_logs.minute < 25
	and courthouse_security_logs.activity = 'exit'
)
join passengers 
on people.passport_number = passengers.passport_number
join flights
on 
(
	passengers.flight_id = flights.id
	and flights.year = 2020 and flights.month = 7 and flights.day = 29
	and flights.hour = 8 and flights.minute = 20
	and flights.origin_airport_id = (SELECT id from airports where city = 'Fiftyville')
)
join phone_calls
on 
(
	people.phone_number = phone_calls.caller
	and phone_calls.year = 2020 and phone_calls.month = 7 and phone_calls.day = 28
	and phone_calls.duration < 60
);

select name 
from people 
join phone_calls 
on people.phone_number = phone_calls.receiver and phone_calls.caller = '(367) 555-5533'
and phone_calls.year = 2020 and phone_calls.month = 7 and phone_calls.day = 28 and phone_calls.duration < 60;

select city 
from airports
where airports.id = 4; 
