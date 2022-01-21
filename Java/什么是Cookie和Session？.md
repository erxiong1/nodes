# 什么是Cookie和Session？

## 第一层

> 什么是Cookie
>
> HTTP Cookie(也叫Web Cookie或者浏览器Cookie) 是服务器发送到用户浏览器并保存在本地的一小块数据,它会在浏览器下次想同一服务器再发送请求时保存并发送到服务器上，通常，它用与告知服务器端两个请求是否来着同一浏览器，如保存用户的登录状态。Cookie 使基于无状态的HTTP协议记录稳定的状态信息成为了可能。
>
> Cookie主要用于下面三个方面：
>
> + 会话状态管理(如用户登录状态，购物车，游戏分数或者其他需要记录的信息)
> + 个性化设置(如用户自定义设置，主题)
> + 浏览器行为跟踪(如跟踪分析用户行为等)
>
> 什么是Session
>
> + Session代表着服务器和客户端一次会话的过程.Session对象存储在特定用户会话所需的属性以及配置信息.这样,当用户在应用程序的Web页之间跳转时,存储在Session对象中的变量将不会丢失,而是在整个用户会话之间一直保存下去,当客户端关闭会话,或者Session超时失效的话介素.

## 第二层

> Cookie和Seesion有什么不同?
>
> + 作用返回不同,Cookie保存在客户端(浏览器),Session保存在服务器端
> + 存取方式的不同,Cookie只能保存ASCII,Session可以存任意数据类型,一般情况下我们可以在Session中保持一些常用变量信息,比如UserID等.
> + 有效期不同,Cookie可设置为长时间保存,比如我们经常使用的默认登录功能,Session一般失效时间较短,客户端关闭或者Session超时都会失效.
> + 隐私策略不同,Cookie存储在客户端,比较容易遭到不发获取,早起有人将登录的登录名和密码存储在Cookie中导致信息被窃取;Session存储在服务器端,安全性相对Cookie要好一些
> + 存储大小不同,单个Cookie保存的数据不能超过4K,Session可存储数据远高于Cookie

## 第三层

> 为什么需要Cookie和Session,他们的关联
>
> 说起来为什么需要Cookie,这就需要从浏览器开始说起,我们都晓得浏览器是没有状态的(HTTP协议无状态),这意味着浏览器并不知道是张三还是李四在和服务器打交道.这个时候就需要有一机制告诉服务器,本次操作用户是否登录,是哪个用户在执行的操作,那这套机制的实现就需要Cookie和Session的配合.
>
> 那么Cookie和Session是如何配合的呢?
>
> 用户第一次请求服务器的时候,服务器根据用户提交的相关信息,创建对应的Session,请求返回时将此Session的唯一表示信息SessionID返回给浏览器,浏览器接受到服务器返回的SessionID信息后,会将此信息存入到Cookie中,同时Cookie记录此SessionID属于哪个域名.
>
> 当用户第二次访问服务器的时候,请求会自动判断此域名下是否存在Cookie信息,如果存在自动将Cookie信息也发送给服务器端,服务端会从Cookie中获取SessionID,在根据SessionID查找对于的Session信息,如果没有找到说明用户没有登录或者登录失效,如果Session证明用户已经登录课执行后面的操作.
>
> 更具以上流程可知,SessionID是连接Cookie和Session的一道桥梁,大部分系统也是更具此原理来验证用户登录状态.

## 第四层

> 既然服务单是根据Cookie中的形象判断用户是否登录,那么浏览器中禁止Cookie,如何保障整个机制的正常运转.
>
> 第一种方案,每次请求中携带一个SessionID的参数,也可以Post的方式提交,也可以在请求的地址后面凭借xxx?SessionID=1342.....
>
> 第二种方式,Token机制,Token机制多用于App客户端和服务器交互的模式,也可以用于Web端用户状态管理.
>
> Token的意思是"令牌",是服务器端生成的一串字符串,作为客户端进行请求的一个标识.Token机制和Cookie和Session的使用机制比较类似.
>
> 当用户第一次登录后,服务器根据提交的用户信息进行生成一个Token,相应时将Token返回给客户端,以后客户端只需要带上这个Token前来请求数据即可,无需再次登录验证.

## 第五层

> 如何考虑分布式Session问题?
>
> 在互联网公司为了可以支持更大的流量,后台往往需要多台服务器共同支撑前段用户请求,那如果用户A服务器登录,第二次跑到服务器B就会出现登录失效的问题.
>
> 分布式Session一般有一下集中解决方案
>
> + Nginx ip_hath策略:服务端使用Nginx代理,每个请求按访问IP的hash分配,这样来自统一IP固定访问一个后台服务器,避免了服务器A创建的Session,第二次分发到服务器B的现象.
>
> + Session复制,任何一个服务器的Session发生改变(增删改),该节点会把这个Session的所有内容序列化,然后广播给所有其它节点
> + 共享Session,服务端无状态话,将用户的Session等信息使用缓存中间件统一管理,保障分发到每一个服务器的相应结果都一致
>
> 建议采用第三种

## 第六层

> 如何解决跨域请求？Jsonp 跨域的原理是什么？
>
> 说起跨域请求，必须要了解浏览器的同源策略，同源策略/SOP（Same origin policy）是一种约定，由 Netscape 公司 1995年引入浏览器，它是浏览器最核心也最基本的安全功能，如果缺少了同源策略，浏览器很容易受到 XSS、CSFR 等攻击。所谓同源是指"协议+域名+端口"三者相同，即便两个不同的域名指向同一个 ip 地址，也非同源。
>
> 解决跨域请求的常用方法是：
>
> - 通过代理来避免，比如使用 Nginx 在后端转发请求，避免了前端出现跨域的问题。
> - 通过 Jsonp 跨域
> - 其它跨域解决方案
>
> 重点谈一下 Jsonp 跨域原理。浏览器的同源策略把跨域请求都禁止了，但是页面中的 `<script><img><iframe>`标签是例外，不受同源策略限制。Jsonp 就是利用 `<script>` 标签跨域特性进行跨域数据访问。
>
> JSONP 的理念就是，与服务端约定好一个回调函数名，服务端接收到请求后，将返回一段 Javascript，在这段 Javascript 代码中调用了约定好的回调函数，并且将数据作为参数进行传递。当网页接收到这段 Javascript 代码后，就会执行这个回调函数，这时数据已经成功传输到客户端了。
>
> JSONP 的缺点是：它只支持 GET 请求，而不支持 POST 请求等其他类型的 HTTP 请求。
>
> 以上就是有关 Cookie 和 Session 常见的面试点，不知道有多少同学可以在面试中准确回答所有问题。



Seesion的钝化和活化

> Session的钝化是值将内存中的Session信息写到服务器本地文件中,活化是指将服务器本地文件中的Session再次读回到内存

Tomact管理Session细节

> 默认情况
>
> tomcat也是开启了Session的活化与钝化功能,不过是Tomcat服务器停止与启动的时候才会触发钝化与活化.钝化他会吧多个用户的Session都放进Sessions.ser文件(该文件在Tomcat服务器work目录下)活化会读取该文件,读取完之后自动删除该文件.
>
> 自定义管理Session
>
> 当我们需要将内存中的Session活跃与否存到本地 我们需要配置
>
> 修改Tomcat配置文件context.xml(在Tomcat安装目录的conf目录下,若使用idea 看情况)
>
> ```xml
> <Manager className="org.apache.catalina.session.PersistentManager" maxIdleSwap="60">
>         <Store className="org.apache.catalina.session.FileStore" directory="MySession"/> 
>  </Manager>
> ```
>
> maxIdleSwap：从最近一次访问服务器后开始计时，经过指定时间（单位：秒）用户没有活动，则将Session钝化到服务器下的文件中。maxIdleSwap="60"，表示经过60秒，用户一直没有活动，则将与用户对应的Session钝化
> directory：指定服务器上保存文件的位置，相对与服务器的work下的项目目录。directory="MySession"该配置生效后，目录如下图
> 
> 

