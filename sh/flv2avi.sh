#!/bin/bash
clear
echo -e "\033[1;34;40mO caminho Default que eu procuro é $HOME
Por favor... Certifique que o filme esteja nesse local antes de comecar\033[0m"
read -p "qual filme deseja converter???: " entrada
read -p "entre com o nome de saida do video: " saida
echo -e "\033[1;36;40m Epsere que eu estou convertendo... $entrada em $saida.avi\033[0m"
mencoder ~/$entrada -ofps 15 -vf scale=300:-2 -oac lavc -ovc lavc -lavcopts vcodec=msmpeg4v2:acodec=mp3:abitrate=64 -o ~/Desktop/$saida.avi 2> /dev/null 1>/dev/null
echo -e "\033[1;32;40mTerminei!!! : )\033[0m"
sleep 1
