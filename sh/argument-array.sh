#!/bin/bash
#Este shell server de exemplo de como percorrer um array usando como $1
#como argumento de nome do array
#ex: ./script teste
#passando o paramentro teste para este script ele ira retorar os valores do array teste


teste[0]="teste0"
teste[1]="teste1"

chuva=('gota' 'gota2' 'gota3')

arg=$1[@]
name=("${!arg}")

echo "Seu argumento foi $1"
echo "Vou percorrer o array $1"
for i in "${name[@]}"
do
	echo $i
done

echo "ehhh agora vou lhe mostrar so a primeira posicao do array $1 --> ${name[0]}"

