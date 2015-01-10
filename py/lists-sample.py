#!/usr/local/bin/python
# -*- coding: utf-8 -*-


#----------------------
# Execricio 1 ----
#-----------------------
#8.4 Open the file romeo.txt and read it line by line. For each line, split the line into a list of
#words using the split() function. The program should build a list of words. For each word
#on each line check to see if the word is already in the list and if not append it to the list.
#When the program completes, sort and print the resulting words in alphabetical order.
#You can download the sample data at http://www.pythonlearn.com/code/romeo.txt

words=[]
file = open('romeo.txt')
for line in file:
    line = line.rstrip() #clean the space on end of the each line
    spl = line.split() #split the line like ['Word', 'Words'. 'etc...']
    for i in spl:
        if i not in words:  # this also can be if not i in words: 
            words.append(i)
words.sort()
print words

#----------------------
# Execricio 2 ----
#-----------------------
#8.5 Open the file mbox-short.txt and read it line by line.
#When you find a line that starts with 'From ' like the following line:
#From stephen.marquard@uct.ac.za Sat Jan  5 09:14:16 2008
#You will parse the From line using split() and print out the second word in the 
#line (i.e. the entire address of the person who sent the message). Then print out a count at the end.
#Hint: make sure not to include the lines that start with 'From:'.
#You can download the sample data at http://www.pythonlearn.com/code/mbox-short.txt
count = 0
file = open('mbox-short.txt')
for lines in file:
    lines = lines.rstrip()
    if not lines.startswith('From'): continue
    if lines.startswith('From:'): continue
    spl = lines.split()
    print spl[1]
    count = count + 1
print count

