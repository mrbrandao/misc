#!/bin/bash
#set -x
#**********************************
#****  Ativar servidor de DNS  ****
#**********************************
killall -KILL named
/etc/rc.d/rc.bind start

#****************************************************
#****    Mata o processo atual e executa o novo  ****
#****************************************************
killall -KILL noip2


#**********************************
#****  atualiza o ip no no-ip  ****
#**********************************
/usr/local/bin/noip2

#**********************************************
#**** Atualiza no no-ip de 5 em 5 minujtos ****
#**********************************************
/usr/local/bin/noip2 -U 2

echo "1" > /proc/sys/net/ipv4/ip_forward
iptables -F
iptables -t nat -F
#************************
#**** bloqueia tudo  ****
#************************
iptables -P FORWARD DROP

#**********************************************
#**** Libera a porta 22 para acesso do SSH ****
#**********************************************
iptables -A INPUT -p tcp --dport 22 -j ACCEPT

#***************************************************************************************************
#***************************************  liberar ip    ********************************************
#**************************************************************************************************
#
#Marilda
iptables -t nat -A POSTROUTING -s 192.168.0.4 -j MASQUERADE
iptables -A FORWARD -s 192.168.0.4 -m mac --mac-source 00:d0:09:f2:b2:11 -j ACCEPT
iptables -A FORWARD -d 192.168.0.4 -j ACCEPT
#
#Andrea
iptables -t nat -A PREROUTING -s 192.168.0.3 -i eth1 -j DNAT --to 192.168.0.5
iptables -t nat -A POSTROUTING -s 192.168.0.5 -j MASQUERADE
iptables -A FORWARD -s 192.168.0.5 -m mac --mac-source 00:16:EC:1E:E4:2A -j ACCEPT
iptables -A FORWARD -d 192.168.0.5 -j ACCEPT


#Andrea
iptables -t nat -A POSTROUTING -s 192.168.0.100 -j MASQUERADE
iptables -A FORWARD -s 192.168.0.100 -m mac --mac-source 00:16:17:67:24:3B -j ACCEPT
iptables -A FORWARD -d 192.168.0.100 -j ACCEPT

#
#Alfredo2
iptables -A INPUT -i ppp0 -p tcp --dport 5800 -j ACCEPT
iptables -A INPUT -i ppp0 -p tcp --dport 5900 -j ACCEPT
iptables -t nat -A POSTROUTING -s 192.168.0.8 -j MASQUERADE
iptables -A FORWARD -s 192.168.0.8 -m mac --mac-source 00:0f:ea:ae:53:f6 -j ACCEPT
iptables -A FORWARD -d 192.168.0.8 -j ACCEPT
iptables -t nat -A PREROUTING -i ppp0 -p tcp --dport 5900 -j DNAT --to 192.168.0.8
iptables -t nat -A PREROUTING -i ppp0 -p tcp --dport 5800 -j DNAT --to 192.168.0.8
#
#Rubens
iptables -t nat -A POSTROUTING -s 192.168.0.6 -j MASQUERADE
iptables -A FORWARD -s 192.168.0.6 -m mac --mac-source 00:40:c7:2d:81:90 -j ACCEPT
iptables -A FORWARD -d 192.168.0.6 -j ACCEPT
#
#Wilson
iptables -t nat -A POSTROUTING -s 192.168.0.7 -j MASQUERADE
iptables -A FORWARD -s 192.168.0.7 -m mac --mac-source 00:02:44:2d:2a:f7 -j ACCEPT
iptables -A FORWARD -d 192.168.0.7 -j ACCEPT

#Mauricio
iptables -t nat -A POSTROUTING -s 192.168.0.9 -j MASQUERADE
iptables -A FORWARD -s 192.168.0.9 -m mac --mac-source 00:13:d3:1c:69:b6 -j ACCEPT
iptables -A FORWARD -d 192.168.0.0 -j ACCEPT




iptables -A INPUT -i lo -j ACCEPT
iptables -A INPUT -i eth2 -j ACCEPT
iptables -A FORWARD -i eth2 -o eth1 -j ACCEPT
iptables -A FORWARD -m state --state ESTABLISHED,RELATED -j ACCEPT
iptables -t nat -A POSTROUTING -o ppp0 -j MASQUERADE
#================================================//==========================================
#

#Controle de Banda
tc qdisc del dev eth1 root
tc qdisc add dev eth1 root handle 1: htb default 30
tc class add dev eth1 root classid 1:0 htb rate 300kbit
tc class add dev eth1 parent 1:0 classid 1:10 htb rate 300kbit ceil 300kbit
#tc class add dev eth1 parent 1:0 classid 1:20 htb rate 25kbit ceil 35kbit
tc class add dev eth1 parent 1:0 classid 1:30 htb rate 65kbit ceil 65kbit
tc filter add dev eth1 parent 1:0 protocol ip u32 match ip dst 192.168.0.0/24 flowid 1:10
tc filter add dev eth1 parent 1:0 protocol ip u32 match ip dst 192.168.0.8 flowid 1:30
tc filter add dev eth1 parent 1:0 protocol ip u32 match ip dst 192.168.0.9 flowid 1:30
