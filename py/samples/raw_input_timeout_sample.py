#!/usr/local/bin/python
# -*- coding: utf-8 -*-

import sys, select

print "You have ten seconds to answer!"

i, o, e = select.select( [sys.stdin], [], [], 10 )

if (i):
  if sys.stdin.readline().strip() == "KILL":
  	print "Quitting"
  	exit()
else:
  print "You said nothing!"
