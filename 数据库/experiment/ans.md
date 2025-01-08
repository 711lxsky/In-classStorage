```mysql
INSERT INTO Student (Name, Gender, BirthDate, ClassID) VALUES
    ('新学生', '男', '2002-01-01', 1);

-- 按学号查询
SELECT s.StudentID, s.Name, s.Gender, s.BirthDate, c.ClassName, m.MajorName
FROM Student s
         JOIN Class c ON s.ClassID = c.ClassID
         JOIN Major m ON c.MajorID = m.MajorID
WHERE s.StudentID = 2;

-- 按姓名查询
SELECT s.StudentID, s.Name, s.Gender, s.BirthDate, c.ClassName, m.MajorName
FROM Student s
         JOIN Class c ON s.ClassID = c.ClassID
         JOIN Major m ON c.MajorID = m.MajorID
WHERE s.Name = '张三';

-- 按专业查询
SELECT s.StudentID, s.Name, s.Gender, s.BirthDate, c.ClassName, m.MajorName
FROM Student s
         JOIN Class c ON s.ClassID = c.ClassID
         JOIN Major m ON c.MajorID = m.MajorID
WHERE m.MajorName = '计算机科学';

# 插入成绩数据
INSERT INTO Grades (StudentID, CourseID, Score) VALUES
                                                    (1, 1, 85.5), (1, 2, 70.0), (1, 3, 55.0), -- 张三
                                                    (2, 1, 60.0), (2, 2, 90.0), (2, 4, 75.0), -- 李四
                                                    (3, 2, 50.0), (3, 3, 40.0), (3, 5, 65.0), -- 王五
                                                    (4, 1, 45.0), (4, 2, 80.0), (4, 3, 55.0), -- 赵六
                                                    (5, 1, 92.0), (5, 3, 58.0), (5, 5, 88.0); -- 孙七


# 查询学生的课程、性质、学期、学分及成绩
SELECT DISTINCT s.Name, c.CourseName, cu.CourseType, cu.Semester, c.Credits, g.Score
FROM Grades g
         JOIN Course c ON g.CourseID = c.CourseID
         JOIN Curriculum cu ON c.CourseID = cu.CourseID
         JOIN Student s ON g.StudentID = s.StudentID;



-- 必修课平均成绩
SELECT s.Name,
       AVG(g.Score * c.Credits) / SUM(c.Credits) AS WeightedAverage
FROM Grades g
         JOIN Course c ON g.CourseID = c.CourseID
         JOIN Curriculum cu ON c.CourseID = cu.CourseID
         JOIN Student s ON g.StudentID = s.StudentID
WHERE cu.CourseType = '必修'
GROUP BY s.StudentID, s.Name;


-- 所有课程平均成绩
SELECT s.Name,
       AVG(g.Score * c.Credits) / SUM(c.Credits) AS WeightedAverage
FROM Grades g
         JOIN Course c ON g.CourseID = c.CourseID
         JOIN Student s ON g.StudentID = s.StudentID
GROUP BY s.StudentID, s.Name;


# 查询学生被哪些教师教过课
SELECT
    s.Name AS StudentName,
    t.TeacherName
FROM Grades g
         JOIN Student s ON g.StudentID = s.StudentID
         JOIN Teaching te ON te.ClassID = s.ClassID
         JOIN Teacher t ON te.TeacherID = t.TeacherID
# WHERE g.StudentID = 1
GROUP BY s.Name, t.TeacherName;


# 查询快要被开除的学生
SELECT s.StudentID, s.Name, SUM(c.Credits) AS TotalFailedCredits
FROM Grades g
         JOIN Course c ON g.CourseID = c.CourseID
         JOIN Student s ON g.StudentID = s.StudentID
         JOIN Curriculum cu ON c.CourseID = cu.CourseID
WHERE g.Score < 60 AND cu.CourseType = '必修'
GROUP BY s.StudentID, s.Name
HAVING SUM(c.Credits) BETWEEN 7 AND 10

UNION

SELECT s.StudentID, s.Name, SUM(c.Credits) AS TotalFailedCredits
FROM Grades g
         JOIN Course c ON g.CourseID = c.CourseID
         JOIN Student s ON g.StudentID = s.StudentID
         JOIN Curriculum cu ON c.CourseID = cu.CourseID
WHERE g.Score < 60 AND cu.CourseType = '选修'
GROUP BY s.StudentID, s.Name
HAVING SUM(c.Credits) BETWEEN 12 AND 15;



```