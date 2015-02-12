#!/usr/bin/python
import sys, getopt
#def main(argv):
#	bola=''
#	opts, args = getopt.getopt(argv, "v")
#	for opt, arg in opts:
#		if opt == '-v':
#			print "tem v"
#			bola = arg
#			print bola
#
bola=' '
carro=''
try:
	opts, args = getopt.getopt(sys.argv[1:], "v:i:")
	for opt, arg in opts:
		if opt == '-v':
			print "tem v"
			bola = arg
			print ("Agora bola : "+bola)
		elif opt in ('-i'):
			print "tem i"
			carro = arg
			print ("Agora carro = "+carro)
except getopt.GetoptError:
	print "Erro"

