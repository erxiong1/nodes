# GIT

## 命令查询表

> - 工作区-> 缓存区 git add .
> - 暂存区-> 仓库 git commit -m "commit message"
> - 查看状态 git status
> - 查看提交记录 git log   git-log(个性化配置的原命令git log --pretty=oneline --all --graph --abbrev-commit')
> - 版本回退 git reset --hard <commitID>
> - 查看分支 git branch
> - 创建并切换分支 git checkout -b 分支名
> - 切换分支 git checkout 分支名
> - 分支合并 git merge 分支名
> - 远程仓库 
>   - remote add 添加远程仓库
>   - push
>   - clone
>   - fetch
>   - pull(fetch+merge)

## Git工作流程图

> <img src="https://s2.loli.net/2022/01/16/6ob54qcClZ8SePV.png" style="zoom:200%;" />
>
> 命令如下：
>
> 1. clone(克隆):从远程仓库中克隆代码到本地
> 2. checkout(检出):从本地仓库中检出一个仓库分支然后进行修订
> 3. add(添加):在提交前先将代码提交到缓存区
> 4. commit(提交):提交到本地仓库.本地仓库中保存修改的各个历史版本
> 5. fetch(抓取):从远程库,抓取到本地仓库，不进行任何的合并动作，一般操作比较少
> 6. pull(拉取):从远程库拉到本地库,自动进行合并(merge),然后放到工作区,想到与fetch+merge
> 7. push(推送):修改完成后,需要和团队成员共享代码时,将代码推送到远程仓库

## 一些小命令

> + ls/ll: 查看当前目录
> + cat 查看文件内容
> + touch:创建文件
> + vi vi编辑器

### 备注

> Git GUI:Git提供图像界面工具
>
> Git Bash:Git提供的命令行工具
>
> 当安装Git后首先要做的事情是设置用户名和email地址。这是非常重要的，因为每次Git提交都会使用该用户的信息

## 基本配置

>1. 打开Git Bash
>
>2. 设置用户信息
>
>   + 设置用户信息
>
>   + git config --global user.name ‘名称’
>   + git config --global user.email ‘邮箱’
>   + 查看用户信息
>   + git config --global user.name
>   + git config --global user.email
>
>3. 创建.bashrc文件<img src="https://s2.loli.net/2022/01/17/LfbBwMcXiYsVyqd.png" style="zoom:200%;" />
>
>4. 在.bashrc文件中输入下内容:
>
>   > #用于输出git提交日志
>   >
>   > alias git-log='git log --pretty=oneline --all --graph --abbrev-commit'
>   >
>   > #用于输出当前目录所有文件及基本信息
>   >
>   > alias ll='ls -al'

## git 基本命令

> 初始化一个git仓库
>
> git init
>
> ![](https://s2.loli.net/2022/01/17/a4UgszGcNWhn5Cj.png)
>
> + git add(工作区 --> 暂存区)
> + git commit (暂存区 --> 本地仓库)
>
> 查看修改的状态(status)
>
> + 作用：查看的修改的状态(暂存区，工作区)
> + 命令形式 :git status
>
> 添加工作区到缓存区
>
> + 作用：添加工作区一个或多个文件的修改到缓存区
> + 命令形式: git add 单个文件名|通配符
>   + 将所有修改加入到缓存区: git add .
>
> 提交缓存区到本地仓库(commit)
>
> + 作用：提交缓存区内容到本地仓库的当前分支
> + 命令形式: git commit -m “注释内容”
>
> 查看提交日志(log)
>
> + 作用：查看提交记录
> + 命令形式: git log [option]
>   + options
>     +  --all 显示所有分支
>     + --pretty-oneline将提交信息显示为一行
>     + --abbrev-commit 使得输出的commitld更剪短
>     + --graph以图的形式显示
>
> 版本回退
>
> + 作用:版本切换
> + 命令形式：git reset --hard commitID
>   + commitID 可以使用git log指令查看
>   + 如何查看已经删除的记录?
>     + git reflog
>     + 这个指令可以看到已经删除的提交记录

### 添加文件之忽略列表

> 一般我们总会有些文件无需纳入Git的管理,也不希望它门总出现在未跟踪的文件列表。通常都是自动生成的文件，比如日志文件，或者编译过程中创建的临时文件。在这种情况下，我们可以在工作目录中创建一个名为**.gitignore**的文件(文件名称国定),列出要忽略的文件模式
>
> ![](https://s2.loli.net/2022/01/17/tZ4IgSWPNFq7YCX.png)

## 分支

> 几乎所有的版本控制系统都以某种形式支持分支。使用分支意味着可以把你的工作从开发主线分离开来进行重大Bug修改，开发新功能，以免影响开发主线 
>
> 查看本地分支
>
> + 命令：git branch
>
> 创建本地分支
>
> + 命令：git branch 分支名
>
> 切换分支
>
> + 命令：git checkout 分支名
>
> 创建并切换到分支
>
> + git checkout -b 分支名
>
> 合并分支(merge)
>
> 一个分支上的提交可以合并到另一个分支
>
> 命令：git merge 分支名称
>
> 删除分支
>
> 不能删除当前分支，只能删除其他分支
>
> git branch -d 名称 删除分支时,会做各种检查
>
> git branch -D 名称 不做任何检查，强制删除
>
> ### 解决冲突
>
> 当两个分支堆文件的修改可能会存在冲突，例如同时修改了同一个文件的同一行，这时就需要手动解决冲突，解决冲突步骤如下
>
> 1. 处理文件中冲突的地方
> 2. 将解决完冲突的文件加入暂存区(add)
> 3. 提交到仓库(commit)<img src="/home/ddj/图片/2022-01-18 01-06-40 的屏幕截图.png" style="zoom:200%;" />
>
> ### 开发中分支使用的原则与流程
>
> 在开发中，一般有如下分支使用的原则与流程：
>
> + master(生产)分支
>
>   线上分支，主分支，中小规模项目作为线上运行的应用对于的分支；
>
> + develop(开发)分支
>
>   是从master创建的分支，一般作为开发部分的主要开发分支，如果没有其他并行开发不同时期上线的要求，都可以在此版本进行开发，阶段开发完成后，需要是合并到master分支，准备上线
>
> + feature/xxxx分支
>
>   从develop创建的分支，一般是同期并行开发，但不同期上线时创建的分支，分支上的研发任务完成后合并到develop分支
>
> + hotfix/xxxx分支
>
>   从master派生的分支，一般作为线上的bug修复使用，修复完成后需要合并到master，test，develop分支
>
> + 还有一些其他分支，如test分支(用于代码测试)，pre(预上线分支)等等。
>
>   ![](https://s2.loli.net/2022/01/18/qGzbEwQrdx3Ja18.png)

## Git远程仓库

## 常用的托管服务[远程仓库]

> Git仓库分为本地仓库和远程仓库.那么如何搭建Git远程仓库?我们可以借助互联网上提供的一些代码托管服务来实现，其中比较常见从有GitHub,码云，GitLab等。  
>
> gitHub(地址:https://github.com/)是一个面向开源的寄私有软件项目的托管平台，因为只支持Git作为唯一的版本库个数进行托管，故名gitHub
>
> 码云(地址:Https://gitee.com/)是国内的一个代码托管平台，由于服务器在国内，所以相比于Github，码云速度更加快
>
> GitLab(地址:https://about.gitlab.com/)是一个用于仓库管理系统的开源项目，使用Git作为代码管理工具，并在基础上搭建起来的web服务器，一般用于企业，学校内部网络搭建git私服。
>
> ## 配置本地仓库和远程仓库
>
> https://blog.csdn.net/p812438109/article/details/110421304
>
> ### 操作远程仓库
>
> **此操作是先初始化本地仓库，然后与创建的远程库进行对接**
>
> + 命令：git remote add <远端名称> <仓库路径>
>
>   + 远端名称，默认使用origin,取决于远端服务器设置
>
>   + 远程路径，从远端服务器获取此URL
>
>   + 例如：git remote add origin git@github.com:erxiong1/git_test.git
>
>     <img src="https://s2.loli.net/2022/01/18/3cbw4jWavKZiSrQ.png" style="zoom:200%;" />
>
> 查看远程仓库
>
> + 命令：git remote
>
>   <img src="https://s2.loli.net/2022/01/18/nfgXUBCVhp3MxjK.png" style="zoom:200%;" />
>
> 推送到远程仓库
>
> + 命令：git push [-f] [--set-upstream] [远端名称 [本地分支名:远端分支名]]
>
>   例如：git push --set-upstream origin master:master
>
>   git branch -vv查看本地仓库和远程仓库分支对应关系
>   建立对于关系之后就可以git push直接推送
>
>   <img src="https://s2.loli.net/2022/01/18/nluNZy4wQRMeiqY.png" style="zoom:200%;" />
>
>   + 如果分支名和本地分支名称相同，则可以只写本地分支
>     + git push origin master
>   + -f 表示强制覆盖
>   + --set-upstream 推送到远端的同时并且建立起和远端分支的关联关系。
>     + git push --set-upstream origin master
>   + 如果当前分支已经和远端分支关联，则可以省略分支名和远端名
>     + git push 将master 分子推送到已经关联的远端分支
>
> 本地仓库与远程仓库的关联关系
>
> + 查看关联关系 git branch -vv
>
>   <img src="https://s2.loli.net/2022/01/18/tPNjgnYzQXCoM3m.png" style="zoom:200%;" />
>
> 从远程仓库克隆
>
> 如果已经有一个远程仓库，我们可以直接clone到本地
>
> + 命令: git clone <仓库路径> [本地仓库]
>
>   + 本地目录可以省略,会自动生成一个目录
>
>     <img src="/home/ddj/图片/2022-01-18 20-18-50 的屏幕截图.png" style="zoom:200%;" />
>
> 从远程仓库中抓取和拉取
>
> 远程分支和本地分支一样，我们可以进行merge操作，只需要先把远端仓库里的更新都下载到本地，在进行操作
>
> + 抓取 命令：git fetch[remote name] [branch name]
>   + 抓取命令就是将仓库里的更新都抓取到本地，不会进行合并
>   + 如果不指定远端名称和分支名称，则抓取所有分支
> + 拉取 命令：git pull [remote name] [branch name]
>   + 拉取命令就是将远端仓库的修改拉取到本地进行合并，等同于fetch+merge
>   + 如果不指定远端名称和分支名，则抓取所有分支并更新当前分支
>
> 解决合并冲突：
>
> 在一段时间A.B用户修改了统一个文件，此时B用户在本地修订代码，提交到本地仓库后，也需要推送到远程仓库，此时B用户晚于A用户，**故需要先拉取远程仓库的提交,经过合并后才能推送到远端的分支**
>
> <img src="/home/ddj/图片/2022-01-18 20-59-58 的屏幕截图.png" style="zoom:200%;" />
>
> 在B用户拉取代码时，因为A，B用户同一段时间修改了同一个文件的相同位置代码，故会发送合并冲突
>
>  **远程分支也是分支，所以合并时发生冲突的解决方式和解决本地分支冲突相同**

## 在Idea中使用Git

> 在Idea中配置Git
>
> 在setting中设置
>
> ![](https://s2.loli.net/2022/01/19/IVkOrZLupWG9cQU.png)
>
> Idea常用的Git操作入口
>
> ![](https://s2.loli.net/2022/01/19/nDs6wB3eGkhYPXZ.png)
>
> ![](https://s2.loli.net/2022/01/19/O3hEQJLBfDF7ZNd.png)

## 几条铁令

> 1. **切换分支前先提交本地的修改**
> 2. 代码及时提交,提交过了就不会丢
> 3. 遇到任何问题都不啊哟删除文件目录，查找原因
