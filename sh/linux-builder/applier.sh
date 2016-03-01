#!/bin/sh
#By: isca -> igorsca at gmail dot com
#Curitiba 01/03/16
#
#This is the applier scipt just to make array running
#
##### global vars ####
SUDO=`which sudo`


#### Colors ####
white="\033[37;40m"
green="\033[32;40m"
red="\033[31;40m"
cian="\033[36;40m"
clean="\033[0m"

#Aliases devem ser passados com 4 parametros para a checagem
#$1 deve sempre ser o nome do array ex: alias
#$2 deve ser o arquivo de origem
#$3 deve ser o o arquivo temporario sendo modificado
#$4 deve ser o RUN que sera o arquivo TMP durante o array

arg=$1[@]
name=("${!arg}")

#Begin Functions
limpa(){
#Esta funcao percorre o array $1 removendo os dados do arquivo
	cp -f "$2" "$3"
	for i in "${name[@]}" 
	do
		grep -v "$i" "$3" > "$4"
		mv "$4" "$3"
	done
	mv -b "$3" "$2"
}
grava(){
#Esta funcao percorre o array passando em $1 gravando os novos dados encontrados
#Copy /etc/bashrc to /tmp/bashrc
	cp -f "$2" "$3" 

	#percorre o array de nome recebido em $1
	for i in "${name[@]}"
	do
		echo "Gravando $i"	
		echo "$i" >> "$3"
	done
	mv -vb "$3" "$2"
}

#Improving command with my pref's aliases
if  grep -e "${name[0]}" "$2" >>/dev/null
then
	echo "Ja existem entradas em "$2""
	read -p "Voce deseja substituilos? (s/N) : " resprc
	if [ $resprc == S -o $resprc == s ] 
	then
		limpa
	else
		echo ""$1" nao serao aplicados!"
		exit 0
	fi
		
fi
for i in "${name[@]}"
do
	echo "Gravando $i"	
	echo "$i" >> "$3"
done
mv -vb "$3" "$2"
exit 0
