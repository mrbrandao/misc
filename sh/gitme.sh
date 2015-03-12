#!/bin/sh
#by: isca
#Curitiba/PR - 16/02/2014
#
#Acerta os submodulos com update
# Faz pull em todo mundo
# Joga todo mundo para branch master
#
#Quando se usa submodules com git o git seta o branch sempre pelo ultimo commit. Entao quando voce modifica algo em um submodule voce precisa sempre criar um novo commit no repositorio principal (superepository), para que as alteracoes em submodules sejam aplicadas.
#Ex: cd [submodule dir]
#git checkout master
#git pull
#cd ..
#git add [submodule diretory]
#git commit -m "movido submodule para o ultimo commit"
#git push
#
#Entao Como usar usar este script?
#Assim:
#gitme update
#gitme master
#gitme pull

case "$1" in
pull)
#git pull
git pull --recurse-submodules
;;
pall)
#use for recursive pull
git submodule foreach --recursive git pull
;;
porg)
#use for origin master recursive pull
git submodule foreach --recursive git pull origin master
;;
update)
git submodule update
git submodule update --recursive --remote
git submodule update --recursive
;;
master)
git submodule foreach --recursive git checkout master
;;
all)
$0 update
$0 master
$0 pull
;;
*)
echo "Use: all/pull/update/master/pall/porg"
;;

esac
