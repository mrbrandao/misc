#!/usr/loca/bin/python
# -*- coding: utf-8 -*-
#A little joke with time like a cronometer ;p

from time import sleep

bombm=1
bombs=59

while bombs != -1: #only for show the zero at end
	if bombs < 10:
		print "Vou explodir em "+"0"+str(bombm)+":"+"0"+str(bombs)
	
	else:
		print "Vou explodir em "+"0"+str(bombm)+":"+str(bombs)
	
	sleep(.10)#10ms
	bombs=bombs-1	
	if bombm == 1 and bombs == -1:
		bombm=0
		bombs=59
print "Boooommm"

