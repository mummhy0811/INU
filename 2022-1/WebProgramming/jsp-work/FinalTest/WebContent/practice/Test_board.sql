CREATE TABLE IF NOT EXISTS test_board(
	id VARCHAR(20) NOT NULL,
	name VARCHAR(20),
	donation int(11),
	PRIMARY KEY (id)
);

INSERT INTO test_board VALUES('1', 'È«±æµ¿', 100000);
INSERT INTO test_board VALUES('2', 'È«±æ¼ø', 200000);
select * from Test_board;