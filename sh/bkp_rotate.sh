#!/bin/sh
#Script de Backup com Rotate de meses
#Este script se propem a fazer o backup e apagar os bkp's que tem
# mais de 5 meses. Ou seja se o mes atual for 6 o bkp do mes 1 sera apagado.
#Para mudar o rotate de meses mude a variavel mes. Assim voce podera fazer rotate
#da quantidade que quiser em meses.

data=`date +%F-%R`
name=wtserver-$data.tbz
dest=wt
mes=5
#-------------
#Definindo mes corrente

currentmes=`date +%m`

#loop de uma volta para encontar o mesXvezes menor ao mes atual
for i in 1
do
	a=`expr "$currentmes" - "$mes"`
	if [ "$a" -le 0 ]
	then
		b=`expr "$a" + 12`
		if [ "$b" -lt 10 ]
		then
			echo "Meses menores que 10"
			ls -1 $dest/*-0"$b"-*
			rm $dest/*-0"$b"-*
		else
			echo "Outros meses"
			ls -1 $dest/*-"$b"-*  
			rm $dest/*-"$b"-*
		fi
	
	else

		echo "Reducao normal"
		ls -1 $dest/*-0"$a"-*
		rm $dest/*-0"$a"-*
	fi
done
