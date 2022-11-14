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
