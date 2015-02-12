#!/bin/sh
DATA=`date +%F-%R`
NAMEBALL=wtserver-$DATA.tbz
TBIN=/bin/tar
WDEST=/media/bkp/winthor/$NAMEBALL
WSOURCE=/data/winthor/winthorsrv


#######
#Rotate
dest=/media/bkp/winthor
currentmes=`date +%m`
bkpmes=`ls -1 $dest|grep tbz|cut -d'-' -f 3`
rotmes=`expr $currentmes - 5`

echo $bkpmes > /tmp/bkpmes
for i in `cat /tmp/bkpmes|tr ' ' '\n'`
do
	a=`expr "$i" - 5`
	if [ "$a" -lt 0 ] 
	then
		echo $a menor que zero
		b=`expr "$a" + 12`
		ls $dest/wtserver-*-$b-*
	fi
done




#$TBIN -cvjf $WDEST $WSOURCE
