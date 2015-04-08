#!/usr/local/bin/python
# -*- coding: utf-8 -*-

#5.2 Write a program that repeatedly prompts a user for integer numbers 
#until the user enters 'done'. Once 'done' is entered, 
#print out the largest and smallest of the numbers. If the user enters anything other than a valid number 
#catch it with a try/except and put out an appropriate message and ignore the number. 
#Enter the numbers from the book for problem 5.1 and Match the desired output as shown.
max = None
min = None
num = None
while True:
    inp = raw_input('Write a number:>')
    if inp == 'done':
        break
    elif len(inp) < 1 : #Testa se comprimento for menos que 1 (Linha em branco)
        print 'Ops you just entre a Blank Line'
        continue
    
    try: 
        num = int(inp)
    except:
        print 'Invalid input'
        continue
        

    if max is None and min is None:
        max = num
        min = num
        
    if num > max:
        max = num
    elif num < min:
        min = num
        
print 'Maximum is',max
print 'Minimum is',min
