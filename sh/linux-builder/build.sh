#!/bin/sh
#By: isca -> igorsca at gmail dot com
#Curitiba 01/03/16
#
#This make a lot configuration for my profile on Linux
#
#How to use applier.sh:
#Aliases devem ser passados com 4 parametros para a checagem
#$1 deve sempre ser o nome do array ex: alias
#$2 deve ser o $PATHRC
#$3 deve ser o $TMPRC
#$4 deve ser o RUN que sera o arquivo TMP duranto o array


##### global vars ####
SUDO=`which sudo`


#### Colors ####
white="\033[37;40m"
green="\033[32;40m"
red="\033[31;40m"
cian="\033[36;40m"
clean="\033[0m"

source ./distros.sh

aliases() {

aliases[0]="##Aliases Fields"
aliases[1]="alias vi=\"vim\""
aliases[2]="alias ls=\"ls --color\""
aliases[3]="alias cp=\"cp -v\""
aliases[4]="alias rm=\"rm -i\""
aliases[5]="alias mv=\"mv -v\""
aliases[6]="alias ll=\"ls -lhG\""
aliases[7]="alias la=\"ls -aG\""
aliases[8]="alias l=\"ls -lahFG\""

source ./applier.sh aliases $PATHRC $TMPRC $TMPRCRUN

}

myhosts() {

myhosts[0]="##Hosts Fields"
myhosts[1]="192.168.1.1		router"

source ./applier.sh myhosts $PATHHOSTS $TMPHOSTS $TMPHOSTSRUN

}

vimrc(){
#Theme Colors
vimconf[0]="\"Default Theme Syntax to vim"
vimconf[1]="syntax on"

source ./applier.sh vimconf $PATHVIM $TMPVIM $TMPVIMRUN

}

profile(){
#Profile configs
profconf[0]="#My Personal Profile Confs"
profconf[1]="set -o vi"

source ./applier.sh profconf $PATHPROFILE $TMPPROF $TMPPROFRUN

}

inputrc(){
#Inputrc entries
inputconf[0]="#My Personal input settings "
inputconf[1]="set editing-mode vi"
inputconf[2]="\$if mode=vi"
inputconf[3]="set keymap vi-command"
inputconf[4]="#These are for vi-command mode"
inputconf[5]="Control-l: clear-screen"
inputconf[6]="set keymap vi-insert"
inputconf[7]="#These are for vi-insert mode"
inputconf[8]="Control-l: clear-screen"
inputconf[9]="\$endif"

source ./applier.sh inputconf $PATHINPUT $TMPINPUT $TMPINPUTRUN

}
case "$1" in

all)

aliases
myhosts
vimrc
profile
inputrc

;;

alias)
aliases;

;;

*)
echo "Use all|alias"
;;


esac


exit 0
