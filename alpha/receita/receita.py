#!/usr/bin/env python
#-*- coding: utf-8 -*-
#
#By: isca zero - igorsca at gmail dot com
#Curitiba - 28-06-15
#
#How works:
# This script is intercaled with an web php form that make a txt's files where this program
# expected to download that files and make a little changes on this files before call a shellscript
# to handle it txt's files to the next step.
#
#Short steps:
# - This script make a conection on ftp
# - List all files on ftp and grep only the txt's files on a "arquivo" var
# - Once it found the files, it make a download of this files to the current directory
# - The txt's files are expected as 10 numbers with quotation marks separation and one phrase
# - When all the files are in local directory it make a linebreak at the last quotation mark
# - and brake the files in two lines, one line with numbers and one line with the phrase
# - at last it renames the original files to the modificate files and call a shellscript to handle with this files


import os
import ftplib

ftp = ftplib.FTP("myftp.com.br")
ftp.login("mylogin@mydomain.com", "#mypassword")
ftp.cwd('path/to_the_txt_files')

arquivos = []
try:
	arquivos = ftp.nlst()
except ftplib.error_perm:
	print "Ops... nao consegui listar"

for arquivo in arquivos:
	if arquivo.endswith(".txt"):
		print "Encontrei estes arquivos:", arquivo
		with open(arquivo, "wb") as file: 
			print "Baixando..."
			ftp.retrbinary('RETR %s' % arquivo, file.write)
			ftp.delete(arquivo) #removendo os q ja foram baixados



for localfiles in os.listdir("./"):
 	if localfiles.endswith(".txt"):
 		#conta quantidade de linhas dos txt's
 		num_lines = sum(1 for line in open(localfiles))
 		if num_lines > 1:
 			print localfiles,"ja foi mexido"
 			continue
 		origem=localfiles
 		destino=localfiles+".tmp"
 		f = open(origem, 'r')
 		f2 = open(destino, 'w')
 		line = f.readline()
 		s = line.rsplit(',',1)
 		line1 = s[0]
 		line2 = s[1]
 		f2.write(line1+'\n')
 		f2.write(line2+'\n')
 		f.close()
 		f2.close()

 		#renomeando... 
 		os.rename(destino, origem)
 		#para rodar so modificados
 		#os.system("./preload.sh %s" % (origem))
		#rodando o shell
		for localfiles in os.listdir("./"):
 			if localfiles.endswith(".txt"):
				os.system("./preload.sh %s" % (localfiles))
	

