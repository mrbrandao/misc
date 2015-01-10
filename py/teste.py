#!/usr/bin/python
import sys
import getopt
def main(argv):
    teste=' '
    opts, args = getopt.getopt(argv, "m")
    for opt, arg in opts:
        if opt == '-m':
            print "mostrando" +arg
