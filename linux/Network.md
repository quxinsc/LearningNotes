## /etc/sysconfig/network-scripts/ifcfg-ens33
## /etc/netplan/02-bond-config.yaml
## /etc/network/interfaces
>手动修改了interfaces 文件，那NetworkManager就自动停止对系统网络的管理，系统改使用interfaces 文件内的参数进行网络配
```js
# interfaces(5) file used by ifup(8) and ifdown(8)
auto ens33
iface ens33 inet static
address 192.168.245.129
netmask 255.255.255.0
gateway 192.168.245.2
dns-nameserver 114.114.114.11
```
## 启用NetworkManager
```js
修改 /etc/NetworkManager/NetworkManager.conf
service network-manager start
```
## /etc/resolv.conf 
```js
nameserver 114.114.114.114
表示解析域名时用该地址指定的主机为域名服务器
其中域名服务器是按照文件中出现的顺序来查询的
且只有当第一个nameserver没有反应时才查询下面的nameserver
```
## 查看网口状态
```
for i in $( ls /sys/class/net ); do echo -n $i: ; cat /sys/class/net/$i/carrier; done
```
1.在不影响业务的前提下，及时隔离主机/容器，避免部分带有蠕虫功能的挖矿木马进一步在内网进行横向移动；
2.使用`top -c`命令查看系统性能，找出消耗CPU较高的进程PID（部分挖矿木马可能会篡改top命令实现进程隐藏，可以使用`which top | xargs stat`命令判断top文件是否被黑客篡改）；
3.根据获取的进程PID，使用“ps -ef -p PID”命令找出进程的详细信息；
4.根据进程详细信息定位到文件位置，并对该文件进行分析，确认是否属于挖矿木马；
5.若确认为挖矿木马，则进行如下清理操作：
（1）结束挖矿相关进程：kill 9 PID
（2）删除挖矿相关文件：rm -rf 异常文件，删除文件时可以使用find / -name 异常文件查找出系统中的所有恶意文件
（3）查看并清理异常定时任务：
	crontab -e
	crontab -u username -l
	cat /etc/crontab
        cat /var/spool/cron
        cat /etc/anacrontab
        cat /etc/cron.d/ 
        cat /etc/cron.daily/ 
        cat /etc/cron.hourly/ 
        cat /etc/cron.weekly/ 
        cat /etc/cron.monthly/ 
        cat /var/spool/cron/
（4）查看密钥认证文件
	删除木马创建的密钥认证文件，如果当前系统之前并未配置过密钥认证，可以直接清空认证存放目录：rm -rf /root/.ssh/*。如果有配置过密钥认证，只需要删除黑客创建的认证文件即可
6.对系统进行风险排查和安全加固，详情可参考如下链接：
【Linux】https://cloud.tencent.com/document/product/296/9604
【Windows】https://cloud.tencent.com/document/product/296/9605