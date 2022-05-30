CREATE TABLE IF NOT EXISTS member(
	id VARCHAR(20) NOT NULL,
	passwd VARCHAR(20),
	name VARCHAR(30),
	PRIMARY KEY (id)
)default CHARSET=utf8;


select * from member;