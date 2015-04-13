#!/bin/sh
#This is my sample use for inadyn with multiple hosts on same machine

noips="default@no-ip.com"
noipl="mynoiplogin@email.com"
noiph="mynoippassword"
alias1="myalias1.noip.com"
alias2="myalias2.ddns.net"
alias3="myalias3.sytes.net"
logfile="/var/log/inadyn.log"

inadyn --dyndns_system $noips -u $noipl -p $noiph -a $alias1 -a $alias2 -a $alias3 -d 7 --verbose 5 --background --log_file $logfile
