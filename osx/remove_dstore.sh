#!/bin/sh
#By: isca 
#Curitiba - 13/02/14
#
# Find on the entered PATH the .DS_Store files for remove
#
green="\033[32m"
red="\033[31m"
limpa="\033[0m"
if [ "$#" -ne 1 ]
then
	echo "$red Ops... Voce deve especificar um caminho para a busca$limpa
Exemplo:
	$0 ~
	$0 /var
"

	exit 1
fi

#Old not interative verbose way
#find "$1" -name ".DS_Store" -delete 
echo "$red Removendo arquivos...$limpa"
find "$1" -name ".DS_Store" -exec rm -rvf {} \;
echo "$green Arquivos .DS_Store foram limpos de $1 com sucesso!$limpa"
