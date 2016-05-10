#!/bin/sh
#By: isca -> igorsca at gmail dot com
#Curitiba 01/03/16
#
#This make a lot configuration for my profile on Linux
#
#This file use a lot if's to detect you distro, its very simple to add your distro here
#If your distro isnt here just add another if with your distro-release here
#$1 deve sempre ser o nome do array ex: alias
#$2 deve ser o $PATHRC
#$3 deve ser o $TMPRC
#$4 deve ser o RUN que sera o arquivo TMP duranto o array


##### global vars ####
SUDO=`which sudo`


#### Colors ####
white="\033[37;40m"
green="\033[32;40m"
red="\033[31;40m"
cian="\033[36;40m"
clean="\033[0m"


#Discover my distro

if [ -e /etc/arch-release ]
then
	#Bashrc
	DISTRORC="bash.bashrc"
	PATHRC="/etc/$DISTRORC" 
	#Temps during copies
	TMPRC="/tmp/$DISTRORC"
	TMPRCRUN="/tmp/bashrc-run"

	#vimrc
	VIMRC="vimrc"
	PATHVIM="/etc/$VIMRC"
	TMPVIM="/tmp/vimrc"
	TMPVIMRUN="/tmp/vimrc-run"
	
	#hosts
	DISTROHOSTS="hosts"
	PATHHOSTS="/etc/$DISTROHOSTS"
	#Temps during copies
	TMPHOSTS="/tmp/$DISTROHOSTS"
	TMPHOSTSRUN="/tmp/hosts-run"
	
	#profile
	DISTPROFILE="profile"
	PATHPROFILE="/etc/$DISTPROFILE"
	TMPPROF="/tmp/profile"
	TMPPROFRUN="/tmp/profile-run"
	
	#inputrc
	DISTINPUT="inputrc"
	PATHINPUT="/etc/$DISTINPUT"
	TMPINPUT="/tmp/inputrc"
	TMPINPUTRUN="/tmp/inputrc-run"

fi

