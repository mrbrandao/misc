#!/bin/bash
#Por : Igor Brandao
#e-mail : igorsca(at)gmail.com
#boxstart.sh é um script de inicializacao para iniciar varios itens no fluxbox
#conforme for achando interessante, acresente coisas à seu gosto aqui...
#Divirta-se
#
#Icones na Área de Trabalho
#idesk&

#Levantar adesklets
adeskltes -k >/dev/null
adesklets&
#Levantar Gdesklets
#gdesklets&

#Setar Papel de Parede
fbsetbg /home/igor/docs/paper/cachoeira.jpg
#fbsetbg /home/igor/.fluxbox/backgrounds/sid_fluxbox.jpg

#Xscreensaver em segundo plano
#xscreensaver -nosplash&


#Workspace pager
killall -KILL fbpager 2>/dev/null
fbpager&
#killall -KILL fluxter 2>/dev/null
#fluxter -w&
#Suporte apm
killall -KILL asapm 2>/dev/null
#killall -KILL wmpower 2>/dev/null
asapm -green blue -status green -withdrawn -lower purple -upper blue&
#wmpower

#Wireless Monitor
#killall -KILL wmwave
#wmwave&
#killall -KILL wmwifi
#wmwifi -tn 1>/dev/null 2>/dev/null
