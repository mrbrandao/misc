#!/usr/local/bin/python
# -*- coding: utf-8 -*-
#Sample how to get hackerspace status with python

import urllib

status = urllib.urlopen('http://garagemhacker.org/status.txt').read().rstrip()
fcomp = 'new3'


try:
	print 'Arquivo ja existe vou usar leitura direto'
	f = open(fcomp, 'r')
except:
	print 'Arquivo nao existe vou crialo'
	f = open(fcomp, 'a')
	f.write(status)
	f = open(fcomp, 'r')

if f.read() == status:
	print 'A garagem esta', status
	print 'nao farei nada'
	f.close()
else:
	print 'A garagem agora esta', status
	f = open(fcomp, 'w')
	f.write(status)
	f = open(fcomp, 'r')
	print 'Gravei novo estado'
	f.close()



