# Servlet运行原理

> Servlet 是一个Java应用程序,运行在服务器端,用来处理客户端请求并做出相应的程序
>
> Servlet多线程体系结构是建立在Java多线程机制上的,它的生命周期是有Web容器负责的
>
> ​	当客户端第一次请求某个Servlet是,Servlet容器会根据web.xml配置文件实例化这个Servlet类,此时他存储与内存中当有新的客户端请求Servlet时,一般不会在实例化该Servlet类,也就是有多个线程在使用这个实例.这样,当两个或者多个Servlet构建的Web应用时要主要线程安全的问题.每一个请求都是一个线程,而不是进程,因此,Servlet堆请求的处理的性能是非常高的.
>
> ​	对于Servlet,他被设计为多线程,如果每个用户的每次请求都创建一个新的对象来运行的话,系统就会在创建线程和销毁线程耗费很大的开销,大大降低了系统的效率.
>
> 因此,Serlvet多线程背后有一个线程池在支持,线程在初始化期间就创建了一定数量的线程对象,通过太高这些对象的利用率,避免高频率的创建对象,从而达到提高程序的效率的目的(由线程来执行的Servlet的service方法,servlet在tomcat中是以单利模式存在的,Servlet的线程安全问题只有大量的并发是才会显现出来,并且很难发现,因此在编写Servlet程序时要特别主页.线程安全问题主要是有示例变量造成的,因此在Servlet中应避免使用示例变量,那么使用同步来保护要使用的示例变量,单为保证系统的最佳性能,应该同步可用性最小的代码路径)
>
> Struts2的Action是原型,非单例的;会对每个请求,产生一个Action的示例来处理
>
> ​	解决servlet线程安全的方案:同步堆共享数据的操作Synchronized(this){...}.避免使用实例变量
>
> 1. 客户端向服务器端发送请求
>
> 2. 这个过程比较重要,这时Tomcat会创建两个对象:HttpServletResponse和HttpServletRequest.并将它们的应用传递给搞分配的线程
>
> 3. 线程开始着手接洽接洽servlet
>
> 4. Servlet根据传来的是GET和POST,分别调用doGet()和doPost()方法进行处理;
>
> 5. ervlet将处理后的结构通过线程传回Tomcat,并在之后将这个线程销毁后送还线程池
>
> 6. tomcat将吃了后的结构编程一个HTTP相应发送给客户端,这样,客户端就可以接受到处理后的结果了
>
>    <img src="http://static.oschina.net/uploads/space/2014/1209/160108_cQA7_820500.jpg" alt="img" style="zoom:200%;" />

 

## Servlet生命周期的各个阶段

> Servlet运行在Servlet容器中,其生命周期由容器来管理.Servlet的生命周期通过Javax.servlet.Servlet接口中的init(),service()和destroy()方法来表示
>
> Servlet的声明周期包含了下面4个阶段:
>
> 1. 加载和实例化
>
> ​	Servlet容器负责加载和实例化Servlet,当Servlet容器启动时,或者在容器检查到需要这个Servlet来相应第一请求时,创建Servlet示例.当Servlet容器启动后,它必须要知道所需要的Servlet类在什么位置,Servlet.Servlet容器可以从本地文件系统,远程文件系统或者其他的网络服务中通过类加载器加载Servlet,成功加载后,容器创建Servlet的实例.因为容器是通过Java的反射API来创建Servlet实例,调用的是Servlet的默认构造方法(空构造)索引我们在编写Servlet类的时候,不应该提供带参数的构造方法
>
> 2. 初始化
>
>    在Servlet实例化之后,容器将调用的Servlet和init()方法初始化这个对象.初始化的目的是为了让Servlet对象在处理客户端请求前完成一些初始化的工作,如建立数据库的连接,获取配置信息等.对于每一个Servlet实例,init()方法只被调用一次.在初始化期间,Servlet实例可以通过使用容器为它准备的ServletConfig对象从Web应用程序的配置信息(在Web.xml中配置)中获取初始化的参数信息.在初始化期间,如果发送错误,Servlet实例可以抛出异常ServletExcepiton异常或者UnavailavbleException一次来通知容器.ServletException异常用于指明一般的初始化失败,例如没有找到初始化参数;而UnavailavbleException一次泳衣通知容器该Servlet实例不可用,例如数据库服务器没有启动,数据连接无法建立,Servlet就可以抛出UnavailableException异常想容器指明它暂时或永久不可用
>
> 3. 请求处理
>
>    Servlet容器调用Servlet的service()方法对请求进行处理。要注意的是，在service()方法调用之前，init()方法必须成功执行。在service()方法中，Servlet实例通过ServletRequest对象得到客户端的相关信息和请求信息，在对请求进行处理后，调用ServletResponse对象的方法设置响应信息。在service()方法执行期间，如果发生错误，Servlet实例可以抛出ServletException异常或者UnavailableException异常。如果UnavailableException异常指示了该实例永久不可用，Servlet容器将调用实例的destroy()方法，释放该实例。此后对该实例的任何请求，都将收到容器发送的HTTP 404（请求的资源不可用）响应。如果UnavailableException异常指示了该实例暂时不可用，那么在暂时不可用的时间段内，对该实例的任何请求，都将收到容器发送的HTTP 503（服务器暂时忙，不能处理请求）响应。
>
> 4. 服务终止
>
>    当容器检测到一个Servlet实例应该从服务中被移除的时候，容器就会调用实例的destroy()方法，以便让该实例可以释放它所使用的资源，保存数据到持久存储设备中。当需要释放内存或者容器关闭时，容器就会调用Servlet实例的destroy()方法。在destroy()方法调用之后，容器会释放这个Servlet实例，该实例随后会被Java的垃圾收集器所回收。如果再次需要这个Servlet处理请求，Servlet容器会创建一个新的Servlet实例。
>
>    在整个Servlet的生命周期过程中，创建Servlet实例、调用实例的init()和destroy()方法都只进行一次，当初始化完成后，Servlet容器会将该实例保存在内存中，通过调用它的service()方法，为接收到的请求服务。
>
> 