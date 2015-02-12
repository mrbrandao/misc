#!/bin/bash
#Vena sobe um servidor VNC usando o x11vnc.
#Apenas um exemplo que pode ser um daemon para vnc em seu home
#by: isca0
#Curitiba 03/06/2007

vena="/usr/bin/x11vnc"
pass="arquivo.txt"
"$vena" --norc --passwdfile "$pass" --forever& >> /dev/null
exit 0
