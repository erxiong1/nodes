# Scrapy

> Scrapy是一个为了爬去网站数据，提取结构性数据而编写的应用框架，我们只需要实现少量的代码，就能够快速的抓取
>
> Scrapy使用Twisted异步网络框架，可以加快我们的下载速度。

## 异步和非阻塞的区别

> 异步：调用在发出之前，这个调用就直接返回，不管有无结果
>
> 非阻塞：关注的是程序在等待调用结果（消息，返回值）时的状态，、指在不能立刻得到结果之前，该调用不会阻塞当先线程

![](https://s2.loli.net/2022/01/10/nx7Iwlt4VZWNOfC.png)

## Scrapy 的模块

> Scrapy Engine(引擎) 总指挥：负责数据和信号的在不同模块间的传递   (Scrapy已经实现)
>
> Scheduler(调度器) 一个队列,存放引擎发过来 的request请求 (Scrapy已经实现)
>
> Downloader(下载器) 下载把引擎发过来的requests请求，并返回给引擎 (Scrapy已经实现)
>
> Spider(爬虫) 处理引擎发来的reponse,提取数据,提取url，并交给引擎 (需要手写)
>
> Item Pipeline(管道) 处理引擎传过来的数据，比如存储 (需要手写)
>
> Downloader Middlewares(下载中间件) 可以自定义下载扩展，比如设置代理  (一般不用手写)
>
> Spider MiddlewaresSpider(中间件) 可以自定义自定义requests请求和进行response过滤 (一般不手写)

## Scrapy入门

> 1. 创建一个scrapy项目
>    + scrapy startproject 项目名称 例如scrapy startproject myspider
> 2. 生成一个爬虫
>    + scrapy genspider 名称 域名例如 scrapy genspider jsuacmspider jsuacm.cn
> 3. 提取数据
>    + 完善spider,使用xpath等方法
> 4. 保存数据
>    + pipeline中保存数据

<img src="https://s2.loli.net/2022/01/11/Av98mrz4X1labcJ.png" style="zoom:200%;" />

### 完善spider

> <img src="https://s2.loli.net/2022/01/11/9Dybv28HWh1FsfX.png" style="zoom:200%;" />
>
> 从选择器中提取字符串：
>
> extract()返回一个包含字符串数据的列表
>
> extract_first()返回列表中第一个字符串
>
> 注意：
>
>  	1. spider中parse方法名不能修改
>  	2. 需要爬去的url地址必须要属于allow_domain下的连接
>  	3. respone.xpath()返回的是一个含有selector对象的列表

### pipeline

> <img src="https://s2.loli.net/2022/01/11/Y7kdCn8XEzFb5mN.png" style="zoom:200%;" />

### logging 模块使用

> - scrapy
>
>   	+ setting中设置LOG_LEVEL="WARNING"
>
>   	+ settings中设置LOG_FILE = "./a.log" # 设置日志保存的位置，设置会终端不会显示日志内容
>
>   	+  import logging 实例化logger的方式在任何文件中使用logge输出内容
>
> - 普通项目中
>
>   - import logging
>   - logging.basicConfig(..)# 设置日志输出的样式，格式
>   - 实例化一个logger=logging.getLogger(__name__)
>   - 在任何py文件中调用logger即可

## scrapy.Request

> ![](https://s2.loli.net/2022/01/11/6VgUG4DLupSCAsK.png)

### item

> ![](/home/ddj/图片/2022-01-11 22-51-05 的屏幕截图.png)
