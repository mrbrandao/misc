#!/usr/bin/python
#sum.py

import sys
import keyword

numbers = [22, 34, 12, 32, 4]
sum = 0

i = len(numbers)

while (i != 0):
	i -= 1
	sum = sum + numbers[i]
print "A soma e: ", sum
