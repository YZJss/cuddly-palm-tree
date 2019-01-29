#  CentOS 7.6 安装jdk

查看JDK软件包列表

```
yum -y list java*
```

```
[root@iZ2zei0fg2v7x4egtl0wllZ ~]# yum -y list java*
Loaded plugins: fastestmirror
Loading mirror speeds from cached hostfile
Available Packages
java-1.6.0-openjdk.x86_64                          1:1.6.0.41-1.13.13.1.el7_3      base
java-1.6.0-openjdk-demo.x86_64                     1:1.6.0.41-1.13.13.1.el7_3      base
java-1.6.0-openjdk-devel.x86_64                    1:1.6.0.41-1.13.13.1.el7_3      base
java-1.6.0-openjdk-javadoc.x86_64                  1:1.6.0.41-1.13.13.1.el7_3      base
java-1.6.0-openjdk-src.x86_64                      1:1.6.0.41-1.13.13.1.el7_3      base
java-1.7.0-openjdk.x86_64                          1:1.7.0.201-2.6.16.1.el7_6      updates
java-1.7.0-openjdk-accessibility.x86_64            1:1.7.0.201-2.6.16.1.el7_6      updates
java-1.7.0-openjdk-demo.x86_64                     1:1.7.0.201-2.6.16.1.el7_6      updates
java-1.7.0-openjdk-devel.x86_64                    1:1.7.0.201-2.6.16.1.el7_6      updates
java-1.7.0-openjdk-headless.x86_64                 1:1.7.0.201-2.6.16.1.el7_6      updates
java-1.7.0-openjdk-javadoc.noarch                  1:1.7.0.201-2.6.16.1.el7_6      updates
java-1.7.0-openjdk-src.x86_64                      1:1.7.0.201-2.6.16.1.el7_6      updates
java-1.8.0-openjdk.i686                            1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk.x86_64                          1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-accessibility.i686              1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-accessibility.x86_64            1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-accessibility-debug.i686        1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-accessibility-debug.x86_64      1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-debug.i686                      1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-debug.x86_64                    1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-demo.i686                       1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-demo.x86_64                     1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-demo-debug.i686                 1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-demo-debug.x86_64               1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-devel.i686                      1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-devel.x86_64                    1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-devel-debug.i686                1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-devel-debug.x86_64              1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-headless.i686                   1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-headless.x86_64                 1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-headless-debug.i686             1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-headless-debug.x86_64           1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-javadoc.noarch                  1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-javadoc-debug.noarch            1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-javadoc-zip.noarch              1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-javadoc-zip-debug.noarch        1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-src.i686                        1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-src.x86_64                      1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-src-debug.i686                  1:1.8.0.191.b12-1.el7_6         updates
java-1.8.0-openjdk-src-debug.x86_64                1:1.8.0.191.b12-1.el7_6         updates

```

安装jdk1.8.0的所有文件

```
yum install -y java-1.8.0-openjdk*
```

```
[root@iZ2zei0fg2v7x4egtl0wllZ ~]# yum install -y java-1.8.0-openjdk*
Loaded plugins: fastestmirror
Loading mirror speeds from cached hostfile
Resolving Dependencies
--> Running transaction check
```

查看JDK是否安装成功

```
java -version
```

```
[root@iZ2zei0fg2v7x4egtl0wllZ ~]# java -version
openjdk version "1.8.0_191"
OpenJDK Runtime Environment (build 1.8.0_191-b12)
OpenJDK 64-Bit Server VM (build 25.191-b12, mixed mode)
```

配置环境变量

JDK默认安装路径`/usr/lib/jvm`

[root@iZ2zei0fg2v7x4egtl0wllZ /]# cd /usr/lib/jvm
[root@iZ2zei0fg2v7x4egtl0wllZ jvm]# ls
java
java-1.8.0
java-1.8.0-openjdk
java-1.8.0-openjdk-1.8.0.191.b12-1.el7_6.x86_64
java-1.8.0-openjdk-1.8.0.191.b12-1.el7_6.x86_64-debug
java-openjdk
jre
jre-1.8.0
jre-1.8.0-openjdk
jre-1.8.0-openjdk-1.8.0.191.b12-1.el7_6.x86_64
jre-1.8.0-openjdk-1.8.0.191.b12-1.el7_6.x86_64-debug
jre-openjdk

在`/etc/profile`文件最后一行添加如下代码

```
# set java environment  
JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.191.b12-1.el7_6.x86_64
PATH=$PATH:$JAVA_HOME/bin  
CLASSPATH=.:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar  
export JAVA_HOME  CLASSPATH  PATH 
```

`ESC`退出`:wq`保存`profile`文件

执行如下生效

```
source  /etc/profile
```

```
vim first.java
```

```
public class first{
      public static void main(String args[]){
        System.out.println("This is my first program.");
      }
    }
```

```
[root@iZ2zei0fg2v7x4egtl0wllZ ~]# javac first.java
[root@iZ2zei0fg2v7x4egtl0wllZ ~]# java first
This is my first program.

```

