#!/usr/local/bin/python
# -*- coding: utf-8 -*-


#----------------------
# Exemplo 1 ----
#-----------------------


#Fazendo um parsezinho na banana
fruta = 'banana'

for letras in fruta:
    print letras


#----------------------
# Exemplo 2 ----
#-----------------------
#Tornado uma string UpperCase
texto = "hello world"
grande = texto.upper()
print grande

#----------------------
# Exemplo 3 ----
#-----------------------
#visualizando tratamentos em uma string ou varial com o 'dir'
funcoes = dir(texto)
print funcoes



#----------------------
# Execricio 1 ----
#-----------------------
#6.5 Write code using find() and string slicing (see section 6.10) to extract the number 
#at the end of the line below. Convert the extracted value to a floating 
#point number and print it out.
text = "X-DSPAM-Confidence:    0.8475"
num = text.find('0')
num = float(text[num:28])
print num
