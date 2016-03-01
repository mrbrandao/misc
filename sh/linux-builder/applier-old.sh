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
clear="\033[0m"

#Aliases devem ser passados com 4 parametros para a checagem
#$1 deve sempre ser o nome do array ex: alias
#$2 deve ser o $PATHRC
#$3 deve ser o $TMPRC
#$4 deve ser o RUN que sera o arquivo TMP duranto o array

#This is my first sample demo withou arguments just for tests
#Improving command with my pref's aliases
if  grep -e "${alias[0]}" "$PATHRC" >>/dev/null
then
	echo "Ja existem entradas em $PATHRC"
	read -p "Voce deseja substituilos? (s/N) : " resprc
	if [ $resprc == S -o $resprc == s ] 
	then
		cp -f "$PATHRC" "$TMPRC"
		for ((i = 0; i < ${#alias[@]}; i++))
		do
			grep -v "${alias[$i]}" $TMPRC > $TMPRC-RUN
			mv $TMPRC-RUN $TMPRC
		done
			mv -b $TMPRC $PATHRC
	else
		echo "Aliases nao serao aplicados!"
		continue
	fi
			
		
else
	cp -f "$PATHRC" "$TMPRC"
	for ((i = 0; i < ${#alias[@]}; i++))
	do
		echo "Gravando ${alias[$i]}"	
		echo "${alias[$i]}" >> "$TMPRC"
	done
	mv -vb "$TMPRC" "$PATHRC"
fi


exit 0
