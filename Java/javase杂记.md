1. javac Myjava.java

   >  该命令是编译Myjava.java文件生成字节码MyJava.class文件

2. Java MyJava

> 改命令执行生成字节码文件后的允许结果

3. javac 

   > 该命令java文件生成字节码文件

4. javap

> 该命令反向生成反编译字节码指令文件

JDB:

> jdb是基于文本和命令行的调试工具(例如Sun JDB);虽然现在有一些很好的调试工具,然后Java调试器(JDB)提供了一些优点.最重要的是JDB可以免费获取并且是平台独立的.其缺点是它只有命令行格式,一些开发人员任务这很原始,而且难以使用.

### 环境变量

1. PATH:作用是指定**命令的搜索路径**,在命令行下面执行命令如javac编译java程序时候,他会到PATH便令所指定的文件中找到命令
2.  CLASSPATH:作用是指定类的搜索路径,要使用已经编写好的类,JVM就是通过CLASSPATH来寻找class文件的
3. JAVA_HOME: 它指向jdk的安装路径,IDEA/tomcat等软件就是通过搜索JAVA_HOMDE变量来找到并安装好的jdk



SDK包含JDK包含JRE包含JVM

JAVA的(**跨平台**)特性实现了开发人员的一次编写,处处运行的梦想

Java语言是纯(**面向对象**)编程语言.一种是可以独立允许的(**应用程序**),另一种是内嵌于网页(**小程序**)

一定要**小写 ** **path** 和 **classpath**

虽然Java是解释性语言,但随着(**JIT**)编译器技术的发展,Java程序的运行速度越来越接近与C++等编译型语言.

> ## JIT
>
> JIT即使编译
>
> 1. 动态编译(dynamic compilation)指的是"在运行时进行编译";与之相对的是事前编译(ahead-of-time compilation,简称AOT),也叫静态编译(static compilation)
> 2. JIT编译(just-in-time compilation)狭义来说是当面某段代码即将第一次被执行时,进行编译,因而交"即使编译".**JIT编译是动态编译的一种特列**JIT编译一词后来被泛华,时长与动态编译等价;但是主要广义与狭义的
>    JIT编译所指的区别.
> 3. 自适应动态编译(adaptive dynamic compilation)也是一种动态编译,单他通常执行的时机比JIT编译迟,先让程序"以某种式"先允许起来,手机一些信息之后再做动态编译.这样的编译也可以更加优化.

在某台计算器中安装JDK之后,安装路径下的bin文件夹中(**java.exe**)文件用于启动Java虚拟机(jvm)

utf-8 一个汉字3个字节

英文字符1个字节

gbk一个汉字2个字节

英文字符1个字节

unicode一个汉字2个字节

一个英文字符2个字节

byte类型给其他赋值不需要强制类型转换

包装类中的SIZE属性是保存的bit数

Unicode编码 是统一码

0.05+0.01==0.060000000000000005

## 转义字符

0开头八进制

0x开头16进制





System.out.println('1'+'2'+""+3+4);

'1'+'2'为自动转换为了int 也就是99 然后+""转为字符串 加上3 加上4得到9934



java中的应用类型是:

1. 类
2. 数组
3. 接口
4. 字符串

```java
System.out.println(true?9:99.0);
//输出结果是9.0
```



java中所有的内容必须处于类的内部

java程序中没必要有一定一个main方

java中科学计数法是double类型的

利用逻辑

Java程序中定义的变量三要素是(变量名,变量类型,变量值)

Java语言进行单行注释的//(**反斜杠**)



Double.parseDouble(s1)+Double.parseDouble(s2)

switch支持的数据类型

1. 枚举
2. byte
3. short
4. char
5. int
6. String

Random类

```java
Random random = new Random();
random.nextInt(100);//产生一个不打野100的随机数
```



String的equalslgnoreCase()方法是不区分大小写的比较

获取字符串某个位置的字符应该使用String类的**charAt()**方法

在事先不晓得循环语句重复执行的次数时,可以用一个(**布尔**)值来终止循环.

if...else if语句的执行效率总是比switch语句高.

break语句用来退出当前循环语句

简单的if...else语句可以使用(**?:**)运算符来替代

char byte short int

Java的选择结构有(**if**)语句和(**switch**)语句



continue和break语句都能在(**循环**)语句中使用,此外break还可以在(**switch**)语句中使用

break label

> PrintStream ps = new PrintStream(System.out);

msg.substring(start,end);不会输出end



java中 new 数组至少指定第一维度

Java语言中,数组的维数用(**[]**)的个数来确定,利用(**new**)关键字为数组分配空间,利用(**数组名.length**)获取数组长度.

通过(**下标**)访问数组元素,一维数组array的长度为(**array.length**)

Java语言中,相同元素个数和类型的一维数组要比二维数组占用的存储空间要小



Arrays.copyOfRange(arr1,5,arr1.length)生成一个新的数组 复制arr1数组下标5到array.length前一个

通过(**采用不同的形式参数列表**)来区分方法的重载

在**运行**阶段,JVM根据每个方法所用的参数类型和个数来决定调用哪个具体的方法.

**Arrays.sort(arr)实现排序**

构造方法不需要类型

this

+ 通过this关键字可以明确的访问一个类的成员变量,解决成员变量和局部变量冲突问题
+ 通过this关键字调用成员方法
+ 在构造方法中访问构造方法this(args)

静态方法中不可以使用this关键字

JVM为命名对象分配(**栈**)空间来存储对象首地址,分配(**堆**)空间来存储对象信息

## 普通内部类有以下几个主要特点

1. 内部类可以访问其所在类的属性(包括在类的私有属性),内部类创建自身对象需要先创建所在类的对象
2. 可以定义内部接口,且可以定义另一个内部类实现这个内部接口
3. 可以在方法体内定义一个内部类,方法体内的内部类可以完成一个基于虚方法的回调操作
4. 内部类不能定义static元素
5. 内部类可以多嵌套

静态内部类 和内部类不同 静态内部类不仅可以在内部类定义static元素,而且在构建对象的时候也可以一次完成,从某种意义上将 静态内部类已经不算严格意义上的内部类了

OOA面向对象分析法

OOD面向对象设计

OOP面向对象编程

面向过程程序设计的核心是(**算法**)

new 不会产生新的类 只是实例化一个类

定义外部类 要么public 要么**缺省**

定义内部类 要么private 要么**默认**

默认构造方法和他所在类相同的访问权限修饰符

不能说创建对象的实例 **对象就是实例**

创建实例??创建什么实例

教室门前的一颗落叶松 也是一个对象 震惊

**普通代码块是指方法或静态方法的代码块**

Java程序中,类是有(**成员变量**)和(**方法**)组成的一个程序单元

JVM中栈空间存储对象的(**引用**),堆空间存储对象的(**成员变量**)



在面向对象分析方法中(OOA)对象具有(对象标识,属性,行为)

老师 学生 课件 计算机 课本

构造方法不能被重写

匿名类不能有静态数据和静态成员方法

吉首大学static final

119 25 30

abstract 方法必须在abstract类中

继承抽象类必须重写抽象方法

interface只能是public abstract

JDK8以后运行interface中定义非抽象的方法单必须是**default**或者**static**修饰并且后面要接{}

## final关键字

+ final修饰的类无法被继承
+ final修饰的方法无法被重写
+ final修饰的局部变量只能被赋值一次
+ final修饰的实例变量必须手动赋值
+ final修饰的实例变量一般添加static修饰 变为静态的 存在方法区,节省空间
+ final修饰的成员变量如果是基本数据类型必须定义时就初始化

# interface

1. 所有成员变量都默认是public static final修饰
2. 所有方法都是public abstract修饰
3. 没有构造方法
4. 接口的实现类必须重写所有的方法
5. 接口也可以继承接口(多继承)多继承时用逗号隔开
6. 如果没有实现接口中的全部方法,必须将此类定义为抽象类
7. JDK8以后新增default关键字可以写非抽象方法
8. JDK8以后还附带static默认的实现方法
9. 接口可以继承多个接口
10. 一个类可以实现多个接口
11. 接口中的默认方法只能是子类来调用

## super关键字

+ super能出现在实例方法和构造方法中

+ super的语法是"super."和"super()"

+ super不能出现在静态方法中

+ super大部分情况可以省略

+ 什么时候不能省略

  >当子类想访问父类的东西的时候使用super. 的方式访问例如 子类内部想调用父类被重写的方法的时候,可以使用super.的方式 当子类出现和父类一样的属性或者方法的时候,此时,**想调用父类的同名属性和方法此时的super.就不能省略**

+ super()是调用父类构造器是必掉的 没有调用空构造 有就匹配参数调用构造

抽象类可以继承抽象类

重写不能改变方法的修饰符

## UML图

![](https://s2.loli.net/2021/12/11/hDCj9pLbSBy8Xz7.png)

继承关系

![](https://s2.loli.net/2021/12/11/mwJzxPfvC62KOFo.png)

实现关系

![](https://s2.loli.net/2021/12/11/IVXn5zBjTL7JAfk.png)

双向关联

![](https://s2.loli.net/2021/12/11/QYILwiCKzgTjRSu.png)

![](https://s2.loli.net/2021/12/11/VF8hZfvog7t3Pcw.png)

![](https://s2.loli.net/2021/12/11/jnJ9LiyCkt14UI6.png)

![](https://s2.loli.net/2021/12/11/5je1hUbTMq2CKxP.png)

![](https://s2.loli.net/2021/12/11/Jrx4uIQog3eUD81.png)

动态绑定和静态绑定



**修饰符必须写在返回值前面**

static可以被重写

abstract 可以修饰interface

在面向对象软件开发过程中,继承机制在(**代码复用**,**提高软件开发**,**降低软件系统维护成本**)等方面具有重要作用

面向对象程序设计中,使用设计模式的作用包括(**其他人更容易理解**,**代码复用**,**保证代码可靠性**)

不可以super.super

重载要求参数类型也一致

类的实例方法可以直接调用本类的的类方法

一般情况下,需要通过set和get方法访问封装的私用成员变量

对象的多态性主要分为**向上转型**和**向下转型**

在设计新类是,为了使类具有较强的扩展性最好重写(toString)和(equals)方法

![](https://s2.loli.net/2021/12/11/ixydKN1q5kz7CLg.png)

依赖关系

关联关系

![](https://s2.loli.net/2021/12/11/AbxHzCkidB3yRfU.png)

![](https://s2.loli.net/2021/12/11/iSBbd6JnprxH4Ue.png)

实现关系

![](https://s2.loli.net/2021/12/11/xY1VTJPa2I7w9Sj.png)

继承关系

不能被继承但可以被重载

# 记住 (Person)obj

多态发生时 成员变量还是我的成员变量 但是方法是儿子的方法

静态依然是自己静态

如果想使用jar包必须配备环境变量classpath

包的命名没有规则 但是我们墨守成规 都用小写 并且是域名倒着写的



Java的体现结构中,最下层是(**移植接口**),由适配器和Java OS组成,保证Java体系结构可以跨平台

必须类和方法都是public 不同包才可以访问



import static 导入静态资源

throws用来声明一个方法可能抛出的所有异常信息,表示出现异常的一种可能性,但并不一定发生这些异常,throw则是抛出一个具体的异常类型,执行throw则一定抛出某种异常



return 不能打断finally

> ### 1.为什么不是java.lang.ArithmeticException: / by zero？
> ​       之所以没有报异常，是因为这是浮点的除法，也就是说0.0并不是真正意义上的0，它只不过是非常接近0而已，所以y一个数除以一个接近0的数，那么结果应为无穷大。而在java浮点范围内存在Infinity表示无穷大的概念。
> 例如：System.out.println(3/0.0); 结果为**Infinity**(无穷大)
>
> ## 2、NAN
>    浮点算术保留了一个特殊的值用来表示一个不是数字的数量,这个值就是NaN（“不是一个数字（Not a Number）”的缩写）。对于所有没有良好的数字定义的浮点计算，**例如0.0/0.0，或者对负数求平方根**其值都是它。例如：
>
> NAN与任何数字比较都是false

将Java源代码翻译成字节码的时候会产生的错误为(**编译错误**),而程序运行时产生的错误为(**运行错误**)

计算机程序错误分为(**语法错误**).(**运行错误**)(**逻辑错误**)

FileInputStream.read()方法抛出的IOException

为了达到程序的高效运行的要求，(**运行**)异常可以直接交给Java虚拟机系统来处理，而Exception类派生出的非运行异常，要利用try语句捕获或者利用throw抛出

Throwable类是java.lang包中的一个类,它派生了Error和Exception等两个子类

按照异常在编译的时候是否被检查，把异常分为(**检查时异常**)和(**运行时异常**)

异常包括：

> + 程序执行过程中遇到的事先没有预料到的情况
> + 程序实现定义好的可能出现的意外情况

throw关键字抛出的对象包括

> Error对象
>
> Throwable子类对象
>
> Exception
>
> RuntimeException





String trim()方法是删除字符串前面多余空格

Arrays.copyOfRange(arr1,5,arr1.length);

Arrays.sort(arr);

new 不会产生新类 只会实例化一个类

外部类只能是public 和缺省的

内部类只能是private和缺省的

默认构造方法和他躲在类的相同的访问权限修饰符

JVM中，栈内存存储对象的应用，堆内存中存储对象的**成员变量**

**在面向对象分析法中，对象具有标识，属性，行为**

static final

重写不能改变方法的修饰符

一般情况下要通过set get来访问封装的私有成员方法

从方法的角度来说 对象多态分为**重载和重写**

最好重写toString和equals

实线是关联 虚线是依赖

实现是继承 虚线是实现

实心是组合 空心是聚合

接口的默认方法只能通过子类对象调用





