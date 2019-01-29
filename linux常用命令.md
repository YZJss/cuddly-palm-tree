linux常用命令  

apt-get update/install  Debian, Ubuntu   						升级/安装列表中的软件包  
yum install 		centos									安装软件包  
wget 													下载文件  
pscp D:/xxx.xx root@服务器地址:/root/xxx.xx					本地向服务器发送文件  
pscp -l root -pw 密码 服务器地址:/root/xxx.xx D:\xxx.xx		服务器像本地发送文件

arch 显示机器的处理器架构(1)   
uname -m 显示机器的处理器架构(2)   
uname -r 显示正在使用的内核版本   
dmidecode -q 显示硬件系统部件 - (SMBIOS / DMI)   
hdparm -i /dev/hda 罗列一个磁盘的架构特性   
hdparm -tT /dev/sda 在磁盘上执行测试性读取操作   
cat /proc/cpuinfo 显示CPU info的信息   
cat /proc/interrupts 显示中断   
cat /proc/meminfo 校验内存使用   
cat /proc/swaps 显示哪些swap被使用   
cat /proc/version 显示内核的版本   
cat /proc/net/dev 显示网络适配器及统计   
cat /proc/mounts 显示已加载的文件系统   
lspci -tv 罗列 PCI 设备   
lsusb -tv 显示 USB 设备

shutdown -h now 关闭系统(1)   
init 0 关闭系统(2)   
telinit 0 关闭系统(3)   
shutdown -h hours:minutes & 按预定时间关闭系统   
shutdown -c 取消按预定时间关闭系统   
shutdown -r now 重启(1)   
reboot 重启(2)   
logout 注销 

cd /home 进入 '/ home' 目录  
cd .. 返回上一级目录   
cd ../.. 返回上两级目录   
cd 进入个人的主目录   
cd ~user1 进入个人的主目录   
cd - 返回上次所在的目录

pwd 显示工作路径  
ls 查看目录中的文件   
ls -F 查看目录中的文件   
ls -l 显示文件和目录的详细资料   
ls -a 显示隐藏文件 

mkdir dir1 创建一个叫做 'dir1' 的目录'   
mkdir dir1 dir2 同时创建两个目录   
mkdir -p /tmp/dir1/dir2 创建一个目录树 

rm -f file1 删除一个叫做 'file1' 的文件'   
rmdir dir1 删除一个叫做 'dir1' 的目录'   
rm -rf dir1 删除一个叫做 'dir1' 的目录并同时删除其内容   
rm -rf dir1 dir2 同时删除两个目录及它们的内容

tar -xvf file.tar //解压 tar tar.xz  
tar -xzvf file.tar.gz //解压tar.gz  
tar -xjvf file.tar.bz2   //解压 tar.bz2  
tar -xZvf file.tar.Z   //解压tar.Z

find / -name mysql 查找文件mysql

cd /apache-tomcat-9.0.13/bin  
./startup.sh  
./shutdown.sh   

service mysqld restart  

:q! 
vim放弃所作修改而直接退到shell下。 

:wq 
vim将先保存文件，然后退出Vi返回到shell。 