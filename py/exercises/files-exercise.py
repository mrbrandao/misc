#!/usr/local/bin/python
# -*- coding: utf-8 -*-

#----------------------
# Execricio 1 ----
#-----------------------

#7.1 Write a program that prompts for a file name, then opens that file and reads through
#the file, and print the contents of the file in upper case. Use the file words.txt to produce
# the output below.
#You can download the sample data at http://www.pythonlearn.com/code/words.txt

ask = raw_input('File name: ')


try:
   handle = open(ask)
    
except:
    print 'Ops...',ask,' not exist or wrong path...'
    exit()  

for line in handle:
        cutnewline = line.rstrip()
        great = cutnewline.upper()
        print great


#----------------------
# Execricio 2 ----
#-----------------------
#7.2 Write a program that prompts for a file name, then opens that file and reads through 
#the file, looking for lines of the form:
#X-DSPAM-Confidence:    0.8475
#Count these lines and extract the floating point values from each of the lines and compute
#the average of those values and produce an output as shown below.
#You can download the sample data at http://www.pythonlearn.com/code/mbox-short.txt when you
#are testing below enter mbox-short.txt as the file name.

fname = raw_input('Enter the file name: ')

try:
    han = open(fname)
except:
    print "Ops... ",fname," not found"
    exit()

total = 0.0
count = 0
for line in han:
    if not line.startswith('X-DSPAM-Confidence:'): continue
    line = line[20:].rstrip()
    line = float(line)
    total = line + total
    count = count + 1
print 'Average spam confidence:', total / count
