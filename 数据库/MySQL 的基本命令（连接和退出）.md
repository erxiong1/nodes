# 基本SQL语句(一篇就够了)

> SQL(Structured Query Language)结构化查询语言，用于存取，查询，更新数据以及管理关系型数据库系统
>
> SQL是1981年由IBM公司推出

## SQL分类

> 根据SQL指令完成的数据库操作的不同，可以将SQL指令分为四类
>
> + DDL Data Defintion language 数据库定义语言 
>   + 用于完成对数据库对象(数据表,数据库,视图,索引)的创建，删除，修改
> + DML Data Manipulation language 数据操作语言
>   + 用于完成对数据表中的数据添加，删除，修改
> + DQL Data Query language 数据查询语言
>   + 用于将数据表中的数据查询出来
> + DCL Data Control Laguage 数据控制语言
>   + 用于完成事务管理等控制型操作



SQL 基本语法

> SQL指令不区分大小写
>
> 每条SQL表达式结束之后都以;结束
>
> SQL关键字之间都以 **空格**进行分割
>
> SQL之间可以不限制换行(可以有空格的地方就可以有换行)

## DDL

### DDL-数据库操作

> 使用DDL语句可以创建数据库，删除数据库，修改数据库

查询数据库

> ##显示mysql中所有是数据库
>
> show databases;  
>
> ##显示指定数据库的创建的SQL指令
>
> show create database <dbName>;

创建数据库

> ##在mysql中创建一个数据库 dbName表示数据库名称
>
> create database <dbName>;
>
> ##创建数据库，指定名称不存在的时候创建
>
> create database if not exists <dbName>;
>
> ##在创建数据库的同时指定数据库的字符集(字符集：数据存储在数据库)
>
> create database <dpName> character set 字符集;

修改数据库

> ##修改数据库的字符集
>
> alter database <dbName> character set 字符集;

删除数据库 

> 删除数据库时会删除数据库中所有的表以及数据库中的所有的数据
>
> ##删除数据库
>
> drop database <dbName>;
>
> ##如果数据库存在则删除数据库
>
> drop database if exists <dbName>;

**使用/切换数据库**

> use <dbName>;

### DDL-数据表的操作

创建数据表

> 数据表实际上就是一个二维的表格，一个表格是由多列组成的表格![2021-11-21 01-51-51 的屏幕截图](/home/ddj/图片/2021-11-21 01-51-51 的屏幕截图.png)

查询数据表

> show tables;

查询表结构

> desc <tableName>;

删除数据表

> ##删除数据表
>
> drop  table <tableName>;
>
> ##删除数据表如果表存在　
>
> drop table if exists <tableName>;

修改数据表

> ##修改表名
>
> alter table <tableName> rename to <newTableName>;
>
> ##数据表也是有字符集的,默认字符集和数据库一致
>
> alter table <tableName> character set 字符集;
>
> ##添加字段(列)
>
> alter table <tableName> add <columnName> <type>;
>
> ##修改的列表名和类型 
>
> alter table <tableName> change <oldColunmName> <newColnumnName> <type>;
>
> ##只修改字段类型
>
> alter table <tableName> modify <ColumnName><newType>; 
>
> ##删除字段(列)
>
> alter table <tableName> drop <columnName>;

## MySQL数据类型

### 数值类型

在MySQL中有多种数据类型可以有存放数值，不同类型存放的数值范围或者形式不同的

| 类型        | 大小(Bytes)                      | 范围                                                         |
| ----------- | -------------------------------- | ------------------------------------------------------------ |
| tinyint     | １                               | 有符号 (-128，127)无符号 (0，255)                            |
| smallint    | ２                               | 有符号 (-32 768，32 767)无符号 (0，65 535)                   |
| mediumint   | ３                               | 有符号 (-8 388 608，8 388 607)无符号 (0，16 777 215)         |
| int/integer | ４                               | 有符号(-2^31,2^31- 1)无符号(0,2^32 - 1)                      |
| bigint      | ８                               | 有符号(-2^63,2^63- 1)无符号(0,2^64 - 1)                      |
| float       | ４                               | (-3.402 823 466 E+38，-1.175 494 351 E-38)，0，(1.175 494 351 E-38，3.402 823 466 351 E+38)有符号0，(1.175 494 351 E-38，3.402 823 466 E+38) |
| double      | ８                               | (-1.797 693 134 862 315 7 E+308，-2.225 073 858 507 201 4 E-308)，0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308)有符号<br />0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308) |
| decimal     | DECIMAL(M<D)为<br />max(M+2,D+2) | 依赖于M和D的值　　decimal(m,n)表示数值一共有10位小数有2位    |





### 字符类型

> 存储字符序列的类型

| 类型         | 字符序列的长度范围 | 说明                                                         |
| ------------ | ------------------ | ------------------------------------------------------------ |
| **char**     | 0~255字节          | 定长字符串,最多可以存储255个字节；当我们指定数据表字段char(n)<br />此列中的数据最多长为n个字符，如果添加的字符串少于n则补'\u0000'至长n长度 |
| **varchar**  | 0~655535字节       | 可变长度字符串,此类型的类最大长度65535                       |
| tinyblob     | 0~255字节          | 存储二进制字符串                                             |
| blob         | 0~65535字节        | 存储二进制字符串                                             |
| mediumblob   | 0~1677215          | 存储二进制字符串                                             |
| longblob     | 0~2^64 -1字节      | 存储二进制字符串                                             |
| tinytext     | 0~255字节          | 文本数据(字符串)                                             |
| text         | 0~65535字节        | 文本数据(字符串)                                             |
| mediumtext   | 0~2^24 -1字节      | 文本数据(字符串)                                             |
| **longtext** | 0~2^64 -1字节      | 文本数据(字符串)                                             |

### 日期类型

> 在MySQL数据库中,我们可以用字符串来存储时间,但是我们需要基于时间字段进行查询操作(查询在某个时间段内的数据)就不便于查询实现

| 类型         | 格式                | 说明                        |
| ------------ | ------------------- | --------------------------- |
| date         | 2021-09-13          | 日期,只存储年月日           |
| time         | 11:20:31            | 时间,只存储时分秒           |
| year         | 2021                | 年份                        |
| **datetime** | 2021-09-13 11:20:31 | 日期加时间,存储年月日时分秒 |
| timestamp    | 20210913 112031     | 日期+时间(时间戳)           |





## 字段约束

> 在创建数据表的时候,指定的对数据的列的数据限制性的要求(对表的列中的数据进行限制)
>
> 为什么给表中的数据添加数据呢?
>
> + 保证数据的有效性
> + 保证数据的完整性
> + 保证数据的正确性
>
> 字段常见的约束有那些呢？
>
> + 非空约束(not null):限制此列的值必须提供,不能null
> + 唯一约束(unique):在表中的多条数据,此列的值不能重复
> + 主键约束(primary key):非空+唯一,能够唯一标示数据表中的一条数据.
> + 外键约束(foreign key):建立不同表之间的关联关系.

### 主键约束

> 主键--就是数据表中的记录中的唯一标识，在一张表中只能有一个主键(主键可以是一个字段,也可以是多个列组合)
>
> 当一个字段声明为主键之后，添加数据时;
>
> + 此字段数据不能为null;
> + 此字段数据不能重复;
>
> #### 创建表时添加主键约束
>
> ```sql
> create table books(
>     book_isbn char(4),
>     book_name varchar(20) primary key
> );
> ```
>
> ### 或者
>
> ````sql
> create table books(
>     book_isbn char(4);
>     book_name varchar(20),
>     primary key(book_name)
> );
> ````
>
> ### 删除数据表主键约束
>
> ````sql
> alter table books drop primary key;
> ````
>
> ### 创建表之后添加主键约束
>
>  ````sql
>  ## 创建表时没有添加主键约束
>  create table books(
>      book_isbn char(4),
>      book_name varchar(10) 
>  );
>  
>  ## 创建表之后添加主键约束
>  alter table books modify book_isbn char(4) primary key;
>  ````
>
> ### 主键自动增长
>
> > 在我们创建一张数据表时，如果数据表中有可以作为主键(列如:学生表的学号,图书表的isbn)我们可以直接设为这个字段为主键,
> >
> > 当有些数据没有合适的字段作为主键的时候，我们可以定义一个与记录无关的列(ID)作为主键
> >
> > ,此数据无具体含义主要作为标识唯一,在mysql中我们可以将此定义为int ，同事设置为**自动增长**
> >
> > 当我们想数据表中新曾一条数据时，无需提供ID列的值，它会自动增长.
>
> #### 定义主键自动增长(只能是数值类型)
>
> **auto_increment**
>
> ````sql
> create table types(
>     type_id double primary key auto_increment,
>     type_name varchar(20) not null,
>     type_reamrk varchar(20)
> );
> ````
>
> **注意**：自动增长从1开始，每次添加一条数据，自动增长的列会+1，但是如果把某条数据删除，自动增长的数据也不会重复生产(自动增长的数据不会保证连续)
>
> ### 联合主键
>
> 　![2021-11-21 15-18-40 的屏幕截图](/home/ddj/图片/2021-11-21 15-18-40 的屏幕截图.png)
>
> #### 定义联合主键
>
> ```sql
> create table grades(
>     stu_num char(8),
>     course_id int,
>     score int,
>     primary key(stu_num,course_id)
>     
> );
> ```
>
> **注意**:在实际企业项目的数据库设计中，联合主键使用频率不高，当一个数据表中没有明确的字段可以作为主键时，我们可以额外添加一个ID字段作为主键

### 外键约束

pass



## DDL数据操作语言

> 用于完成对数据表中的数据中插入，删除，修改

### 插入数据

```sql
insert into <tableName>(colmnName,...)values(value1,....);
```

#### 示例

````sql
## 向数据表中指定的列添加数据(不允许为空的必须提供数据)
insert into stus(stu_num,stu_name,sut_gender)values('202012321','张三','男',21,'130313131');
## 数据表名后字段名列表顺序可以与表名不一致，但是values中的值的顺序必须与表明后字段名顺序对应
## 当要向表中的数据所有列添加数据的时候，表名后面的字段列表可以省略，但是values中的值顺序要于数据表中定义的字段保持一致
## 建议把字段写出了(增强字段的稳定性)
````



### 

###　删除数据

> 从数据表中删除满足特定条件(所有)的数据

```sql
delete from <tableName> where conditions; 
```

#### 示例

````sql
## 删除学号为20210102的记录
delete from stus where stu_num=220210102;
## 删除年龄大于20岁的学生信息(如果多条数据满足情况则删除多条记录)
delete from stus where stu_age>20;
## 如果删除语句没有where子句，则表示删除当前数据表中的所有记录(敏感操作)
delete from stus;
````



### 修改数据

> 对数据表中已经添加的记录进行修改

```sql
update <tableName> set columName=值 [where conditions]
```

示例

````sql
## 将学号为20210105的学生姓名修改为'孙七'
update stus set stu_name='孙七'　where stu_num='20210105';
## 将学号20210103的学生　性别修改为'男'，同事QQ修改为'77777' (修改多列)　
update stus set sut_age='男',stu_qq='77777' where stu_num='20210103';

## 如果update语句没有where子句,则表示修改当前表中的所有行(记录)
update stus set stu_name='Tom'
````

## DQL 数据查询语言

> 从数据表中提取满足特定条件的记录
>
> + 单表查询
> + 多表联合查询

## **单表查询**

#### 查询的基础语法

```sql
## select 关键字查询的是
select colnumName1,.. from <tableName>;
## 如果要显示查询到的的记录的所有列，可以使用*代替字段列表(在项目中不建议使用)
select * from <tableName>;
```

#### where子句

> 在删除，修改及修改的语句后都可以添加where子句(conditions)，用于筛选出满足特定的数据进行，删除，修改和查询操作．

```sql
delete from tableName where conditions;
update <tableName> set ... where contitions;
select ... from <tableName> where contitions;
```

### 条件

````sql
## ＝　等于
select * from stus where sut_num = '20202';
## != <>不等于
select * from stus where sut_num != '20202';
select * from stus where sut_num <> '20202';
## >大于
select * from stus where sut_age>18;
## <小于
select * from stus where sut_age<18;
## >=大于等于
select * from stus where sut_age>=18;
## <=小于等于
select * from stus where stu_age<=18;
## between and 区间查询
select * from stus where stu_age between 18 and 20;
````

### 多条件查询

> 在where子句中，可以将多个条件通过逻辑预算(and or not)进行连接,通过多个条件来筛选需要的操作

````sql
## and 并且　筛选多个条件同时满足的记录
select * from stus where stu_gender='女' and stu_age<21;
## or　或者
select * from stus where stu_gender='女'　or stu_gender='中间';
## not 取反
select * from stus where stu_age not between 18 and 21;
````

### like 子句

> 在where子句中可以使用**like**关键字来实现模糊查询

````sql
select * from tableName where columName like 'reg';
````

+ 在like关键字后的reg表达式中
  + %表示任意多字符［%o%表示含有o］
  + _表示任意一个字符

````sql
## 查询学生姓名包含字符o的学生信息
select * from stus where stu_name like '%o%';
## 查询学生姓名第一个字为张的学生信息
select * from stus where stu_name like '张%';
## 查询学生姓名最后一个字母为o的学生信息
select * from stus where stu_name like '%o';
##　查询学生姓名中第二个字母为o的学生信息
select * from stus where stu_name like '_o％';
````

#### 对查询结果的处理

**设置查询的列**

> 声明显示查询结果的指定列

```sql
select colnumName,... from stus where stu_age>20;
```

#### 计算列

> 对从数据表中查询的记录的列进行一定的运算之后显示出来.

````sql
## 出生年份　＝现在的年份-年龄
select stu_name,2021-stu_age from stus;
````

### 字段别名

> 我们可以为查询的结果的字段　取一个语义更强的别名

**as 字段别名**

````sql
##给2021-stu_age取一个别名(as　可以省略)
select stu_name,2021-stu_age as 出生　from stus;
````

### 消除重复行

**distinct**

> 从查询的结果中将重复的记录消除　

```sql
select distinct stu_age from stus;
```

## order by排序

> 将查询到的满足条件的记录按照指定的列的值升序/降序排列

````sql
select * from <tableName> where conditions by order by columnName asc|desc;
````

+ order by columnName 表示将查询结果按照指定的列排序
  + asc 按照指定的列升序排序
  + desc 按照指定的列降序排序和查看表结构是同一个缩写(纯属巧合)

### 示例

```sql
##单字段排序
select * from stu order by sex desc;
##多字段排序  首先性别降序　然后id升序
select * from stu order by sex, id asc,
```

## 聚合函数

> sql中提供了一些可以对查询记录进行列计算的的函数--聚合函数

+ count() 统计函数,统计满足条件的指定字段的个数(记录数)

  + ```sql
    ## 统计学生个数
    select (id) from stu;
    ## 统计女生个数
    select count(sex) from stu WHERE sex='男';
    ```

+ max()记录指定列中的最大值

+ min()记录中指定列的最小值

+ sum()记录中指定列的和

+ avg()记录中指定记录的平均值

### 日期函数 和　字符串函数

#### 日期函数

> 当我们向日期类型的列添加数据时,可以通过字符串类型(字符串格式必须是　yyyy-MM-dd hh:mm:ss)
>
> 如果我们要获取当前系统的时间添加到日期类型的列　可以使用**now()**或者**sysdate()**
>
> curtime();	返回当前时间
> curdate();　返回当前日期

##### 字符串函数

````sql
## upper(colynm)将字段的值转换成大写
select upper(name) from stu;
## lower(column)将指定列的值转换成小写
select upper(name) from stu;
## substring(column,start,len)从指定列中截取部分显示　start从1开始
select id,substring(name,4,8);
````

## 分组查询

````sql
select 分组字段/聚合函数　from 表名　[where 条件] group by 分组字段名;
````

+ select 后使用*显示对查询的结果进行分组之后，显示每一组的第一条记录(这种显示通常是无意义的)
+ select 后通常显示分组字段和聚合函数(对分组后的数据进行统计,求和,平均值等)

```sql
# 先对查询的学生信息按性别进行分组(分成男,女),然后分别统计每组学生的个数
select sex,count(sex)from stu group by sex;
# 先对查询的学生信息按性别进行分组　然后计算
select sex,avg(scroe) from stu group by sex;
# 先对学生按照班级分组　然后统计各组的学生数量，在排序
select age,count(stu) from stu group by age order by age asc;
# 查询所有学生,按年龄进行分组,然后分别统计每组>1的人数,再筛选年龄升序 (having　隐藏记录　有group by 才能有　having)
select age,count(num)
from stu
group by age
having count(num)>1
order by age asc;
```

## 分页查询

> 当数据表中的记录比较多的时候,如果一次性全部查询出来的显示给用户,用户的可读性/体验性就不太好,因为此我们可以将这些数据分页进行展示.

```sql
select ... from ... where ... limit param1,param2;
```

+ param1 int 获取查询语句的结果的第一条数据的索引(索引从0开始)
+ param2 int 获取查询语句的结果的条数(如果剩下的数据条数<pram2,则返回剩下的记录)

#### 案例

对数据表中的学生信息进行分页显示,总共59条数据,我们每页显示20条

> 总记录数: count 59
>
> 每页显示 page 20
>
> 总页数 pageCount = cpimt%page ?count/page:count/page +1;



````sql
# 查询第一页:
select * from stu limit 0,20;
# 查询第二页
select * from stu limit 20,20;
# 查询第三页
select * from stu limit 40,20;
# 如果一张表中,pageNum表示查询的页码,pageSize表示查询每页的条数:
select * from stu limit (pageNum-1)*pageSize,pageSize;
````

## 数据表的关联关系



> MySQL是一个关系型数据库,不仅可以存储数据,还可以维护数据与数据之间的关系--通过数据表中的数据字段的外键约束

#### 数据与数据之间的关系分析分为四种

> + 一对一关联
> + 一对多关联
> + 多对一关联
> + 多对多关联

### 一对一关联

> 人--身份证
>
> 学生--学籍
>
> 用户--用户详情

方案一:主键关联--两张数据表中的主键相同的数据互相对应的数据

方案二:唯一外键--在任意一张表中添加外键约束与另一张表主键关联,并且将外键列添加唯一约束

### 一对多与多对一

> 班级---学生(一对多)一个班级可以包含多个学生
>
> 学生--班级(多对一) 多个学生可以属于同一个班级
>
> 图书--分类 商品--商品类别

### 多对多关联

> 学生--课程 一个学生可以选择多门课,一门课也可以由多个学生选择
>
> 会员--社团 一个会员





## 外键约束

> 外键约束--将一个列添加外键约束与另一张表的主键(唯一列)进行关联之后,这个外键约束添加的数据必须要在关联的主键字段中存在

案例:学生表 与 班级表(在学生表中添加外键与班级表的主键进行关联)

1. 先创建班级表

   ```sql
   create table classes(
   	class_id int primary key auto_increment,
   	class_name varchar(40) not null unique,
   	class_remark varchar(200)
   );
   ```

2. 创建学生表(在学生表中添加外键与班级表主键进关联)

```sql
# 在创建表的时候,定义cid 字段,并添加外键约束
# 由于cid列 要与classes表class_id进行关联,因此cid字段类型长度要与class_id一致
create table students(
 	stu_num char(8) primary key,
 	stu_name varchar(30) not null unique,
 	stu_gender char(2) not null,
 	stu_age int not null,
 	cid int,
 	constraint FK_STUDENTS_CLASSES foreign key(cid) references classes(class_id)
);
# 创建表之后为cid 添加外键约束
alter table students add constraint FK_STUENTS_CLASSES foreign key(cid) classes(class_id);
```

3. 向班级表添加班级信息

   ```sql
   insert into classes(class_name,class_remark) values('Python','...'),('mysql','...'),('JAVA','...');
   ```

4. 向学生表中添加学生信息

   ```sql
   insert into students (stu_num,stu_name,stu_gender,stu_age,cid)values('11111','杜东京','男',18,2);
   # 添加学生时,设置给cid外键列的值必须在其关联的主表classes的class_id列存在
   ```

   > **当学生表中存在的学生信息关联班级的某条记录时,就不能对班级表的这条记录进行修改ID和删除操作**

```sql
delete from classes where class_id=2;
update classes set class_id=8 where class_id=2;
#SQL 错误 [1451] [23000]: Cannot delete or update a parent row: a foreign key constraint fails (`dp_test2`.`students`, CONSTRAINT `FK_STUDENTS_CLASSES` FOREIGN KEY (`cid`) REFERENCES `classes` (`class_id`))
```

## 修改和删除被关联表的记录或者ID


> 如果一定要修改Java2104的班级ID,该如何实现?
>
> + 将应用Python班级的id的学生记录的cid修改为null
> + 在修改班级信息中的Python记录的class_id
> + 讲学生表中cid为NULL的记录设重新修改为 Python这个班级的class_id

```sql
UPDATE students set cid=null where cid=2;
UPDATE classes  set class_id=4 where class_id =2;
UPDATE students set cid = 4 where cid  is null;
```

 ## 我们可以通通过级联操作实现:(on xxx cascade)

1. 在添加外键时,设置**级联修改**和**级联删除**

```sql
# 删除原有的外键
alter table sutdents drop foreign key FK_STUDENTS_CLASSES;
# 重新添加外键,并设置级联修改和级联删除
alter table students add constraint FK_STUDENTS_CLASSES foreign key(cid) references classes(class_id) on update cascade on delete cascade;
```

+ 当添加on delete cascade声明后 删除班级某记录之后 学生表外键绑定此记录的都会被删除
+ 当添加on update cascade声明后 修改班级记录的主键 学生表与之关联的外键都会跟着改变

## 连接查询

> 通过DQL的学习,我们可以很轻松的从一张数据表中查询出需要的数据:在企业的应用开发,我们经常需要从多张表中查询数据(列如:我们查询学生信息的时候),可以通过连接查询从多张数据表提取数据:
>
> 在MySQL中可以使用join实现多表的联合查询--链接查询,
>
> + inner join 内连接
> + left join 左连接
> + right join 右连接

## 内连接

```sql
select ... from tableName inner join tableName2;
```

### 笛卡尔积

> + 笛卡尔积(A集合&B集合):使用A中的每个记录依次关联B中每个记录,笛卡尔集的总数=A总数*B总数
> + 如果直接执行select ... from tableNmae1 inner join tableName2; 会获取两张数据表中的数据集合的笛卡尔积(依次使用tableName1表中的每条数据 去 匹配tableName2的每条数据)

### 内连接条件

> 两张表同时用inner join连接查询之后产生笛卡尔积数据很多是无意义的,我们如何消除无意义的数据----添加两张进行连接的查询时的条件

+ 使用on设置两张表连接查询的匹配条件

  ````sql
  -- 使用where设置过滤条件:先生成笛卡尔积再从笛卡尔积中过滤数据(效率很低)
  select * from students inner join classes where students.cid=classes.class_id;
  -- 使用ON设置连接查询条件:先判断连接条件是否成立,如果成立两张表的数据进行组合在生成一条结果记录
  select * from students inner join classes on students.cid=classes.class_id;
  ````

  > 结果:只取两种表中匹配条件成立的数据,任何一张表在另一张表如果没有找到对应匹配则不会出现在查询结果中(例如:小红和小明没有对应的班级信息 python课没有被人选)
  
  ## 左连接 LEFT JOIN
  
  > 需求:查询出所有的学生信息,如果学生有对应的班级信息,则将对应的班级信息也查询出来.
  
  左连接:显示左表中的所有数据,如果在右表中满足条件的数据,则进行匹配;如果右表中不存在匹配数据,则显示为null
  
  ```sql
  select * from leftTable join rightTable on 匹配条件;
  ```
  
  ## 右连接 RIGHT JOIN
  
  > 右连接:示右表中的所有数据,如果在右表中满足条件的数据,则进行匹配;如果左表表中不存在匹配数据,则显示为null

### 数据表别名

> 如果连接查询的多张表中存在相同名字的字段,我们可以使用**表名.字段名**来分区,如果表名太长则不便于SQL语句的编写,我们可以使用数据表别名

````sql
select s.*,c.class_name from students s inner join classes c  on s.cid=c.class_id;
````

## 子查询/嵌套查询

> 子查询--先进行一次查询,第一次查询的结果作为第二次查询的/条件(源)  (第二次查询是基于第一次查询的结果进行的)

#### **案例**:查询班级班级名为(mysql)的学生信息(只知道班级名称,而不知道班级ID)

+ 传统方式

````sql
-- a.查询mysql的班级的编号
select class_id from classes where class_name='mysql';
-- b.查询此班级编号的学生信息
select * from students where cid=2
````

子查询单行单列

+ 子查询:

````sql
select * from students where cid=(select class_id from classes where class_name='mysql');
````

#### 案例2:查询所有Java班级中的学生信息

+ 传统方式

```sql
-- a查询所有Java班的班级编号
select class_id from classes where class_name like 'Java%';
-- b查询这些班级编号中的学生信息(union 将多个查询语句的结果整合到一起)
select * from students where cid = 1
union
select * from students where cid = 2
union
select * from students where cid = 3
```

子查询多行单列

+ 子查询

```sql
-- 如果查询返回的结果是多个值(单列多行),条件使用**in / not in**
select * from students where cid in (select class_id from classes where class_name like 'mysql%');
```

子查询返回多个值,多行多列

#### 案例3:查询cid=1的班级中性别为男的学生信息

```sql
-- 传统的多条件查询
select * from students where cid=1 and stu_gender='男';
-- 子查询(先查询cid=1班级中的所有信息,将这些信息作为一个整体虚拟表 在基于这个虚拟表查询性别为男的学生信息)
select * from (select * from students where cid=1) t where t.stu_gender='男';
```

# 存储过程

## 存储过程介绍

#### SQL指令执行过程

![2021-11-27 00-21-24 的屏幕截图](/home/ddj/图片/2021-11-27 00-21-24 的屏幕截图.png)

从SQL执行的流程中我们分析存在的问题

1. 如果我们需要重复多次执行相同的SQL,SQL执行需要通过连接传递到MySQL,并且经过编译和执行的步骤
2. 如果我们需要连续执行多个SQL指令,并且第二个SQL指令需要使用第一个SQL指令执行的结果为参数;

### 存储过程的优缺点分析

### 存储过程优点:

> 1. SQL指令无需客户端编写,通过	网络传送,可以节省网络开销,同事避免SQL指令在网络传输过程中被恶意篡改保证安全性;
> 2. 存储过程经过编译创建并保存在数据库中,执行过程无需重复的进行编译操作,对SQL指令的执行过程进行了性能提升;
> 3. 存储过程中多个SQL指令之间存在逻辑关系,支持流程控制语句(分支,循环),可以实现更为复杂的的业务;

### 存储过程的缺点

> 1. 存储过程是根据不同的数据库进行编译.创建并存储在数据库中;当我们需要切换到其他的数据库产品时,需要重写针对于新数据库的存储过程
> 2. 存储过程受限于数据库产品,如果需要提高性能的优化会成为一个问题
> 3. 在互联网项目中,如果需要数据库的高(连接)并发访问,使用存储过程会增加数据库的连接执行时间(因为我们将复杂的业务交给了数据库进行处理)

## 创建存储过程

```sql

create procedure <procedure_name>([IN/OUT args])
begin
	-- SQL
end;
-- 示例
create procedure prod_test(in a int,in b int,out c int)
begin
	set c = a+b;
end;
```

## 调用存储过程

```sql
create procedure proc_test1(in a int,in b int,out c int)
begin
	set c = a+b;
end;
-- 调用存储过程
set @m;
call proc_test1(3,200,@m);
-- 显示变量表
select @m from dual; -- dual表是数据库自带的用来存储标量的表
```

### 存储过程中变量的使用

> 存储过程中的变量分为2种,局部变量 和 用户变量

#### 局部变量

> 局部变量:定义在存储过程中的变量,只能存储过程内部使用

+ 局部变量定义语法

```sql
-- 局部变量要定义在存储过程中,而且必须定义存储过程开始
declare <attr_name> <type> [default value];
-- 示例
-- 创建一个存储过程:计算输入参数的平方 与输入参数/2 之和
create procedure proc_test3(in a int,out r int)
begin
		declare x int default 0;
		declare y int default 1;
		set x = a/2;
		set y =a/2;
		set r = x+y;
end;
```

### 用户变量

> 用户变量:相当于全家变量,定义的用户变量可以通过 **select @attrName dual**进行查询
>
> -- 用户变量会存储在mysql数据库的字典中(dual)
>
> -- 用户变量定义使用set关键字直接定义,变量名以@开头
>
> set @n=1;

#### 给变量设置值

+  无论是局部变量还是用户变量,都使用**set关键字修改值**

将存储过程中使用select ... into ..给变量赋值

```sql
create procedure proc_test4(out c int)
begin
	select count(stu_name) into c from students;-- 查询到学生数量赋值给c
end;

CALL proc_test4(@ddj);
SELECT @ddj from dual;
```

#### 用户变量使用的注意事项

> 因为用户变量相当于全局变量,可以使用SQL指令以及多个存储过程中共享,在开发中建议尽量少使用用户变量,用户变量过多会导致程序不易理解,难以维护

## 存储过程的参数

> MySQL存储过程的参数一共三种: IN \ OUT \ INOUT

#### IN 输入参数

> 输入参数 -- 在调用过程中传递数据存储过程的参数(在调用过程必须具有实际值的变量 或者 字面值)

```sql
-- 创建存储过程:添加学生信息
create procedure proc_test8(IN snum char(8) ,IN sname varchar(30) , IN gender varchar(3) ,IN age int , IN cid int)
begin
		insert into students (stu_num, stu_name, stu_gender,stu_age, cid)
		values(snum,sname,gender,age,cid);
end;
call proc_test8('1324518','二宝','女',20,1);
```

### OUT输出参数

> 输出参数 -- 将存储过程中产生的数据返回给过程的调用者,相当于Java方法中的返回值,单不同的是一个存储过程可以有多个输出参数

```sql
-- 创建存储过程 根据学生学号, 查询学生姓名
create procedure proc_test10(IN snum varchar(8),OUT sname varchar(30))
begin
	select stu_name into sname from students where stu_num = snum;
end;
set @name='';
call proc_test10('11111211',@name);
select @name from dual;
```

### INOUT输入输出参数

```sql
create procedure proc_test11(INOUT str varchar(30))
begin
		select stu_name into str from students where stu_num=str;
end;
set @name = '11111211';
call proc_test11(@name);
SELECT @name from dual;
```

### 存储过程中的流程控制

> 在存储过程中支持流程控制语句用于实现显示实现逻辑的控制

#### 分支语句

> + if-then-else
>
> ```sql
> -- 单分支:如果条件成立则执行SQL1,否则执行SQL2
> if conditions then
> -- SQL
> end if;
> -- 案例
> create procedure proc_test13(in a int)
> begin
> 	if a=1 then
> 	insert into classes(class_name,class_remark) values('go','test');
> 	end if;
> end;
> 
> -- 双分支:如果条件成立则执行SQL1,否则执行SQL2
> if conditions then 
> 	-- SQL1
> else 
> 	-- SQL2
> end if;
> -- 案例
> create procedure proc_test14(IN a int)
> begin
> 	if a=1 then
> 		insert into classes(class_name,class_remark) values('go','test');
> 	else 
> 		insert into students (stu_num,stu_name,stu_gender,stu_age,cid) values ('20201234','小熊','男',19,1);
> 	end if;	
> end;
> ```
>
> 
>
> + case
>
> ```sql
> create procedure proc_test15(in a int)
> begin
> 	case a
> 		when 1 then
> 			-- SQL1
> 		when 2 then
> 			-- SQL2
> 		when 3 then
> 			-- SQL3
> 	end case;
> end;
> -- 案例
> create procedure proc_test15(in a int)
> begin
> 	case a
> 		when 1 then
> 			-- SQL1
> 		 	insert into classes(class_name) values('语文');
> 		when 2 then
> 			insert into classes(class_name) values('数学');
> 			-- SQL2
> 		else 
> 			-- SQL(如果变量的值和所有when的值都不匹配,则执行else中的这个SQL)
> 		insert into classes(class_name) values('英语');
> 	end case;
> end;
> call proc_test15(1);
> call proc_test15(2);
> call proc_test15(100);
> ```
>
> 

#### 循环语句

+  while

```sql
create procedure proc_test17(in num int)
begin
	declare i int default 0;
	while i<num do
        -- SQL
        insert into classes (class_name) values (concat('java',i));
        set i=i+1;
	end while;
end;
call proc_test17(10);
```

+ repeat

```sql
create procedure proc_test18(in num int)
begin
	declare i int default 0;
	repeat 
		insert into classes (class_name) values(concat('python',i));
		set i = i+1;
	until  i >= num end repeat;
end;
call proc_test18(5);
```



+ loop

```sql
create procedure proc_test20(in num int)
begin
	declare i int default 1;
	myloop : loop
		-- SQL
		insert into classes(class_name) values(concat('html',i));
		set i = i+1;
		if i>=num then
			leave myloop;
		end if;
	end loop;
end;
call proc_test20(5);
```

### 存储过程管理

#### 查询存储过程

> 存储过程是隶属于某个数据库的,也就是说我们存储过程创建在某个数据库之后,只能在数据库中调用此存储过程
>
> 查询存储过程:查询某个数据库中,有哪些存储过程

```sql
-- 根据数据库名,查询当前数据库的存储过程
show procedure status where db='dp_test2';

-- 查询存储过程的创建细节
show create procedure dp_test2.proc_test1;
 
```

### 修改存储过程

> 修改存储过程是指修改存储过程的特性

```sql
alter procedure <procedureName>特征1 [特征2] [特征3]
```

存储过程的特征参数:

+ CONTAINS SQL  表示子查询包含SQL语句,但不包含读或者写数据的语句
+ NO SQL 表示子程序中不包含SQL语句
+ READS SQL DATA 表示子程序中包含读数据的语句
+ MODIFIES SQL DATA 表示子程序中包含读写数据的语句
+ SQL SECURITY{DEFINER|INVOKER}指明谁有权限来执行
  + DEFINER 表示只有定义自己能够执行
  + INVOKER 表示调用者可以执行
+ COMMENT 'string' 表示注释信息

#### 删除存储过程

```sql
-- 删除存储过程
-- drop 删除数据库的对象 ,数据库 数据表 存储过程 视图 触发器 索引
drop procedure proc_test1;
```

## 存储过程练习案例

> 使用存储过程解决企业项目中开发过程中的问题
>
> 案例:使用存储过程完成借书操作


#### 数据准备

```sql
-- 创建数据库
create database db_test3 character set utf8 ;
use db_test3;
-- 创建图书信息表
create table books(
    book_id int primary key auto_increment,
    book_name varchar(50) not null,
    book_author varchar(20) not null,
    book_price decimal(10,2) not null,
    book_stock int not null,
    book_decs varchar(200)
);
-- 添加图书信息
insert into books(book_name,book_author,book_price,book_stock,book_decs)values('Java程序设计','亮亮',38.80,12,'亮亮老师带你学Java');
insert into books(book_name,book_author,book_price,book_stock,book_decs)values('Java王者之路','威哥',44.40,9,'千峰威哥,Java王者领路人');

-- 创建学生表
create table students(
    stu_num char(8) primary key,
    stu_name varchar(20) not null,
    stu_gender char(2) not null,
    stu_age int not null
);
-- 添加学生信息
insert into students(stu_num,stu_name,stu_gender,stu_age)values('1001','张三','男',20);
insert into students(stu_num,stu_name,stu_gender,stu_age)values('1002','李四','女',20);
insert into students(stu_num,stu_name,stu_gender,stu_age)values('1001','王五','男',20);
```

### 创建存储过程

**业务分析**

> 创建一个存储过程实现借书的操作:哪个学生借哪本书,借了多少本?
>
> 操作:
>
> + 保存借书记录
> + 修改图书库存
>
> 条件:
>
> + 判断学生是否存在?
> + 判断图书是否存在,库存是否存在?

### 创建借书记录表

``` sql
-- 借书记录表
create table records(
	rid int primary key auto_increment,
	snum char(8) not null,
	bid int not null,
	borrow_num int not null,
	is_return int not null,-- 0 表示未归还 1 表示已经归还
	borrow_date date not null,
	constraint FK_RECORDS_STUDENTS foreign key(snum) references students(stu_num),
	constraint FK_RECORDS_BOOKS foreign key(bid) references books(book_id)
);
```

### 实现借书的存储过程

```sql
-- 实现借书业务:
-- 参数1:a输入参数 学号
-- 参数2:b输入参数 图书编号
-- 参数3:m输入参数 借书的数量
-- 参数4:state输入参数 借书的状态(1 借书成功,2学生学号不存在,3 图书不存在 4库存不足)
create procedure proc_borrow_book(IN a char(8),in b int,in m int,out state int)
begin
	declare stu_count int;
	declare book_count int;
	declare stock int default 0 ;
	-- 判断学号是否存在: 根据参数 a  到学生信息表查询是否存在stu_num = a的记录
	select count(stu_num)into stu_count from students where stu_num=a;
	if stu_count>0 then
        -- 学号存在
        -- 判断图书ID是否存在:根据参数b 查询图书记录总数
        select count(book_id) into book_count from books where book_id = b;
        if book_count>0 then
        	-- 图书存在
        	-- 检查图书库存是否够用: 查询图书库存,然后和参数m进行比较
        	select book_stock into stock from books where book_id = b;
        	if stock >= m then
        		-- 库存足够 可以借出
        		set state = 1;
        		-- 执行借书
        		-- 操作1:在借书记录表中添加记录
        		insert into records(snum,bid,borrow_num,is_return,borrow_date)values(a,b,m,0,sysdate());
        		-- 操作2:
        		update books set book_stock = stock-m where book_id=b;
        	else 
        		-- 库存不足
        		set state = 4;
        	end if;
        else 
        	-- 图书不存在
        	set state = 3;
        end if;
	else 
	-- 学号不存在
		set state = 2;
	end if;
end;
```



 ## 游标

> 问题:如果我们要创建一个存储过程,需要返回查询语句查询到的多条数据,该如何实现呢?

### 游标的概念

> 游标可以用来依次取出查询结果集中的每一条数据--逐条读取查询结果集中的记录

### 游标的使用步骤

1. 声明游标

   + 声明游标语法:

   ```sql
   declare cursor_name cursor for slect_statement;
   ```

   + 示例

   ```sql
   declare mycursor cursor for select book_name,book_author,book_price from books;
   ```

2. 打开游标

   ```sql
   open mycursor;
   ```

3. 使用游标

   ```sql
   fetch mycursor into bname,bauthor,bprice;
   ```

4. 关闭游标

   ```sql
   close mycursor;
   ```

​		

案例

```sql
create procedure proc_test2(out result varchar(200))
begin
	declare bname varchar(20);
	declare bauthor varchar(20);
	declare bprice decimal(10,2);
	declare num int;
	declare i int;
	declare str varchar(50);
	-- 此查询语句执行之后返回的结果是一个结果集(多条记录)
	declare mycursor cursor for select book_name,book_author,book_price from books;
	select count(book_id) into num from books;	
-- 打开游标
	open mycursor;	
	-- 使用游标要结合循环语句
	set i =0;
	while i<num do
		-- 提取游标:当前指向的记录(提取之后,游标自动下移)
		 fetch mycursor  into bname,bauthor,bprice;
		set i=i+1;
		set str = concat_ws('~',bname,bauthor,bprice);
		set result = concat_ws(',',result,str);
	end while;
	-- 关闭游标
	close mycursor;
end;
```

## 触发器

### 触发器的介绍

> 触发器,就是一种特殊的存储过程.触发器和存储过程一样是一个能够完成特定功能,存储在数据库服务器上的SQL片段,但是触发器无需调用,当对数据表中执行DML操作时自动触发SQL片段的执行,无需手动调用.
>
> 在MySQL,只有执行insert\delete\update操作才能触发触发器的执行

### 触发器的使用

#### 案例说明:当向学生信息表中添加,删除,修改学生信息时,使用触发器进行记录日志

### 创建触发器

语法:

````sql
create trigger tri_name 
<before|after> 			-- 定义触发时机
<insert|delete|update>  -- 定义DML类型
ON <table_name> 
for each row            -- 声明为杭集触发器(只要操作一条记录 触发器就执行一次)
SQL                     -- 触发器操作
````



````sql
-- 创建触发器:当学生信息表添加操作时,则向日志信息表中记录一条rizhi
create trigger tri_test1
after insert on students
for each row 
insert into stulogs(time,log_text)values(now(),concat('添加',NEW.stu_num,'学生信息'));
````

### 查看触发器

```sql
show triggers;
```

### 删除触发器

```sql
drop trigger tri_test1;
```

## NEW与OLD

> 触发器多用于监听对数据表中的数据insert ,delete,update操作,在触发时通常处理一些DML的关联操作;我们可以使用**NEW**和**OLD**关键字在触发器中获取这个触发器的DML操作的数据
>
> + NEW:在触发器用于获取insert操作添加的数据,update操作修改后的记录
> + OLD:在触发器中用于获取delete操作删除前的数据,update操作修改前的数据

### **NEW**

+ insert操作:NEW表示添加的新记录

  ```sql
  create trigger tri_test1
  after insert on students
  for each row 
  insert into stulogs(time,log_text)values(now(),concat('添加',NEW.stu_num,'学生信息'));
  ```

+ update操作中:NEW表示修改后是数据

  ```sql
  create trigger tri_test2
  after update on students 
  for each ROW 
  INSERT into stulogs (time,log_text) values(now(),concat('修改学生信息为:',NEW.stu_num,NEW.stu_name));
  
  UPDATE students set stu_name='李10'where stu_num ='1007';
  
  ```

### OLD

+ delete:OLD表示删除的记录

  ```sql
  -- 当从students表中删除学生信息时,同时要在stulogs中添加一条日志
  create trigger tri_test3
  after delete on students
  for each ROW 
  insert into stulogs (time,log_text)values(now(),concat('删除',OLD.stu_num,'学生信息'));
  
  delete from students  where stu_num ='1007';
  ```

+ update:  OLD表示修改前的记录

  ````sql
   create trigger tri_test5
  after update on students 
  for each ROW 
  insert into stulogs(time,log_text) VALUES (now(),concat('将学生姓名从[',OLD.stu_name,']','修改为','[',new.stu_name,']'));
  
  update students set stu_name='哈哈' where stu_num='1005';
  ````




## 触发器的使用总结

### 优点

+ 触发器是自动执行的,当对触发器相关的表执行相应DML操作时立即执行;
+ 触发器可以实现数据表中的级联操作(关联操作),有利于保证数据的完整性;
+ 触发器可以对DML操作的数据进行更为分组的合法性校验

### 缺点

+ 使用触发器实现的业务逻辑如果出现问题将难以定位,后期维护困难
+ 大量使用触发器容易导致代码结构杂乱 ,增加了程序的复杂性
+ 当触发器操作的数据量比较打时,执行效率会大大降低

### 使用建议

+ 在互联网项目中,应避免使用触发器
+ 在并发量不大的项目可以使用存储过程,但是互联网项目中不提倡使用存储过程(原因:存储过程是将实现业务的逻辑交给数据库处理,一则增减了数据库的负载,二则不利于数据库的迁移)





## 视图

### 视图的概念

> 视图,就是由数据库中的**一张表或者多张表特定的条件查询出数据构造得到** 得到虚拟表

### 视图的作用

+ 安全性:如果将数据表授权给用户操作,那么用户可以CRUD数据表中所有数据,加入我们想要堆数据表中的部分数据进行保护,可以将公开的数据生成数据视图,授权用户访问视图:用户通过查询视图可以获取数据表中公开的数据,从而达到奖数据表中的部分数据堆用户隐藏
+ 简单性:如果我们需要查询的数据源于多张数据表,可以使用多表连接查询来实现:我们通过视图将这些表查询的结果对用户开放,用户则可以直接通过视图获取多表数据,操作更便捷.

### 创建视图

#### 语法

```sql
create view <view_name>
as
select_statement
```

#### 示例

+ 示例1

  ```sql
  -- 创建视图示例1:将学生表中性别为男的学生生成一个视图
  create view view_test1
  as
  select * from students where stu_gender='男';
  -- 查询视图
  select * from view_test1;
  ```

  

+ 示例2

  ```sql
  -- 创建视图示例2:查询学生借书的信息(学生名,图书名,借书数量)
  create view view_test2
  as 
  select s.stu_name,b.book_name,r.borrow_num
  from books b inner join records r inner join students s 
  on b.book_id=r.bid and r.snum=s.stu_num ;
  select * from view_test2 where stu_name !='张三';     
  ```

  

### 视图数据的特性

视图是虚拟表,查询视图的数据是源于数据表的,当对视图进行操作时,对原数据表中的数据是否有影响呢?

**查询操作:**如果在数据表中添加了新的数据,而且这个数据满足创建视图时查询语句的条件,通过查询视图也可以查询出新增数据,当删除原表中满足条件的数据时,也会葱视图中删除

**新增数据**:如果在视图中新增数据,数据会被添加到原始数据表

**删除数据**:如果视图删除数据,数据也会从原表中删除

**修改操作**:如果通过修改数据,则也将修改原数据表中的数据



### **视图的使用建议:**对复杂查询简化,并且不会对数据进行修改的情况下可以使用视图.



### 查询视图结构

```sql
-- 查询视图结构
```

### 修改视图

```sql
-- 方式1
create or replace view view_test1
as 
select * from students where stu_gender='女';
-- 方式2
alter view view_test1
as 
select * from students where stu_gender='男';
```

### 删除视图

+ 删除数据表时会同时删除数据表中的数据,删除视图时不会影响数据表中的数据

```sql
drop view view_test1;
```



## 索引

> 数据库是用来存储数据的,在互联网应用中存储的数据可能会很多{大数据},**数据表中的查询速度会随着数据量的增长逐渐变慢**,从而导致响应用户请求的速度变慢--用户体验差   我们如何提高数据库的查询效率呢?

### 索引的介绍

索引,就是用来提高数据表中数据的查询效率的.

> 索引,就是将数据表中的某一列/某几列的值取出来构造成便于查找的结构进行存储,生成数据表的目录 当前我们进行数据查询的时候,则先在目录 中进行查找得到对于的数据地址,然后在到数据表中根据地址快速的获取数据记录,避免全表扫描

## 索引的分类

MySQL中的索引,根据创建的所有的列不同,可以分为:

+ 主键索引:在数据表的主键字段创建索引,这个字段必须被 primary key修饰,每张表只能有一个主键
+ 唯一索引:在数据表中的唯一列创建的索引(unique), 此列的索引值只能出现一次,可以为null
+ 普通索引:在普通字段上创建的索引,没有唯一性的限制
+ 组合索引:两个及以上字段联合创建的索引

**说明:**

1.  在创建数据表时,将字段设置为主键(添加主键约束),会自动在主键字段创建主键索引
2.  在创建数据表时,将字段声明为唯一键(添加唯一约束),会自动在唯一字段创建唯一索引

## 创建索引

#### 唯一索引

```sql
-- 创建唯一索引:创建唯一索引的列的值不能重复
-- create unique index <index_name> on 表命(列名);
create unique index index_test1 on tb_testindex(tid);
```

### 普通索引

```sql
-- 创建普通索引
-- create index <index_name> on 表名(列命);
create index index_text2 on tb_testindex(name);
```

### 组合索引

```sql
-- 创建组合索引
-- create index <index_name> on 表明(列命1,列命2,列命3);
create index index_test3 on tb_testindex(tid,name);
```

### 全文索引

> MySQL 5.6 版本新增加的索引,可以通过此索引进行全文检索操作,因为MySQL全文检索不支持中文,因此这个全文索引不被开发者关注,在应用开发中通常是通过搜索引擎(数据库中间件)实现全文检索 

```sql
create fulltext index <index_name> on 表名(字段名);
```

### 索引是使用

> 索引创建完成之后无需调用,当根据创建索引的列进行数据查询的时候,会自动使用索引;
>
> 组合索引需要根据创建索引的索引字段进行查询时触发

+ 在命令行窗口中可以查看查询语句的查询规划

  ```sql
  explain select * from tb_testindex where tid=250000\G;
  ```

  

![](/home/ddj/图片/2021-12-03 01-39-40 的屏幕截图.png)



### 查看索引

```sql
-- 命令行
show create table tb_testindex\G;
-- 查询数据表的索引
show indexes from tb_testindex;
-- 查询索引
show keys from tb_testindex;
```



### 删除索引

```sql
-- 删除索引: 索引是建立在表字段上的,不同的表中可能出现相同名称的索引
-- 因此删除索引时需要指定表名
drop index index_test3 on tb_testindex;
```



## 索引的使用总结

优点

+ 索引大大降低了数据服务器在执行查询操作时扫描的数据量,提高查询效率
+ 索引可以避免服务器排序,将随机IO编程顺序IO

缺点

+ 索引是根据数据表的列进行创建的,当数据表中的数据发生DML操作时,索引也需要更新
+ 索引文件也会占用磁盘空间(小问题)

注意事项

+ 如果数据表中的数据不多时,全表扫描可能更加快,不要使用索引;
+ 数据量很大但是DML操作很频繁时,不建议使用索引;
+ 不要在数据重复度高的列上创建索引(性别);
+ 创建索引之后,要注意SQL语句的编写,避免索引失效

## 数据库的事务

### 数据库事务介绍

+ 我们吧完成特定的业务的多个数据的DML步骤称之为一个事务
+ 事务,就是完成一个业务的多个DML

### 数据库事务特性

> ACID特性,高频面试题

+ #### 原子性(Atomicity):一个事务的多个DML操作,要么同时成功,要么同时执行失败

+ **一致性(Consistency)**:事务执行之前和事务执行之后,数据库中的数据是一致的,完整性和一致性不能被破坏

+ **隔离性:(lsolation):数据库允许多个事务同时执行(张三借Java书同时允许李四借Java书),多个并行的事务之间不能相互影响**

+ **持久性(Durabikity):事务完成之后,对数据的操作是永久的**



### MySQL事务管理

### 自动提交

+ 在MySQL中,默认DML指令的执行是自动提交的,当我们执行一个DML指令之后,自动同步到数据库中

  ![](/home/ddj/图片/2021-12-03 17-09-59 的屏幕截图.png)

### 开启事务

> 开启事务,就是关闭自动提交

+ 在事务开始操作之前,执行 **start transaction**开始事务
+ 依次执行事务中的每个DML操作
+ 如果执行的过程的任何位置出现异常,则执行**rollback**回滚事务
+ 如果事务中所有的DML操作都执行成功,则最后执行**commit**提交事务

![](/home/ddj/图片/2021-12-03 17-25-15 的屏幕截图.png)

```sql
-- 开启事务
start transaction;
-- 借书业务
-- 操作1:在借书记录表中添加记录
insert into records (snum,bid,borrow_num,is_return,borrow_date) values('1011',4,2,0,sysdate());

SELECT  aaa;
-- 事务回滚(清除连接缓存中的操作,撤销当前事务已经执行的操作)
rollback;
-- 操作2:修改图书库存
update books set book_stock=book_stock-2 where book_id=4;

-- 提交事务(将连接缓存中的操作写入数据文件)
commit;
```





### 事务的隔离级别

> 数据库允许多个事务并行,多个事务之间是隔离的,相互独立的;如果事务之间不相互隔离并且操作同一数据时,数据的一致性可能被破坏

MySQL数据库事务隔离级别:

+ **读未提交(read uncommitted)**:T2可以读取T1执行单未提交的数据;可能会导致出现脏读

  > 脏读:一个事务读取到另一个事务中未提交的数据

  ![](/home/ddj/图片/2021-12-03 17-45-54 的屏幕截图.png)

+ **读已提交(read committed)**:T2只能读取T1已经提交的数据;避免了脏读但可能会导致不可重复读(虚读)

  > 不可重复读(虚读):在同一个事务中2次查询操作读取到的数据不一致
  >
  > 例如:T2进行一次查询之后在第二次查询之前,T1修改并提交了数据,T2进行了第二次查询读取到的数据和第一次读取到数据不一致 

  

![](/home/ddj/图片/2021-12-03 17-53-02 的屏幕截图.png)

+ **可重复读(repeatable read)**:T2执行第一次查询之后,在事务结束之前其他事务不能修改对应的数据;避免了不可重复读(虚读);但可能会导致幻读

  > 幻读,T2对数据表中的数据进行修改然后查询,在查询之前向数据表中新增了一条数据,就导致T2以为修改了所有数据,但却查询出了与修改不一致的数据(T1事务新增的数据)

![](/home/ddj/图片/2021-12-03 19-59-44 的屏幕截图.png)

+ **串行化(serializable)**:同时只允许一个事务对数据表进行操作;避免了脏读,虚读(不可重复读),幻读问题



| 隔离级别                   | 脏读 | 不可重复读(虚读) | 幻读 |
| -------------------------- | ---- | ---------------- | ---- |
| 读未提交(read uncommitted) | 会   | 会               | 会   |
| 读已提交(read committed)   | 不会 | 会               | 会   |
| 可重复读(repeatable read)  | 不会 | 不会             | 会   |
| 串行化(serializable)       | 不会 | 不会             | 不会 |

#### 设置数据库事务的隔离级别

> 我们可以通过设置数据库默认的事务的隔离界别来控制事务之间的隔离性;
>
> 也可以通过客户端与数据库的连接设置事务间的事务之间的隔离性;(在应用程序中设置--Spring)
>
> MySQL数据库的默认的隔离级别为**'可重复读'**

+ 查看MySQL数据库默认的隔离级别

  ````sql
  -- 在MySQL8.0.3之前
  select @@tx_isolation;
  -- 在MySQL8.0.3之后
  select @@transaction_isolation;
  ````

+ 设置MySQL默认隔离级别

  ```sql
  set session transaction isolation level <repeatable read>;
  ```

  ## 数据库设计

  > MySQL数据库作为数据存储的介质为应用系统提供数据存储的服务,我们如何设计出合理的数据库,数据表以满足应用系统的数据存储需求呢?
  + 车库:是用来存放车辆的,车库都需要划分车位,如果不划分车位,车子杂乱无章的存放可能导致车辆堵塞,同时也可能导致场地的浪费--------优先的场地能通停放最多的车辆,同时方便每一辆车的出入
  + 数据库,是用来存放数据的,我们需要设计合理的数据表--------能够完成数据的存储,同时能够方便的提取我们应用系统所需的数据

  ### 数据库设计流程

  > 数据库是为应用系统服务的,数据库存储什么样的数据也是由应用系统来决定的.
  >
  > 当我们进行应用系统开发时,我们首先要明确应用应用系统功能需求------软件系统的需求分析

  1. **根据应用系统的功能,分析数据实体**(实体,就是要存储的数据对象)
     + 电商系统:商品,用户,订单....
     + 教务管理系统:学生,课程,成绩....

  2. **提取实体的数据项**(数据项,就是实体的属性)
     + 商品(商品名称,商品图片,商品描述...)
     + 用户(姓名,登录名,登录密码...)
  3. **根据数据库设计三范式规范我们数据项**:检查实体的数据项是否满足数据库设计三范式
     + **如果实体的数据项不满足三范式,可能导致数据的冗余,从而引起数据维护困难,破坏数据一致性等问题**
  4. **绘制E-R图**(实体关系图,直观的展示实体之间的关系)
  5. **数据库建模**:
     + 三线图进行数据表设计
     + PowerDesigner
     + PDMan
  6. **建库建表**:编写SQL指令创建数据库,数据表
  7.  **添加测试数据,SQL测试**

## 数据库设计案例

> 学校图书管理系统(借书)

  		1. 数据实体:
  	       + 学生
  	       + 图书
  	       + 类别
  	       + 借书记录
  	       + 管理员
  		2. 提取数据项
  	     + 学生(学号,姓名,性别,年龄,院系编号,院系名称,院系说明..)
  	     + 图书(类别ID,类别名称,类别描述)
  	     + 类别(图书ID,图书名称,图书作者,图书封面,图书价格,图书库存...)
  	     + 借书记录(记录ID,学号,图书编号,数量,是否归还,还书日期)
  	     + 管理员(管理员ID,登录名,登录密码,员工编号,员工姓名,员工编号)
  	     + 员工(员工编号,员工姓名,手机,QQ,邮箱)

## 数据库设计三范式

### 第一范式:

> 要求数据表的字段不可再分

​	以下表不满足第一范式(在数据库中创建不出不满足第一范式的表)

![](/home/ddj/图片/2021-12-03 21-11-07 的屏幕截图.png)

​	将细分的列作为单独的一列

![](/home/ddj/图片/2021-12-03 21-11-44 的屏幕截图.png)

### 第二范式

> 不存在非关键字段对关键字段部分依赖

以下表不满足第二范式

![](/home/ddj/图片/2021-12-03 21-29-12 的屏幕截图.png)

将每个关键字段列出来\关键字段的组合也列出来,依次检查每个非关键字段

![](/home/ddj/图片/2021-12-03 21-34-21 的屏幕截图.png)

### 第三范式

> 不存在非关键字段的之间的传递依赖 

以下数据表不满足第三范式

![](/home/ddj/图片/2021-12-03 22-49-27 的屏幕截图.png)

将关键字段和被依赖的关键字段分贝作为主键,依次检查所有非关键字段的依赖关系

  ## 绘制E-R图

> E-R(Entity_Relationship) 实体关系图,用于直观的体现实体与实体之间的关联关系(一对一,一对多,多对一,多对多)

**E-R图**基本图例 

![](/home/ddj/图片/2021-12-04 17-40-27 的屏幕截图.png)

### E-R图示例

![](/home/ddj/图片/2021-12-04 17-41-02 的屏幕截图.png)

## 三线图 统一数据实体的表结构

> 每个实体创建一张数据表
>
> 多堆多关联:额外创建一个数据表维护关系,关系表分别创建外键与两张表关联
>
> 一对多,多对一关联:在多的一端添加外键与一的一端主键建立外键约束
>
> 一对多关联:在任意一端创建外键与另一端关联主键关联,并将外键设置