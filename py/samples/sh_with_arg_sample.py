#!/bin/env python
#little sample running calling sheelscript passing $1 as files
#
#this preload.sh is:
#cat $1
#


import os

#listing all files on current directory
for files in os.listdir("./"):
	#searching txt files only
	if files.endswith(".txt"):
		print files
		#running shellscript with matched files instead of $1
		os.system("./preload.sh %s" % (files))