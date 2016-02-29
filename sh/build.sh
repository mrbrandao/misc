#!/bin/sh
#By: isca -> igorsca(at)gmail.com
#Curitiba 13/02/14
#
#This make a lot configuration for my profile on Linux
#
##### global vars ####
SUDO=`which sudo`
#
aliases() {
#Improving command with my pref's aliases
echo "Irei pedir sua senha..."
echo '
#Aliass Fields
alias vi=\"vim\"
alias ls=\"ls -G\"
alias cp=\"cp -v\"
alias rm=\"rm -i\"
alias mv=\"mv -v\"
alias ll=\"ls -lhG\"
alias la=\"ls -aG\"
alias l=\"ls -lahFG\"
' >> $DISTRORC 
}
#Discover my distro


if [ -e /etc/arch-release ]
then
	sudo sh -c 'export DISTRORC="/etc/bash.bashrc && aliases"'
fi

exit 0
