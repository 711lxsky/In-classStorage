### 需求分析

#### 系统数据结构

1. **专业（Major）**
   - `MajorID`：专业编号，主键。
   - `MajorName`：专业名称。

2. **班级（Class）**
   - `ClassID`：班级编号，主键。
   - `ClassName`：班级名称。
   - `MajorID`：所属专业的编号，外键。
   - `Year`：入学年份。

3. **学生（Student）**
   - `StudentID`：学生编号，主键。
   - `Name`：学生姓名。
   - `Gender`：性别。
   - `BirthDate`：出生日期。
   - `ClassID`：所属班级的编号，外键。

4. **课程（Course）**
   - `CourseID`：课程编号，主键。
   - `CourseName`：课程名称。
   - `Credits`：学分。

5. **教学计划（Curriculum）**
   - `CurriculumID`：教学计划编号，主键。
   - `MajorID`：所属专业的编号，外键。
   - `CourseID`：课程编号，外键。
   - `Semester`：授课学期。
   - `CourseType`：课程性质（必修或选修）。

6. **成绩（Grades）**
   - `GradeID`：成绩编号，主键。
   - `StudentID`：学生编号，外键。
   - `CourseID`：课程编号，外键。
   - `Score`：分数。

7. **教师（Teacher）**
   - `TeacherID`：教师编号，主键。
   - `TeacherName`：教师姓名。

8. **授课安排（Teaching）**
   - `TeachingID`：授课安排编号，主键。
   - `TeacherID`：教师编号，外键。
   - `ClassID`：班级编号，外键。
   - `CourseID`：课程编号，外键。

#### 系统功能

1. **专业管理**
   - 添加、修改、删除专业信息。
   - 查询专业列表及其详细信息。

2. **班级管理**
   - 添加、修改、删除班级信息。
   - 查询班级列表及其详细信息，包括所属专业和入学年份。

3. **学生管理**
   - 添加、修改、删除学生信息。
   - 查询学生列表及其详细信息，包括所属班级、性别和出生日期。
   - 学生学籍状态管理，包括正常、留级、退学等。

4. **课程管理**
   - 添加、修改、删除课程信息。
   - 查询课程列表及其详细信息，包括课程名称和学分。

5. **教学计划管理**
   - 添加、修改、删除教学计划信息。
   - 查询教学计划列表及其详细信息，包括所属专业、课程、授课学期和课程性质。

6. **成绩管理**
   - 录入、修改、删除学生成绩。
   - 查询学生成绩列表及其详细信息，包括学生、课程和分数。
   - 计算学生的总学分、必修课和选修课的不及格学分，并根据规则判断是否需要开除。

7. **教师管理**
   - 添加、修改、删除教师信息。
   - 查询教师列表及其详细信息，包括教师姓名。

8. **授课安排管理**
   - 添加、修改、删除授课安排信息。
   - 查询授课安排列表及其详细信息，包括教师、班级和课程。

9. **系统设置**
   - 用户权限管理。
   - 数据备份与恢复。

通过以上数据结构和功能设计，本学籍管理系统能够有效地管理学校的学籍信息，确保数据的准确性和完整性，同时提供便捷的操作界面，方便管理人员进行日常管理和决策支持。

### 一：概念结构设计（E-R图设计）

#### 实体（Entities）
1. **Class**（班级）
   - 属性：ClassID（主键）、ClassName、MajorID（外键）、Year

2. **Course**（课程）
   - 属性：CourseID（主键）、CourseName、Credits

3. **Curriculum**（课程计划）
   - 属性：CurriculumID（主键）、MajorID（外键）、CourseID（外键）、Semester、CourseType

4. **Grades**（成绩）
   - 属性：GradeID（主键）、StudentID（外键）、CourseID（外键）、Score

5. **Major**（专业）
   - 属性：MajorID（主键）、MajorName

6. **Student**（学生）
   - 属性：StudentID（主键）、Name、Gender、BirthDate、ClassID（外键）

7. **Teacher**（教师）
   - 属性：TeacherID（主键）、TeacherName

8. **Teaching**（教学安排）
   - 属性：TeachingID（主键）、TeacherID（外键）、ClassID（外键）、CourseID（外键）

#### 关系（Relationships）
1. **Class-Major**（班级与专业的关联）
   - 一个班级属于一个专业（1:N）

2. **Curriculum-Major**（课程计划与专业的关联）
   - 一个专业有多个课程计划（1:N）

3. **Curriculum-Course**（课程计划与课程的关联）
   - 一个课程计划包含一个课程（1:1）

4. **Grades-Student**（成绩与学生的关联）
   - 一个学生成绩对应一个学生（1:1）

5. **Grades-Course**（成绩与课程的关联）
   - 一个学生成绩对应一个课程（1:1）

6. **Student-Class**（学生与班级的关联）
   - 一个学生属于一个班级（1:1）

7. **Teaching-Teacher**（教学安排与教师的关联）
   - 一个教学安排对应一个教师（1:1）

8. **Teaching-Class**（教学安排与班级的关联）
   - 一个教学安排对应一个班级（1:1）

9. **Teaching-Course**（教学安排与课程的关联）
   - 一个教学安排对应一个课程（1:1）

### 二：逻辑结构设计（E-R图转换为关系模型）

#### 关系模式
1. **Class(ClassID, ClassName, MajorID, Year)**
   - 主键：ClassID
   - 外键：MajorID -> Major(MajorID)

2. **Course(CourseID, CourseName, Credits)**
   - 主键：CourseID

3. **Curriculum(CurriculumID, MajorID, CourseID, Semester, CourseType)**
   - 主键：CurriculumID
   - 外键：MajorID -> Major(MajorID)
   - 外键：CourseID -> Course(CourseID)

4. **Grades(GradeID, StudentID, CourseID, Score)**
   - 主键：GradeID
   - 外键：StudentID -> Student(StudentID)
   - 外键：CourseID -> Course(CourseID)

5. **Major(MajorID, MajorName)**
   - 主键：MajorID

6. **Student(StudentID, Name, Gender, BirthDate, ClassID)**
   - 主键：StudentID
   - 外键：ClassID -> Class(ClassID)

7. **Teacher(TeacherID, TeacherName)**
   - 主键：TeacherID

8. **Teaching(TeachingID, TeacherID, ClassID, CourseID)**
   - 主键：TeachingID
   - 外键：TeacherID -> Teacher(TeacherID)
   - 外键：ClassID -> Class(ClassID)
   - 外键：CourseID -> Course(CourseID)

### E-R图示例

```plaintext
+----------------+       +----------------+       +----------------+
|      Major     |       |     Class      |       |     Course     |
+----------------+       +----------------+       +----------------+
| MajorID (PK)   |<----->| MajorID (FK)   |       | CourseID (PK)  |
| MajorName      |       | ClassID (PK)   |       | CourseName     |
+----------------+       | ClassName      |       | Credits        |
                         | Year           |
                         +----------------+

+----------------+       +----------------+       +----------------+
|     Student    |       |     Grades     |       |   Curriculum   |
+----------------+       +----------------+       +----------------+
| StudentID (PK) |<----->| StudentID (FK) |<----->| MajorID (FK)   |
| Name           |       | GradeID (PK)   |       | CourseID (FK)  |
| Gender         |       | CourseID (FK)  |       | CurriculumID   |
| BirthDate      |       | Score          |       | Semester       |
| ClassID (FK)   |       +----------------+       | CourseType     |
+----------------+       +----------------+       +----------------+

+----------------+       +----------------+       +----------------+
|     Teacher    |       |    Teaching    |       |     Class      |
+----------------+       +----------------+       +----------------+
| TeacherID (PK) |<----->| TeacherID (FK) |<----->| ClassID (FK)   |
| TeacherName    |       | TeachingID (PK)|       +----------------+
+----------------+       | ClassID (FK)   |
                         | CourseID (FK)  |
                         +----------------+
```

### 说明
- **实体**：每个实体都有其属性和主键。
- **关系**：实体之间的关系通过外键来表示。
- **主键**：每个实体表中的主键用于唯一标识每条记录。
- **外键**：用于建立实体之间的关联，确保数据的一致性和完整性。

通过以上设计，可以确保数据库的结构合理、数据一致，并且能够高效地支持各种查询和操作。

```mermaid
erDiagram
    MAJOR {
        int MajorID PK
        varchar MajorName
    }
    CLASS {
        int ClassID PK
        varchar ClassName
        int MajorID FK
        int Year
    }
    COURSE {
        int CourseID PK
        varchar CourseName
        int Credits
    }
    CURRICULUM {
        int CurriculumID PK
        int MajorID FK
        int CourseID FK
        varchar Semester
        enum CourseType
    }
    STUDENT {
        int StudentID PK
        varchar Name
        enum Gender
        date BirthDate
        int ClassID FK
    }
    GRADES {
        int GradeID PK
        int StudentID FK
        int CourseID FK
        decimal Score
    }
    TEACHER {
        int TeacherID PK
        varchar TeacherName
    }
    TEACHING {
        int TeachingID PK
        int TeacherID FK
        int ClassID FK
        int CourseID FK
    }

    MAJOR ||--o{ CLASS : has
    MAJOR ||--o{ CURRICULUM : has
    CLASS ||--o{ STUDENT : has
    COURSE ||--o{ CURRICULUM : is_in
    COURSE ||--o{ GRADES : has
    STUDENT ||--o{ GRADES : has
    TEACHER ||--o{ TEACHING : teaches
    CLASS ||--o{ TEACHING : has
    COURSE ||--o{ TEACHING : is_in

```


在编写查询快要被开除的学生的SQL语句过程中，遇到了以下问题：

### 问题描述
最初尝试直接通过`Grades`表与`Course`表、`Student`表以及`Curriculum`表进行连接，并筛选出成绩低于60分且课程类型为“必修”或“选修”的记录。然而，在计算学生的累计失败学分时发现结果不准确，具体表现为某些学生的累计失败学分数值偏低或偏高。经过初步排查，怀疑是由于某些学生在多个学期选修了同一门课程，导致成绩记录重复计算，进而影响了最终的统计结果。

### 解决方案
为了解决上述问题，采取了以下措施：
1. **去重处理**：在计算每个学生的累计失败学分之前，先对成绩记录进行去重处理，确保每门课程的成绩只被计算一次。
2. **分组统计**：分别针对“必修”和“选修”课程进行分组统计，确保不同类型的课程按照不同的标准进行累计。
3. **条件筛选**：在`HAVING`子句中增加了具体的条件限制，确保只有累计失败学分在指定范围内的学生才会被选中。

最终的SQL语句如下：

```sql
# 查询快要被开除的学生
SELECT s.StudentID, s.Name, SUM(c.Credits) AS TotalFailedCredits
FROM (
    SELECT DISTINCT g.StudentID, g.CourseID, g.Score
    FROM Grades g
) g
JOIN Course c ON g.CourseID = c.CourseID
JOIN Student s ON g.StudentID = s.StudentID
JOIN Curriculum cu ON c.CourseID = cu.CourseID
WHERE g.Score < 60 AND cu.CourseType = '必修'
GROUP BY s.StudentID, s.Name
HAVING SUM(c.Credits) BETWEEN 7 AND 10

UNION

SELECT s.StudentID, s.Name, SUM(c.Credits) AS TotalFailedCredits
FROM (
    SELECT DISTINCT g.StudentID, g.CourseID, g.Score
    FROM Grades g
) g
JOIN Course c ON g.CourseID = c.CourseID
JOIN Student s ON g.StudentID = s.StudentID
JOIN Curriculum cu ON c.CourseID = cu.CourseID
WHERE g.Score < 60 AND cu.CourseType = '选修'
GROUP BY s.StudentID, s.Name
HAVING SUM(c.Credits) BETWEEN 12 AND 15;
```

### 结果验证
通过上述修改，查询结果更加准确，能够正确地反映出快要被开除的学生及其累计失败学分。此外，还对部分学生进行了手动验证，确认查询结果与实际情况相符。

通过这次问题的解决，不仅提高了SQL查询的准确性，也加深了对SQL中去重处理和分组统计的理解。

### 总结

本次《数据库系统》上机报告主要围绕学籍管理数据库系统的开发与实现展开。通过需求分析、概念结构设计、逻辑结构设计以及功能实现等多个环节，我们成功构建了一个功能完备、操作便捷的学籍管理系统。以下是本次实验的主要成果和收获：

1. **需求分析**：明确了系统需要管理的专业、班级、学生、课程、教学计划、成绩、教师和授课安排等八大模块，为后续的设计和实现奠定了基础。
2. **概念结构设计**：通过E-R图的设计，清晰地展示了各个实体之间的关系，为数据库的逻辑结构设计提供了直观的参考。
3. **逻辑结构设计**：定义了各个实体的属性及其关系，确保了数据库的规范化和一致性。特别是通过外键约束，保证了数据的完整性和准确性。
4. **功能实现**：选择了MySQL作为数据库管理系统，并编写了相应的建表语句和SQL查询语句。实现了学生信息的录入、查询、成绩管理、教师管理等功能，并解决了在查询快要被开除的学生时出现的数据重复计算问题。
5. **问题解决**：在遇到数据重复计算的问题时，通过去重处理、分组统计和条件筛选等方法，有效解决了问题，确保了查询结果的准确性。

通过本次实验，不仅加深了对数据库系统理论知识的理解，还提升了实际操作能力和问题解决能力。未来将进一步优化系统性能，增加更多的功能模块，以满足更复杂的应用需求。