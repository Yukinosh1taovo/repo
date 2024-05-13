## MySql

cmd连接本地数据库`mysql -u root -p`

### DDL(Data Definition Language 数据定义语言)

```sql
SHOW DATABASES; # 查询所有数据库
SELECT DATABASE(); # 查询当前数据库
CREATE DATABASE [IF NOT EXISTS] 数据库名 [DEFAULT CHARSET 字符集] [COLLATE 排序规则]; # 创建数据库
DROP DATABASE [IF EXISTS] 数据库名 # 删除数据库
USE 数据库名 # 使用数据库
```

```sql
SHOW TABLES; # 查询当前数据库所有表
DESC 表名 # 查询表结构
SHOW CREATE TABLE 表名 # 查询指定表的建表语句
```

```sql
CREATE TABLE 表名(  # 创建表
    字段1 字段1类型 [COMMENT 注释1],
    字段2 字段2类型 [COMMENT 注释2],
    字段3 字段3类型 [COMMENT 注释3] # 注意最后一个没有逗号
	)[COMMENT 表注释] ;
```

```sql
ALTER TABLE 表名 ADD 字段名 类型(长度) [COMMENT 注释] [约束]; # 添加字段
ALTER TABLE 表名 MODIFY 字段名 新数据类型(长度) # 修改数据类型
ALTER TABLE 表名 CHANGE 旧字段名 新字段名 类型(长度) [COMMENT 注释] [约束]; # 修改字段名和数据类型
ALTER TABLE 表名 DROP 字段名; # 删除字段
ALTER TABLE 表名 RENAME TO 新表名 # 修改表名
```

```SQL
DROP TABLE [IF EXISTS] 表名; # 删除表
TRUNCATE TABLE 表名; # 删除指定表 并重新创建该表 (清空)

```







### 数据类型

![](D:\Files\repo\typora\Screenshot_2024-05-08-16-50-01-491_tv.danmaku.bil.png)

![](D:\Files\repo\typora\Screenshot_2024-05-08-16-50-17-009_tv.danmaku.bil.png)

![](D:\Files\repo\typora\Screenshot_2024-05-08-16-56-05-442_tv.danmaku.bil.png)



### DML(Data Manipulation Language 数据操作语言)

```sql
INSERT INTO 表名 (字段名1, 字段名2, ...) VALUES(值1, 值2, ...); # 给指定字段添加数据
INSERT INTO 表名 VALUES(值1, 值2, ...); # 给全部字段添加数据
# 批量添加数据
INSERT INTO 表名 (字段1, 字段2, ...) VALUES(值1, 值2, ...), (值1, 值2, ...), (值1, 值2, ...);
INSERT INTO 表名 VALUES (值1, 值2, ...), (值1, 值2, ...), (值1, 值2, ...);
```

```sql
UPDATE 表名 SET 字段名1 = 值1, 字段名2 = 值2, ...[WHERE 条件]; # 修改数据 
```

```SQL
DELETE FROM 表名 [WHERE 条件]; # 删除数据 如果没有条件会删除整张表的所有数据
```

### DQL(Data Query Language 数据查询语言)

```SQL
SELECT 
	字段列表
FROM
	表名列表
WHERE
	条件列表 
GROUP BY
	分组字段列表
HAVING
	分组后条件列表
ORDER BY
	排序字段列表
LIMIT
	分页参数
```

1. 基本查询

```sql
SELECT 字段1, 字段2, 字段3 ... FROM 表名;
SELECT * FROM 表名;  # 查询多个字段

SELECT 字段1[AS 别名1], 字段2[AS 别名2] ... 表名; # 设置别名

SELECT DISTINCT 字段列表 FROM 表名; # 去除重复记录
```

2. 条件查询

```SQL
SELECT 字段列表 FROM 表名 WHERE 条件列表;
```

<img src="D:\Files\repo\typora\Snipaste_2024-05-12_11-37-29.png" style="zoom:100%;" />

3. 聚合函数

```SQL
SELECT 聚合函数(字段列表) FROM 表名;
SELECT sum(age) FROM emp WHERE ID IS NOT NULL; # 例
```

![](D:\Files\repo\typora\Snipaste_2024-05-12_11-57-36.png)

4. 分组查询

```sql
SELECT 字段列表 FROM 表名 [WHERE 条件] GROUP BY 分组字段名 [HAVING 分组后过滤条件];
SELECT gender, count(*) FROM emp GROUP BY gender; # 例 统计男性员工和女性员工的数量 
SELECT workaddress, count(*) FROM emp WHERE age < 45 GROUP BY workaddress HAVING count(*) >= 3;
	# 例 查询年龄小于45岁的员工,并根据工作地址分组,获取员工数量大于等于3的工作地址
```

![](D:\Files\repo\typora\Snipaste_2024-05-12_12-08-59.png)
