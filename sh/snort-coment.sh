#!/bin/bash
#Comenta as linhas do snort.conf que apontam para arquivos de regras no diretório rules/ que não existem.

ARQ_CONF="/etc/snort/snort.conf"
RULES_DIR="/etc/snort/rules"
ARQ_LISTA1="lista_de_includes_pura"
ARQ_LISTA2="lista_de_includes_gerada"
TEMPORARIO="snort.conf-temporario"

cat $ARQ_CONF | grep "include \$RULE_PATH" | awk -F'/' '{print $2}' > $ARQ_LISTA1
for i in $(cat $ARQ_LISTA1 )
do
if [ -e $RULES_DIR/$i ]
then
echo "include \$RULE_PATH/$i" >> $ARQ_LISTA2
else
echo "#include \$RULE_PATH/$i" >> $ARQ_LISTA2
fi
done
cat $ARQ_CONF | grep -v "include \$RULE_PATH" > $TEMPORARIO
cat $TEMPORARIO > $ARQ_CONF
echo '' >> $ARQ_CONF
cat $ARQ_LISTA2 >> $ARQ_CONF

rm $ARQ_LISTA1 $ARQ_LISTA2 $TEMPORARIO
