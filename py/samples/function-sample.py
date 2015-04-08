#!/usr/local/bin/python
# -*- coding: utf-8 -*-

#Exemplos de funcoes com python


#-----------------------
#Exemplo 1------
#------------------------

def lingua(lang):
    if lang == 'en':
        print 'Hello'
    elif lang == 'es':
        print 'Ola'
    elif lang == 'fr':
        print 'Bonjour'
    else:
        print 'E aí meu!?'
lingua('en')
lingua('es')
lingua('fr')
lingua('lalalal')


#-----------------------
#Exemplo 2------
#------------------------
def lingua2(lang):
    if lang == 'es':
        return 'Hello'
    elif lang == 'fr':
        return 'Bonjour'
    else:
        return 'E aí trolha? ....'

print lingua2('es'), 'Dolly'
print lingua2('fr'), 'Abajour'
print lingua2('lalalala'), 'saca a rolha'

#-----------------------
#Exemplo 3------
#------------------------

def calc(a,b):
    soma = a + b
    return soma

x = calc(5,5)
print x
