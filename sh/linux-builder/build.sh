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

alias[0]="##Aliases Fields"
alias[1]="alias vi=\"vim\""
alias[2]="alias ls=\"ls --color\""
alias[3]="alias cp=\"cp -v\""
alias[4]="alias rm=\"rm -i\""
alias[5]="alias mv=\"mv -v\""
alias[6]="alias ll=\"ls -lhG\""
alias[7]="alias la=\"ls -aG\""
alias[8]="alias l=\"ls -lahFG\""

source ./applier.sh alias $PATHRC $TMPRC $TMPRCRUN

}

#vimrc(){
#Theme Colors
#vimconf[0]=""Default Theme Syntax to vim"
#vimconf[1]="syntax on"
#}

aliases

exit 0
