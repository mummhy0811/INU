CREATE TABLE IF NOT EXISTS test_board(
	id VARCHAR(20) NOT NULL,
	name VARCHAR(20),
	donation int(11),
	PRIMARY KEY (id)
);

INSERT INTO test_board VALUES('1', 'ȫ�浿', 100000);
INSERT INTO test_board VALUES('2', 'ȫ���', 200000);
select * from Test_board;