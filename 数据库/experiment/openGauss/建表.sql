-- 删除已有的表
-- 注意要先删除参照表（如SC），再删除被参照表（如Student，Course）
DROP TABLE SC;
DROP TABLE Student;
DROP TABLE Course;


-- 创建基本表
-- 注意要先创建被参照表（如Student，Course），再创建参照表（如SC）
CREATE TABLE Student(
Sno CHAR(10) PRIMARY KEY,	-- 列级完整性约束的方式，定义主码
Sname CHAR(10),
Ssex CHAR(5),
Sage SMALLINT,
Sdept CHAR(10)
); 


CREATE TABLE Course(
Cno CHAR(10) PRIMARY KEY,
Cname CHAR(20),
Cpno CHAR(10),
Ccredit SMALLINT,
FOREIGN KEY (Cpno) REFERENCES Course(Cno)	-- 表级完整性约束的方式，定义外码；注意参照列Cpno必须加括号
);


CREATE TABLE SC(
Sno CHAR(10) REFERENCES student(Sno),	-- 列级完整性约束的方式，定义外码
Cno CHAR(10) REFERENCES course(Cno),
Grade SMALLINT,
PRIMARY KEY (Sno, Cno)	-- 表级完整性约束的方式，定义主码
);


-- 向基本表中插入数据
INSERT INTO Student VALUES ('95001','李勇','男',20,'CS');
INSERT INTO Student VALUES ('95002','刘晨','女',19,'IS');
INSERT INTO Student VALUES ('95003','王敏','女',18,'MA');
INSERT INTO Student VALUES ('95004','张立','男',19,'IS');


-- 如果根据参照关系表中一行参照了另外一行，应先插入被参照行（如('6',...,...,...)），后插入参照行（如(...,...,'6',...)）
INSERT INTO Course VALUES ('6','数据处理',NULL,2);
INSERT INTO Course VALUES ('7','PASCAL语言','6',4);
INSERT INTO Course VALUES ('5','数据结构','7',4);
INSERT INTO Course VALUES ('1','数据库','5',4);
INSERT INTO Course VALUES ('2','数学',NULL,2);
INSERT INTO Course VALUES ('3','信息系统','1',4);
INSERT INTO Course VALUES ('4','操作系统','6',3);



INSERT INTO SC VALUES ('95001','1',92);
INSERT INTO SC VALUES ('95001','2',65);
INSERT INTO SC VALUES ('95001','4',88);
INSERT INTO SC VALUES ('95002','2',90);
INSERT INTO SC VALUES ('95002','5',73);



